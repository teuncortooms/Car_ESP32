#ifndef DS4CarController_h
#define DS4CarController_h

#include <Arduino.h>
#include <PS4Controller.h>
#include <Car.h>

class DS4CarController
{
    Car _car;
    int analogStickThreshold;

public:
    DS4CarController(Car &car);
    void Setup(char *ps4Mac);
    void WaitForController();
    void HandleInput();

private:
    void handleMovement();
    bool eitherAnalogStickIsAboveThreshold();
    void driveLeftMotor(int coord);
    void driveRightMotor(int coord);
    int convertCoordToSpeed(int coord);
    void driveMotor(String side, int speed);
};

#endif