#include "CarController.h"

CarController::CarController(Car &car)
    : _car(car)
{
}

void CarController::Exec(String message)
{
    if (message != previousMessage)
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
        if (message == "SlowDown")
        {
            // TODO: add millis check, to gradually process input
            _car.AdjustSpeed(-1);
            Serial.println(_car.GetSpeed());
        }
        if (message == "SpeedUp")
        {
            _car.AdjustSpeed(10);
            Serial.println(_car.GetSpeed());
        }
        if (message == "")
        {
            _car.Stop();
        }
    }
    previousMessage = message;
}