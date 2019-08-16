#include <Arduino.h>
#include <Servo.h>
#include <Constants.h>

Servo left;
Servo right;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  left.attach(LEFT_PORT);
  right.attach(RIGHT_PORT);
}

void loop() {
  while (Serial.available() > 0) {
    int leftAmount = Serial.parseInt();
    int rightAmount = Serial.parseInt();

    if (Serial.read() == '\n') {
      left.write(leftAmount);
      right.write(rightAmount);
    }
  }
}