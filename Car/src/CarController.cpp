#include "CarController.h"

CarController::CarController() : _car(18, 22, 23, 19)
{
    _counter = 0;
}

void CarController::Exec(String message)
{
    if (message.indexOf("/?GO_UP") > 0 || message == "Up")
    {
        Serial.print(_counter++);
        Serial.print(": ");
        _car.GoUp();
    }
    if (message.indexOf("/?GO_DOWN") > 0 || message == "Down")
    {
        Serial.print(_counter++);
        Serial.print(": ");
        _car.GoDown();
    }
    if (message.indexOf("/?GO_LEFT") > 0 || message == "Left")
    {
        Serial.print(_counter++);
        Serial.print(": ");
        _car.GoLeft();
    }
    if (message.indexOf("/?GO_RIGHT") > 0 || message == "Right")
    {
        Serial.print(_counter++);
        Serial.print(": ");
        _car.GoRight();
    }
}
