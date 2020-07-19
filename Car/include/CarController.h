#ifndef CarController_h
#define CarController_h

#include <Arduino.h>
#include <Car.h>

class CarController
{
    int _counter;
    Car _car;

public:
    CarController();
    void Exec(String message);
};

#endif