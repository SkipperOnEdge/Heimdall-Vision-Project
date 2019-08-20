#include <Drivetrain.h>
#include <Arduino.h>

Drivetrain::Drivetrain() : leftServo(Servo()), rightServo(Servo())  {
}

bool Drivetrain::init(int leftPort, int rightPort) {
    bool left = leftServo.attach(leftPort);
    bool right = rightServo.attach(rightPort);
    Serial.println(left);
    Serial.println(right);
    return left && right;
}

void Drivetrain::drive(int speed, int rotation) {
    speed = copysign(speed * speed / 100, speed);
    rotation = copysign(rotation * rotation / 100, rotation);
    int maxInput = copysign(max(abs(speed), abs(rotation)), speed);


    int leftMotorOutput;
    int rightMotorOutput;

    if( speed >= 0 ) {
        if(rotation >= 0) {
            leftMotorOutput = maxInput;
            rightMotorOutput = speed - rotation;
        }
        else{
            leftMotorOutput = speed + rotation;
            rightMotorOutput = maxInput;
        }
    }
    else{
        if(rotation >= 0) {
            leftMotorOutput = speed + rotation;
            rightMotorOutput = maxInput;
        }
        else {
            leftMotorOutput = maxInput;
            rightMotorOutput = speed - rotation;
        }
    }
 
    setServos(leftMotorOutput , rightMotorOutput);
}

void Drivetrain::setServos( int leftMotorRaw, int rightMotorRaw) {
    leftServo.write(map( leftMotorRaw , -100 , 100 , 0 , 180));
    rightServo.write(map( rightMotorRaw , -100 , 100 , 180 , 0));
}
