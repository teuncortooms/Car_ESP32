#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include <Motor.h>

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
    void Stop();
    int GetSpeed();
    void SetSpeed(int speed);
    void AdjustSpeed(int increment);
    void LeftMotorUp(int speed);
    void LeftMotorDown(int speed);
    void RightMotorUp(int speed);
    void RightMotorDown(int speed);
};

#endif