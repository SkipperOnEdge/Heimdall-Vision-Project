#ifndef Drivetrain_h
#define Drivetrain_h

#include <Servo.h>

class Drivetrain {
    public:
        static constexpr int upperMax = 100, lowerMin = -upperMax;
        Drivetrain();
        bool init(int leftPort, int rightPort);
        void drive(int rawSpeed, int rawRotation);
        void rawDrive(int leftSpeed, int rightSpeed);
    private:
        Servo leftServo;
        Servo rightServo;
        static int limit(int amount);
};

#endif