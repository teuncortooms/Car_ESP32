#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

class Motor
{
    int AcceleratePin;
    int ReversePin;
    int SpeedPin;
    int SpeedPwmChannel;
    int Speed;

public:
    Motor(int AcceleratePin, int ReversePin, int SpeedPin, int SpeedPwmChannel);
    void Setup();
    void Accelerate();
    void Reverse();
    void Stop();
    void SetSpeed(int speed);
    void AdjustSpeed(int increment);
};

#endif