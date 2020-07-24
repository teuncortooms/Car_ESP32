#include "CarController.h"

CarController::CarController(
    int LeftAcceleratePin,
    int LeftReversePin,
    int LeftSpeedPin,
    int LeftSpeedPwmChannel,
    int RightAcceleratePin,
    int RightReversePin,
    int RightSpeedPin,
    int RightSpeedPwmChannel)
    : _car(
          LeftAcceleratePin,
          LeftReversePin,
          LeftSpeedPin,
          LeftSpeedPwmChannel,
          RightAcceleratePin,
          RightReversePin,
          RightSpeedPin,
          RightSpeedPwmChannel)
{
}

void CarController::Exec(String message)
{
    if (message.indexOf("/?GO_UP") > 0 || message == "Up")
    {
        _car.GoUp();
    }
    if (message.indexOf("/?GO_DOWN") > 0 || message == "Down")
    {
        _car.GoDown();
    }
    if (message.indexOf("/?GO_LEFT") > 0 || message == "Left")
    {
        _car.GoLeft();
    }
    if (message.indexOf("/?GO_RIGHT") > 0 || message == "Right")
    {
        _car.GoRight();
    }
    if (message.indexOf("/?STOP") > 0 || message == "Stop")
    {
        _car.Stop();
    }
}
