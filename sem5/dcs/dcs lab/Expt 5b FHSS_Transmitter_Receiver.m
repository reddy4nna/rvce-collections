clear; clc; close all;

%% ---------------------- 1. System Parameters ---------------------------
Nb          = 20;           % Number of data bits
Rb          = 1e3;          % Bit rate (bps)
Tb          = 1/Rb;         % Bit duration (s)
bitsPerHop  = 2;             % Slow FH: multiple bits transmitted per hop
Nhops       = ceil(Nb/bitsPerHop);
Th          = bitsPerHop*Tb;      % Hop duration (s)

f0 = 2e3;  f1 = 4e3;          % Baseband BFSK tone frequencies for bit 0/1
M          = 7;                % Hop-set size = LFSR period (2^3 - 1 = 7); see REVISION NOTES
hopSpacing = 10e3;             % Channel spacing (Hz)
fHopSet    = (1:M)*hopSpacing;  % Available hop-carrier frequencies

fs      = 200e3;              % Sampling frequency
EbN0dB  = 3;                  % Eb/N0 (dB) for the single-run demo (chosen so
                                % the demo actually shows occasional errors
                                % with only Nb=20 bits - see Section 9)

%% ---------------------- 2. Generate Random Data Bits --------------------
data = randi([0 1], 1, Nb);

%% ---------------------- 3. BFSK Baseband Modulation ----------------------
t_bit = 0:1/fs:Tb-1/fs;
samplesPerBit = length(t_bit);
bfskSignal = zeros(1, Nb*samplesPerBit);
for i = 1:Nb
    idxStart = (i-1)*samplesPerBit + 1;
    idxEnd   = i*samplesPerBit;
    if data(i) == 0
        bfskSignal(idxStart:idxEnd) = cos(2*pi*f0*t_bit);
    else
        bfskSignal(idxStart:idxEnd) = cos(2*pi*f1*t_bit);
    end
end
t = (0:length(bfskSignal)-1)/fs;

%% ---------------------- 4. Generate Pseudo-random Hop Pattern -------------
% 3-stage LFSR, generator polynomial x^3 + x + 1 -> period 7 (hand-verified
% to revisit every non-zero 3-bit state exactly once before returning to
% the seed), mapped mod M (=7) to an index into the hop-frequency set.
lfsr       = [1 0 1];         % Non-zero seed
hopPattern = zeros(1, Nhops);
for h = 1:Nhops
    idx           = mod( lfsr(1)*4 + lfsr(2)*2 + lfsr(3), M ) + 1;
    hopPattern(h) = idx;
    fb   = xor(lfsr(1), lfsr(3));   % feedback taps for x^3+x+1
    lfsr = [fb, lfsr(1:end-1)];
end

%% ---------------------- 5. Frequency Hopping (Transmitter) ----------------
samplesPerHop = bitsPerHop*samplesPerBit;
txSignal      = zeros(1, length(bfskSignal));
for h = 1:Nhops
    idxStart = (h-1)*samplesPerHop + 1;
    idxEnd   = min(h*samplesPerHop, length(bfskSignal));
    tSeg     = t(idxStart:idxEnd);
    hopCarrier = cos(2*pi*fHopSet(hopPattern(h))*tSeg);
    txSignal(idxStart:idxEnd) = bfskSignal(idxStart:idxEnd) .* hopCarrier;
end

%% ---------------------- 6. AWGN Channel -------------------------------------
% Eb is measured from the ACTUAL transmitted (post-hop) waveform, not the
% pre-hop tone - see REVISION NOTES above for why this matters.
Eb       = mean(txSignal.^2) * Tb;    % Energy/bit of the signal actually on the channel
EbN0Lin  = 10^(EbN0dB/10);
N0       = Eb/EbN0Lin;
noiseVar = N0*fs/2;
rxSignal = txSignal + sqrt(noiseVar)*randn(size(txSignal));

%% ---------------------- 7. Receiver: Dehopping -------------------------------

dehopped = zeros(1, length(rxSignal));
for h = 1:Nhops
    idxStart = (h-1)*samplesPerHop + 1;
    idxEnd   = min(h*samplesPerHop, length(rxSignal));
    tSeg     = t(idxStart:idxEnd);
    hopCarrier = cos(2*pi*fHopSet(hopPattern(h))*tSeg);   % same sequence as TX
    dehopped(idxStart:idxEnd) = rxSignal(idxStart:idxEnd) .* hopCarrier;
end

%% ---------------------- 8. BFSK Demodulation (Correlation Detector) ---------
rxBits = zeros(1, Nb);
for i = 1:Nb
    idxStart = (i-1)*samplesPerBit + 1;
    idxEnd   = i*samplesPerBit;
    seg  = dehopped(idxStart:idxEnd);
    corr0 = sum(seg .* cos(2*pi*f0*t_bit));
    corr1 = sum(seg .* cos(2*pi*f1*t_bit));
    rxBits(i) = corr1 > corr0;
end

%% ---------------------- 9. Results (illustrative single run) -----------------
numErrors = sum(rxBits ~= data);
BER       = numErrors/Nb;
theoreticalBER = qfunc(sqrt(EbN0Lin));     % coherent orthogonal BFSK reference
expectedErrors = theoreticalBER*Nb;
fprintf('===== FHSS System Results (Eb/N0 = %d dB, %d bits) =====\n', EbN0dB, Nb);
fprintf('Transmitted bits      : %s\n', num2str(data));
fprintf('Hop pattern (indices) : %s\n', num2str(hopPattern));
fprintf('Received bits         : %s\n', num2str(rxBits));
fprintf('Number of errors      : %d\n', numErrors);
fprintf('BER (this run)        : %.4f\n', BER);
fprintf('Theoretical BER at this Eb/N0     : %.5f\n', theoreticalBER);
fprintf('Expected errors in %d bits        : %.3f\n', Nb, expectedErrors);
fprintf('NOTE: with only %d bits, getting 0 errors is NORMAL whenever\n', Nb);
fprintf('      expectedErrors is well below 1 (try lowering EbN0dB to\n');
fprintf('      reliably see errors in a single run).\n');
fprintf('      See Section 12 for the statistically meaningful BER curve.\n\n');

%% ---------------------- 10. Time-domain / Hop-pattern Plots -------------------
figure('Name','FHSS Signals');
subplot(3,1,1);
stairs([data data(end)], 'LineWidth', 1.5); ylim([-0.5 1.5]);
title('Original Data Bits'); grid on;

subplot(3,1,2);
stairs(1:Nhops, fHopSet(hopPattern)/1e3, 'LineWidth', 1.5);
xlabel('Hop Index'); ylabel('Frequency (kHz)');
title('Pseudo-random Frequency Hopping Pattern'); grid on;

subplot(3,1,3);
plotLen = min(5000, length(txSignal));   % defensive: never exceed signal length
plot(t(1:plotLen), txSignal(1:plotLen));
title('FHSS Transmitted Signal (zoomed in)'); xlabel('Time (s)'); grid on;

%% ---------------------- 11. Spectrogram (hops visible over time) --------------
figure('Name','FHSS Spectrogram');
spectrogram(txSignal, hamming(512), 256, 1024, fs, 'yaxis');
title('Spectrogram of FHSS Transmitted Signal (frequency hopping visible)');

%% ---------------------- 12. BER vs Eb/N0 --------------------------------------

NbitsTest    = 3000;                    % Large bit count for a stable BER estimate
EbN0dB_range = 0:2:14;
BER_sim      = zeros(size(EbN0dB_range));

% --- Build a longer test hop pattern (LFSR continues cycling as needed) ---
NhopsTest = ceil(NbitsTest/bitsPerHop);
lfsrT = [1 0 1];
hopPatternTest = zeros(1, NhopsTest);
for h = 1:NhopsTest
    idx = mod( lfsrT(1)*4 + lfsrT(2)*2 + lfsrT(3), M ) + 1;
    hopPatternTest(h) = idx;
    fbT   = xor(lfsrT(1), lfsrT(3));
    lfsrT = [fbT, lfsrT(1:end-1)];
end

for k = 1:length(EbN0dB_range)
    % Fresh random data for every Eb/N0 point
    dataTest = randi([0 1], 1, NbitsTest);
    bfskTest = zeros(1, NbitsTest*samplesPerBit);
    for i = 1:NbitsTest
        idxStart = (i-1)*samplesPerBit + 1;
        idxEnd   = i*samplesPerBit;
        if dataTest(i) == 0
            bfskTest(idxStart:idxEnd) = cos(2*pi*f0*t_bit);
        else
            bfskTest(idxStart:idxEnd) = cos(2*pi*f1*t_bit);
        end
    end
    tTest = (0:length(bfskTest)-1)/fs;

    txTest = zeros(1, length(bfskTest));
    for h = 1:NhopsTest
        idxStart = (h-1)*samplesPerHop + 1;
        idxEnd   = min(h*samplesPerHop, length(bfskTest));
        tSeg     = tTest(idxStart:idxEnd);
        hopCarrier = cos(2*pi*fHopSet(hopPatternTest(h))*tSeg);
        txTest(idxStart:idxEnd) = bfskTest(idxStart:idxEnd) .* hopCarrier;
    end

    Eb_k      = mean(txTest.^2) * Tb;         % Actual per-bit energy of this waveform
    EbN0Lin_k = 10^(EbN0dB_range(k)/10);
    N0_k      = Eb_k/EbN0Lin_k;
    noiseVar_k = N0_k*fs/2;
    rx = txTest + sqrt(noiseVar_k)*randn(size(txTest));

    dehop = zeros(1, length(rx));
    for h = 1:NhopsTest
        idxStart = (h-1)*samplesPerHop + 1;
        idxEnd   = min(h*samplesPerHop, length(rx));
        tSeg     = tTest(idxStart:idxEnd);
        hopCarrier = cos(2*pi*fHopSet(hopPatternTest(h))*tSeg);
        dehop(idxStart:idxEnd) = rx(idxStart:idxEnd) .* hopCarrier;
    end
    % No LPF here either - see NOTE ON FILTERING in Section 7. The
    % correlator below rejects the sum-frequency term by construction.

    rxB = zeros(1, NbitsTest);
    for i = 1:NbitsTest
        idxStart = (i-1)*samplesPerBit + 1;
        idxEnd   = i*samplesPerBit;
        seg  = dehop(idxStart:idxEnd);
        c0 = sum(seg .* cos(2*pi*f0*t_bit));
        c1 = sum(seg .* cos(2*pi*f1*t_bit));
        rxB(i) = c1 > c0;
    end
    BER_sim(k) = sum(rxB ~= dataTest)/NbitsTest;
end

BER_theory = qfunc(sqrt(10.^(EbN0dB_range/10)));   % Coherent orthogonal BFSK

figure('Name','FHSS BER Performance');
semilogy(EbN0dB_range, BER_sim + 1e-6, '-o', 'LineWidth', 1.5); hold on;
semilogy(EbN0dB_range, BER_theory, '--r', 'LineWidth', 1.5);
xlabel('E_b/N_0 (dB)'); ylabel('Bit Error Rate');
legend('Simulated FHSS (dehopped BFSK)', 'Theoretical Coherent Orthogonal BFSK');
title('BER Performance of the FHSS System');
grid on;