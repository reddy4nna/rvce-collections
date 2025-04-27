// ULTRASONIC SENSOR LED INTERFACE
/*
ultrasonic sensor: 
vcc --> 5v
echo --> pin 8
trig --> pin 9
gnd --> gnd

led:
small side --> gnd
longer side --> pin 3
*/

int trigPin = 9;
int echoPin = 8;
int led_Pin = 3;
int distance_threshold = 40;
float duration_us, distance_cm;

void setup(){
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led_Pin, OUTPUT);
}

void loop(){
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration_us = pulseIn(echoPin, HIGH);

    distance_cm = 0.017 * duration_us;
    if(distance_cm <distance_threshold)
    digitalWrite(led_Pin, HIGH);
    else digitalWrite(led_Pin, LOW);

    Serial.print("distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
    delay(500);
}

//TEMPERACTURE AND HUMIDITY SENSOR WITH LED
/*
display board:
scl --> a5 <last to last>
sda --> a4
vcc --> 5v
gnd --> gnd

sensor (chex borad):
vcc --> 3v
middle pin--> 2
gnd --> gnd
*/

#include "DHT.h"
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    dht.begin();
}

void loop(){
    float humi=dht.readHumidity(0); //float humi=dht.readHumidity(); take out 0 if any error arises
    float tempC=dht.readTemperature();
    Serial.print("humidity: ");
    Serial.print(humi);
    Serial.print("%");
    Serial.print("      |   ");
    Serial.print("temperature");
    Serial.print(tempC);
    Serial.print("      .C  ");

    lcd.clear(); //if overlapping occurs
    lcd.setCursor(0,0);
    lcd.print("humi:    ");
    lcd.print(humi);
    lcd.print("%");
    
    lcd.setCursor(0,1);
    lcd.print("Temp:    ");
    lcd.print(tempC);
    lcd.print("     .C  ");
    delay(500);
}

//FLAME SENSOR

/*
flame sensor(one led type bulb):
vcc --> 5v
gnd --> gnd
flame pin --> 2

buzzer:
gnd --> gnd
other --> 13
*/

int Buzzer = 13;
int FlamePin = 2;

void setup(){
    pinMode(Buzzer, OUTPUT);
    pinMode(FlamePin, INPUT);
    Serial.begin(9600);
}

void loop(){
    int Flame = digitalRead(FlamePin);
    if (Flame == HIGH){
        Serial.println("HIGH FLAME");
        digitalWrite(Buzzer, HIGH);
    }
    else{
        Serial.println("NO FLAME");
        digitalWrite(Buzzer, LOW);
    }
}

//WATER LEVEL SENSOR
/*
water pump:
gnd --> gnd
other --> 2

led:
gnd --> gnd
other --> 13 (longer)
*/

int FloatSensor = 2;
int led=13;

void setup(){
    Serial.begin(9600);
    pinMode(FloatSensor, INPUT_PULLUP);
    pinMode(led, OUTPUT);
}

void loop(){
    int buttonState=digitalRead(FloatSensor);
    if (buttonState==HIGH){
        digitalWrite(led, LOW);
        Serial.println("WATERLEVEL - HIGH");
    }
    else{
        digitalWrite(led, HIGH);
        Serial.println("WATERLEVEL - LOW");
    }
    delay(1000);
}


//Moisture sensor
/*
the probe type thing(scissors lokking):
vcc --> 5v
gnd --> gnd
a0 --> a0 (if analog)
d0 --> 8 (if digital)

led:
gnd --> gnd
other --> 13 (o/p)
*/

//if analog:
int sensor_pin = A0;
int output;
void setup(){
    Serial.begin(9600);
    Serial.println("reading from sensor... ");
    delay(2000);
}

void loop(){
    output = analogRead(sensor_pin);
    output = map(output,500,10,0,100);
    Serial.print("Moisture: ");
    Serial.print(output);
    Serial.println("%");
    delay(1000);
}

//if digital:
int sensor_pin = 8;
int led_pin = 13;
void setup(){
    pinMode(sensor_pin,INPUT);
    pinMode(led_pin,OUTPUT);
}

void loop(){
    if(digitalRead(sensor_pin)==HIGH)
        digitalWrite(led_pin,HIGH);
    else{
        digitalWrite(led_pin,LOW);
        delay(1000);
    }
}


//TOUCH SENSOR
/*
finger print kinda thing:
vcc --> 5v
gnd --> gnd
other --> 2

led:
short --> gnd
other --> 3
*/

const int touch_sensor = 2;
const int led_pin = 3;

void setup(){
    Serial.begin(9600);
    pinMode(touch_sensor,INPUT);
    pinMode(led_pin,OUTPUT);
}

void loop(){
    int touchstate = digitalRead(touch_sensor);
    if(touchstate== HIGH){
        Serial.println("Sensor is beign touched");
        digitalWrite(led_pin,HIGH);
    }
    else{
        Serial.println("Sensor is no tbe ing touched");
        digitalWrite(led_pin,LOW);
        delay(1000);
    }
}

//DOOR SENSOR
/*
door like thingy:
gnd --> gnd
other --> 13

led:
short --> gnd
other --> 3
*/

const int door_sensor = 13;
int led_pin =3;

void setup(){
    Serial.begin(9600);
    pinMode(door_sensor, INPUT_PULLUP);
    pinMode(led_pin,OUTPUT);
}

void loop(){
    int doorstate = digitalRead(door_sensor);
    if(doorstate== HIGH){
        Serial.println("door is open");
        digitalWrite(led_pin,HIGH);
    }
    else{
        Serial.println("door is closed");
        digitalWrite(led_pin,LOW);
        delay(1000);
    }
}

//LDR SENSOR
/*
4 pin and a led typa:
vcc --> 5v
gnd --> gnd
A0 --> A0

led:
short --> gnd
other --> 2
*/

const int ldrpin = A0;
const int ledpin = 2;

void setup(){
    Serial.begin(9600);
    pinMode(ledpin,OUTPUT);
    pinMode(ldrpin,INPUT);
}

void loop(){
    int ldrstate = analogRead(ldrpin);
    if(ldrstate<=200){
        digitalWrite(ledpin,LOW);
        Serial.print("its bright turn off the led");
        Serial.println(ldrstate);
    }
    else{
        digitalWrite(ledpin,HIGH);
        Serial.print("its dark turn on the led");
        Serial.println(ldrstate);
    }
}

//SMOKE SENSOR
/*
pan looking thingy:
vcc --> 5v
gnd --> gnd
A0 --> A5

2 leds:
short --> gnd (in both)
other --> 11 and 12 (each)

buzzer: 
black --> gnd
other --> 10
*/

int redled = 12;
int greenled = 11;
int buzzer = 10;
int smokeA0 = A5;
int smoke_threshold = 150


void setup(){
    Serial.begin(9600);
    pinMode(redled,OUTPUT);
    pinMode(greenled,OUTPUT);
    pinMode(buzzer,OUTPUT);
    pinMode(smokeA0,INPUT);
}

void loop(){
    int smokestate = analogRead(smokeA0);
    if (smokestate>smoke_threshold){
        digitalWrite(redled,HIGH);
        digitalWrite(greenled,LOW);
        tone(buzzer,1000,200);
    }
    else{
        digitalWrite(redled,LOW);
        digitalWrite(greenled,HIGH);
        noTone(buzzer);
    }

    delay(1000)
}

//IR SENSOR
/*
ir (2led thingy): 
vcc --> 5v
gnd --> gnd
oter --> 4

servo motor(helicopter thingy on top): 
vcc --> 5v
gnd --> gnd
pwm --> 5

*/
#include <Servo.h>
Servo servo;
int sensor_pin = 4;
int servo_pin = 5;

void setup(){
    Serial.begin(9600);
    pinMode(sensor_pin,INPUT);
    servo.attach(servo_pin);
}

void loop(){
    int val = digitalRead(sensor_pin);
    if(val==0){
        servo.write(0);
        Serial.println("motor off");
    }
    else{
        servo.write(180);
        Serial.println("motor on");
    }
}