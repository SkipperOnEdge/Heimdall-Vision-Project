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

bool Drivetrain::init(int leftPort, int rightPort) {
    bool left = leftServo.attach(leftPort);
    bool right = rightServo.attach(rightPort);
    Serial.println(left);
    Serial.println(right);
    return left && right;
}

void Drivetrain::drive(int rawSpeed, int rawRotation) {
    rawSpeed = limit(rawSpeed), rawRotation = limit(rawRotation);
    
    int speed = copysign(rawSpeed * rawSpeed / 100, rawSpeed);
    int rotation = copysign(rawRotation * rawRotation / 100, rawRotation);

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
    setServos(limit(leftMotorOutput), limit(rightMotorOutput) * -1);
}

void Drivetrain::setServos(int leftRaw, int rightRaw) {
    leftServo.write(map(leftRaw, -100, 100, 0, 180));
    rightServo.write(map(rightRaw, -100, 100, 0, 180));
}
