#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include <Motor.h>
#include <Enums.h>

class Car
{
    Motor leftMotor;
    Motor rightMotor;
    int speed;
    int minSpeed;
    int maxSpeed;

public:
    Car(
        int leftAcceleratePin,
        int leftReversePin,
        int leftSpeedPin,
        int leftSpeedPwmChannel,
        int rightAcceleratePin,
        int rightReversePin,
        int rightSpeedPin,
        int rightSpeedPwmChannel,
        int minSpeed,
        int maxSpeed);
    void GoUp();
    void GoDown();
    void GoLeft();
    void GoRight();
    void GoUpLeft();
    void GoUpRight();
    void Stop();
    int GetSpeed();
    int GetMinSpeed();
    int GetMaxSpeed();
    void SetSpeed(int speed);
    void AdjustSpeed(int increment);
    void DriveMotor(Side side, int speed);
};

#endif