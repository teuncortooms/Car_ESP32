#ifndef Car_h
#define Car_h

#include <Arduino.h>

class Car
{
    int LeftAccelerate;
    int LeftReverse;
    int RightAccelerate;
    int RightReverse;

public:
    Car(int LeftAcceleratePin, int LeftReversePin, int RightAcceleratePin, int RightReversePin);
    void GoUp();
    void GoDown();
    void GoLeft();
    void GoRight();
    void Stop();

private:
    void setup();
    void switchOn(int pin);
    void switchOff(int pin);
};

#endif