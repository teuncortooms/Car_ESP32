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
    : leftMotor(LeftAcceleratePin, LeftReversePin, LeftSpeedPin, LeftSpeedPwmChannel),
      rightMotor(RightAcceleratePin, RightReversePin, RightSpeedPin, RightSpeedPwmChannel)
{
    leftMotor.Setup();
    rightMotor.Setup();
}

void Car::GoUp()
{
    leftMotor.Accelerate();
    rightMotor.Accelerate();
    Serial.println("going up");
}

void Car::GoDown()
{
    leftMotor.Reverse();
    rightMotor.Reverse();
    Serial.println("going down");
}

void Car::GoLeft()
{
    leftMotor.Reverse();
    rightMotor.Accelerate();
    Serial.println("going left");
}

void Car::GoRight()
{
    leftMotor.Accelerate();
    rightMotor.Reverse();
    Serial.println("going right");
}

void Car::Stop()
{
    leftMotor.Stop();
    rightMotor.Stop();
    Serial.println("stopped");
}

int Car::GetSpeed()
{
    return this->speed;
}

void Car::SetSpeed(int speed)
{
    this->speed = speed;
    leftMotor.SetSpeed(speed);
    rightMotor.SetSpeed(speed);
}

void Car::AdjustSpeed(int increment)
{
    this->speed += increment;
    leftMotor.AdjustSpeed(increment);
    rightMotor.AdjustSpeed(increment);
}