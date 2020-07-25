#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include <Motor.h>

class Car
{
    Motor leftMotor;
    Motor rightMotor;
    int speed;

public:
    Car(
        int LeftAcceleratePin,
        int LeftReversePin,
        int LeftSpeedPin,
        int LeftSpeedPwmChannel,
        int RightAcceleratePin,
        int RightReversePin,
        int RightSpeedPin,
        int RightSpeedPwmChannel);
    void GoUp();
    void GoDown();
    void GoLeft();
    void GoRight();
    void Stop();
    int GetSpeed();
    void SetSpeed(int speed);
    void AdjustSpeed(int increment);
};

#endif