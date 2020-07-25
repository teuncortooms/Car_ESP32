#include "CarController.h"

CarController::CarController(Car& car)
    : _car(car)
{
}

void CarController::Exec(String message)
{
    if (message == "Up")
    {
        _car.GoUp();
    }
    if (message == "Down")
    {
        _car.GoDown();
    }
    if (message == "Left")
    {
        _car.GoLeft();
    }
    if (message == "Right")
    {
        _car.GoRight();
    }
    if (message == "Stop")
    {
        _car.Stop();
    }
}