#ifndef CarController_h
#define CarController_h

#include <Arduino.h>
#include <Car.h>

class CarController
{
    Car _car;

public:
    CarController(Car& car);
    void Exec(String message);
};

#endif