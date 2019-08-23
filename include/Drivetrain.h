#ifndef Drivetrain_h
#define Drivetrain_h

#include <Servo.h>

using InitFunction = void (*)(Servo, Servo);

class Drivetrain {
    public:
        static constexpr int upperMax = 100, lowerMin = -upperMax;
        Drivetrain();
        void init(InitFunction func);
        void drive(int rawSpeed, int rawRotation);
        void rawDrive(int leftSpeed, int rightSpeed);
    private:
        Servo leftServo;
        Servo rightServo;
        static int limit(int amount);
};

#endif