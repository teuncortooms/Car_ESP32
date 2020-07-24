#include "Car.h"

Car::Car(
    int LeftAcceleratePin,
    int LeftReversePin,
    int LeftSpeedPin,
    int LeftSpeedPwmChannel,
    int RightAcceleratePin,
    int RightReversePin,
    int RightSpeedPin,
    int RightSpeedPwmChannel)
    : LeftMotor(LeftAcceleratePin, LeftReversePin, LeftSpeedPin, LeftSpeedPwmChannel),
      RightMotor(RightAcceleratePin, RightReversePin, RightSpeedPin, RightSpeedPwmChannel)
{
    LeftMotor.Setup();
    RightMotor.Setup();
}

void Car::GoUp()
{
    LeftMotor.Accelerate();
    RightMotor.Accelerate();
    Serial.println("going up");
}

void Car::GoDown()
{
    LeftMotor.Reverse();
    RightMotor.Reverse();
    Serial.println("going down");
}

void Car::GoLeft()
{
    LeftMotor.Reverse();
    RightMotor.Accelerate();
    Serial.println("going left");
}

void Car::GoRight()
{
    LeftMotor.Accelerate();
    RightMotor.Reverse();
    Serial.println("going right");
}

void Car::Stop()
{
    LeftMotor.Stop();
    RightMotor.Stop();
    Serial.println("stopped");
}

void Car::SetSpeed(int speed)
{
    LeftMotor.SetSpeed(speed);
    RightMotor.SetSpeed(speed);
}

void Car::AdjustSpeed(int increment)
{
    LeftMotor.AdjustSpeed(increment);
    RightMotor.AdjustSpeed(increment);
}