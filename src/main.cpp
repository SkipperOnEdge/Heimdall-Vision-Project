#include <Arduino.h>
#include <Constants.h>
#include <Drivetrain.h>
#include <Stream.h>

Drivetrain arcadeDrive{};

void setup() {
  Serial.begin(9600);
  arcadeDrive.init([](Servo leftServo, Servo rightServo) {
          leftServo.attach(leftPort, 1400, 1600);
          rightServo.attach(rightPort, 1400, 1600);
        });
}

void loop() {
  while (Serial.available() > 0) {
    int speed = Serial.parseInt();
    int rotation = Serial.parseInt();

    arcadeDrive.drive(speed, rotation);
  }
}