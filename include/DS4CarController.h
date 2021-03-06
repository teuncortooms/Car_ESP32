#ifndef DS4CarController_h
#define DS4CarController_h

#include <Arduino.h>
#include <PS4Controller.h>
#include <Car.h>
#include <Enums.h>

class DS4CarController
{
    Car _car;
    int threshold;

public:
    DS4CarController(Car &car);
    void Setup(char ps4Mac[18]);
    void WaitForController();
    void HandleInput();

private:
    void handleMovement();
    bool analogSticksMoved();
    void handleAnalogSticks();
    bool L2OrR2Moved();
    void handleL2andR2();
    void handleAnalogInput(Side side, int coords);
    int convertCoordToSpeed(int coord);
};

#endif