#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor
{
    int acceleratePin;
    int reversePin;
    int speedPin;
    int speedPwmChannel;
    int speed;
    int minSpeed;
    int maxSpeed;

public:
    Motor(int acceleratePin, int reversePin, int speedPin, int speedPwmChannel, int minSpeed, int maxSpeed);
    void Setup();
    void Accelerate();
    void Accelerate(int speed);
    void Reverse();
    void Reverse(int speed);
    void Stop();
    void SetSpeed(int speed);
    void AdjustSpeed(int increment);
};

#endif