#ifndef Drivetrain_h
#define Drivetrain_h

#include <Servo.h>

class Drivetrain {
    public:
        Drivetrain();
        bool init(int leftPort, int rightPort);
        void drive(double speed, double rotation);
    private:
        Servo leftServo;
        Servo rightServo;
        void setServos(int leftServoRaw , int rightServoRaw);

    
};



#endif