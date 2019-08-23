#include <Drivetrain.h>
#include <Arduino.h>

int Drivetrain::limit(int amount) {
    if(amount > upperMax) {
        return upperMax;
    } else if (amount < lowerMin) {
        return lowerMin;
    } else {
        return amount;
    }
}

Drivetrain::Drivetrain() : leftServo(Servo()), rightServo(Servo()) {}

void Drivetrain::init(InitFunction func) {
    func(leftServo, rightServo);
}

void Drivetrain::drive(int rawSpeed, int rawRotation) {
    rawSpeed = limit(rawSpeed), rawRotation = limit(rawRotation);

    int speed = copysign(rawSpeed, rawSpeed);
    int rotation = copysign(rawRotation, rawRotation);

    int maxInput = copysign(max(abs(speed), abs(rotation)), speed);

    int leftMotorOutput;
    int rightMotorOutput;

    if(speed >= 0) {
        if(rotation >= 0) {
            leftMotorOutput = maxInput;
            rightMotorOutput = speed - rotation;
        } else {
            leftMotorOutput = speed + rotation;
            rightMotorOutput = maxInput;
        }
    } else {
        if(rotation >= 0) {
            leftMotorOutput = speed + rotation;
            rightMotorOutput = maxInput;
        } else {
            leftMotorOutput = maxInput;
            rightMotorOutput = speed - rotation;
        }
    } 
    rawDrive(limit(leftMotorOutput), limit(rightMotorOutput) * -1);
}

void Drivetrain::rawDrive(int leftSpeed, int rightSpeed) {
    Serial.println(map(leftSpeed, -100, 100, 0, 180));
    Serial.println(map(rightSpeed, -100, 100, 0, 180));
    Serial.println(" ");
    leftServo.writeMicroseconds(map(leftSpeed, -100, 100, 1400, 1600));
    rightServo.writeMicroseconds(map(rightSpeed, -100, 100, 1400, 1600));
}
