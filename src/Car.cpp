#include "Car.h"

Car::Car(
    int leftAcceleratePin,
    int leftReversePin,
    int leftSpeedPin,
    int leftSpeedPwmChannel,
    int rightAcceleratePin,
    int rightReversePin,
    int rightSpeedPin,
    int rightSpeedPwmChannel,
    int minSpeed,
    int maxSpeed)
    : leftMotor(leftAcceleratePin, leftReversePin, leftSpeedPin, leftSpeedPwmChannel, minSpeed, maxSpeed),
      rightMotor(rightAcceleratePin, rightReversePin, rightSpeedPin, rightSpeedPwmChannel, minSpeed, maxSpeed)
{
    this->speed = maxSpeed;
    this->minSpeed = minSpeed;
    this->maxSpeed = maxSpeed;
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

void Car::SetSpeed(int input)
{
    int newSpeed;
    if (input < minSpeed)
        newSpeed = minSpeed;
    else if (input > maxSpeed)
        newSpeed = maxSpeed;
    else
        newSpeed = input;

    this->speed = newSpeed;
    leftMotor.SetSpeed(newSpeed);
    rightMotor.SetSpeed(newSpeed);
}

void Car::AdjustSpeed(int increment)
{
    int newSpeed = this->speed + increment;
    SetSpeed(newSpeed);
}