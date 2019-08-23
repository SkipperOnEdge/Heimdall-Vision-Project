#include <Arduino.h>
#include <Constants.h>
#include <Drivetrain.h>

Drivetrain arcadeDrive;
void setup() {
  Serial.begin(9600);
  arcadeDrive.init([](Servo leftServo, Servo rightServo) {
          leftServo.attach(leftPort, 1400, 1600);
          rightServo.attach(rightPort, 1400, 1600);
        });
}

void loop() {
  // int forwardInput = 50;
  // int rotationInput = 60;
  // arcadeDrive.drive(forwardInput , rotationInput);
   arcadeDrive.rawDrive(2,-2);
}