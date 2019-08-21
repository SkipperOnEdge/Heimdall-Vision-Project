#include <Arduino.h>
#include <Constants.h>
#include <Drivetrain.h>

Drivetrain arcadeDrive;
void setup() {
  Serial.begin(9600);
  Serial.print(arcadeDrive.init(leftPort, rightPort));
  int forwardInput = 0;
  int rotationInput = 0;
}

void loop() {
  int forwardInput = 0;
  int rotationInput = 0;
  arcadeDrive.drive(forwardInput , rotationInput);
}