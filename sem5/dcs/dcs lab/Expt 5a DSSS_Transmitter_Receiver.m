clear; clc; close all;

%% ---------------------- 1. System Parameters ---------------------------
Nb      = 20;           % Number of information bits to transmit
Rb      = 1e3;          % Bit rate (bits/sec)
Tb      = 1/Rb;         % Bit duration (sec)
PG      = 15;            % Processing Gain = chips per bit (spreading factor)
Rc      = PG*Rb;         % Chip rate (chips/sec)
Tc      = 1/Rc;          % Chip duration (sec)
fs      = 20*Rc;         % Sampling frequency (oversampling the chip rate)
fc      = 5*Rc;          % Carrier frequency for BPSK modulation
EbN0dB  = 0;              % Eb/N0 (dB) used for the single-run passband demo
                            % (chosen so the demo actually shows occasional
                            % errors with only Nb=20 bits - see Section 9)

t_chip       = 0:1/fs:Tc-1/fs;
sampPerChip  = length(t_chip);

%% ---------------------- 2. Generate Random Data Bits --------------------
data          = randi([0 1], 1, Nb);   % Information bits {0,1}
dataBipolar   = 2*data - 1;            % NRZ bipolar mapping (+1/-1)

%% ---------------------- 3. Generate PN Spreading Code -------------------
% 4-stage LFSR, generator polynomial x^4 + x + 1 (a primitive polynomial)
% -> maximal length = 2^4 - 1 = 15 chips (hand-verified to return to the
% seed state after exactly 15 shifts, confirming full-period operation).
lfsr   = [1 0 0 1];             % Non-zero initial seed
pnCode = zeros(1, PG);
for i = 1:PG
    pnCode(i) = lfsr(end);
    fb   = xor(lfsr(1), lfsr(4));   % feedback taps for x^4+x+1
    lfsr = [fb, lfsr(1:end-1)];
end
pnBipolar = 2*pnCode - 1;   % Bipolar chips (+1/-1)

%% ---------------------- 4. Spreading (Transmitter) -----------------------
% Each data bit is multiplied by one full period of the PN code ->
% bandwidth expanded by factor PG (processing gain).
spreadSignal = zeros(1, Nb*PG);
for i = 1:Nb
    spreadSignal((i-1)*PG+1 : i*PG) = dataBipolar(i) * pnBipolar;
end

%% ---------------------- 5. BPSK Modulation onto Carrier ------------------
chipsUpsampled = repelem(spreadSignal, sampPerChip);
t              = (0:length(chipsUpsampled)-1)/fs;
txCarrier      = cos(2*pi*fc*t);
txSignal       = chipsUpsampled .* txCarrier;   % DS-SS BPSK transmitted signal

%% ---------------------- 6. AWGN Channel -----------------------------------

Eb_passband = Tb/2;
EbN0Lin     = 10^(EbN0dB/10);
N0          = Eb_passband/EbN0Lin;
noiseVar    = N0*fs/2;
rxSignal    = txSignal + sqrt(noiseVar)*randn(size(txSignal));

%% ---------------------- 7. Receiver: Coherent Demodulation ----------------
rxMixed = rxSignal .* txCarrier;                  % Assume perfect carrier sync
lpf     = ones(1, sampPerChip)/sampPerChip;        % Chip-matched (boxcar average) filter
rxFiltered    = filter(lpf, 1, rxMixed);
rxChipSamples = rxFiltered(sampPerChip:sampPerChip:end);  % One sample/chip (integrate-and-dump)

%% ---------------------- 8. Despreading + Bit Detection ---------------------
% Correlate received chips with the SAME, synchronized PN sequence, then
% integrate ("dump") over one bit period -> correlation receiver.
rxBits = zeros(1, Nb);
for i = 1:Nb
    chipsThisBit = rxChipSamples((i-1)*PG+1 : i*PG);
    despread     = chipsThisBit .* pnBipolar;
    corrOut      = sum(despread);
    rxBits(i)    = corrOut > 0;
end

%% ---------------------- 9. Results (illustrative single run) ---------------
numErrors = sum(rxBits ~= data);
BER       = numErrors/Nb;
theoreticalBER   = qfunc(sqrt(2*EbN0Lin));         % antipodal BPSK reference
expectedErrors   = theoreticalBER*Nb;
fprintf('===== DSSS System Results (Eb/N0 = %d dB, %d bits) =====\n', EbN0dB, Nb);
fprintf('Transmitted bits : %s\n', num2str(data));
fprintf('Received bits    : %s\n', num2str(rxBits));
fprintf('Number of errors : %d\n', numErrors);
fprintf('BER (this run)   : %.4f\n', BER);
fprintf('Theoretical BER at this Eb/N0     : %.5f\n', theoreticalBER);
fprintf('Expected errors in %d bits        : %.3f\n', Nb, expectedErrors);
fprintf('NOTE: with only %d bits, getting 0 errors is NORMAL whenever\n', Nb);
fprintf('      expectedErrors is well below 1 (try lowering EbN0dB, e.g.\n');
fprintf('      to -4 or -6, to reliably see errors in a single run).\n');
fprintf('      See Section 12 for the statistically meaningful BER curve.\n\n');

%% ---------------------- 10. Time-domain Plots -------------------------------
figure('Name','DSSS Signals');
subplot(4,1,1);
stairs([data data(end)], 'LineWidth', 1.5); ylim([-0.5 1.5]);
title('Original Data Bits'); grid on;

subplot(4,1,2);
stairs([pnCode pnCode(end)], 'LineWidth', 1.5); ylim([-0.5 1.5]);
title(sprintf('PN Spreading Code (1 period, PG = %d)', PG)); grid on;

subplot(4,1,3);
stairs([spreadSignal spreadSignal(end)]);
title('Spread Bipolar Chip Sequence'); grid on;

subplot(4,1,4);
plotLen = min(2000, length(txSignal));   % defensive: never exceed signal length
plot(t(1:plotLen), txSignal(1:plotLen));
title('DS-SS BPSK Transmitted Signal (zoomed in)'); xlabel('Time (s)'); grid on;

%% ---------------------- 11. Power Spectral Density --------------------------
figure('Name','DSSS Spectrum');
Nfft    = 2^nextpow2(length(txSignal));   % size FFT to the actual signal (no truncation)
f       = (-Nfft/2:Nfft/2-1)*(fs/Nfft);
Sspread = fftshift(abs(fft(txSignal, Nfft)).^2);
plot(f/1e3, 10*log10(Sspread/max(Sspread) + eps));
xlabel('Frequency (kHz)'); ylabel('Normalized PSD (dB)');
title('PSD of DS-SS Transmitted Signal (bandwidth spread by PG)');
grid on;

%% ---------------------- 12. BER vs Eb/N0 (Monte Carlo, baseband) ------------

Eb_baseband  = Tb;
EbN0dB_range = 0:2:12;
BER_sim      = zeros(size(EbN0dB_range));
NbitsTest    = 5000;
dataTest         = randi([0 1], 1, NbitsTest);
dataTestBipolar  = 2*dataTest - 1;
spreadTest       = zeros(1, NbitsTest*PG);
for i = 1:NbitsTest
    spreadTest((i-1)*PG+1:i*PG) = dataTestBipolar(i) * pnBipolar;
end

for k = 1:length(EbN0dB_range)
    EbN0Lin_k = 10^(EbN0dB_range(k)/10);
    N0_k      = Eb_baseband/EbN0Lin_k;
    noiseChip = sqrt(N0_k/(2*Tc)) * randn(1, NbitsTest*PG);
    rxChip    = spreadTest + noiseChip;

    rxBitsTest = zeros(1, NbitsTest);
    for i = 1:NbitsTest
        seg = rxChip((i-1)*PG+1:i*PG) .* pnBipolar;
        rxBitsTest(i) = sum(seg) > 0;
    end
    BER_sim(k) = sum(rxBitsTest ~= dataTest)/NbitsTest;
end

figure('Name','DSSS BER Performance');
semilogy(EbN0dB_range, BER_sim, '-o', 'LineWidth', 1.5); hold on;
semilogy(EbN0dB_range, qfunc(sqrt(2*10.^(EbN0dB_range/10))), '--r', 'LineWidth', 1.5);
xlabel('E_b/N_0 (dB)'); ylabel('Bit Error Rate');
legend('Simulated DS-SS (despread)', 'Theoretical BPSK');
title('BER Performance of the DS-SS System vs. Theoretical BPSK');
grid on;