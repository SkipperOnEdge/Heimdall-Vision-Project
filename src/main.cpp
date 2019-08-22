#include <Arduino.h>
#include <Constants.h>
#include <Drivetrain.h>

Drivetrain arcadeDrive;
void setup() {
  Serial.begin(9600);
  Serial.print(arcadeDrive.init(leftPort, rightPort));
}

void loop() {
  int forwardInput = 50;
  int rotationInput = 60;
  arcadeDrive.drive(forwardInput , rotationInput);
  // arcadeDrive.rawDrive(0,0);
}