#include <Arduino.h>
#include <Servo.h>
#include <Constants.h>
#include <Drivetrain.h>

Drivetrain arcadeDrive;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print(arcadeDrive.init( LEFT_PORT , RIGHT_PORT ));
}

void loop() {
arcadeDrive.drive( 0 , 100);
}