#ifndef CarController_h
#define CarController_h

#include <Arduino.h>
#include <Car.h>

class CarController
{
    Car _car;

public:
    CarController(int LeftAcceleratePin, int LeftReversePin, int RightAcceleratePin, int RightReversePin);
    void Exec(String message);
};

#endif