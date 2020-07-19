#ifndef Car_h
#define Car_h

#include <Arduino.h>

class Car
{
    int indexLeftAccelerate;
    int indexLeftReverse;
    int indexRightAccelerate;
    int indexRightReverse;
    int pins[4];
    int states[4];

public:
    Car(int LeftAcceleratePin, int LeftReversePin, int RightAcceleratePin, int RightReversePin);
    void GoUp();
    void GoDown();
    void GoLeft();
    void GoRight();

private:
    void setup();
    void togglePin(int pinIndex);
    void switchOn(int pinIndex);
    void switchOff(int pinIndex);
    void switchAllOff();
};

#endif