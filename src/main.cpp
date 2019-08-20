#include <Arduino.h>
#include <Constants.h>
#include <Drivetrain.h>

Drivetrain arcadeDrive;
void setup() {
  Serial.begin(9600);
  Serial.print(arcadeDrive.init(leftPort, rightPort));
}

void loop() {
  arcadeDrive.drive(50, 0);
}