#include <Servo.h>

Servo rotation;  // create servo object to control a servo
Servo pitch;
const int q1Resistor = A0;
const int q2Resistor = A1;
int threshold = 40;
int valueq1;
int valueq2;
void setup() {
  rotation.attach(6);
  pitch.attach(5);
  pinMode(q1Resistor, INPUT);
  Serial.begin(9600);
  pinMode(q2Resistor, INPUT);
}

void loop() {
  valueq1 = analogRead(q1Resistor);
  valueq2 = analogRead(q2Resistor);
  Serial.println("VALUE Q1:");
  Serial.println(valueq1);
  Serial.println("VALUE Q2:");
  Serial.println(valueq2);
  int difference = valueq1 - valueq2;
  delay(500);
  int servoPos = rotation.read();
  if (abs(difference) > threshold) {
    if (difference > 0 && servoPos < 180) {
      rotation.write(servoPos - 5);
    } else if (difference < 0 && servoPos > 0) {
      rotation.write(servoPos + 5);
    }
  }
}