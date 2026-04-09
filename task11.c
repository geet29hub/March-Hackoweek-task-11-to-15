#include <Servo.h>

Servo myServo;
int sensorPin = 2;

void setup() {
  pinMode(sensorPin, INPUT);
  myServo.attach(9);
}

void loop() {
  int val = digitalRead(sensorPin);

  if (val == HIGH) {
    myServo.write(90); // Door Open
    delay(3000);
  } else {
    myServo.write(0); // Door Closed
  }
}
