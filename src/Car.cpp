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
}

void Car::GoDown()
{
    leftMotor.Reverse();
    rightMotor.Reverse();
}

void Car::GoLeft()
{
    leftMotor.Stop();
    rightMotor.Accelerate();
}

void Car::GoRight()
{
    leftMotor.Accelerate();
    rightMotor.Stop();
}

void Car::GoUpLeft()
{
    leftMotor.Accelerate(0.7 * this->speed);
    rightMotor.Accelerate();
}

void Car::GoUpRight()
{
    leftMotor.Accelerate();
    rightMotor.Accelerate(0.7 * this->speed);
}

void Car::Stop()
{
    leftMotor.Stop();
    rightMotor.Stop();
}

int Car::GetSpeed()
{
    return this->speed;
}

int Car::GetMinSpeed()
{
    return this->minSpeed;
}

int Car::GetMaxSpeed()
{
    return this->maxSpeed;
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

void Car::DriveMotor(Side side, int speed)
{
    if (side == LEFT && speed == 0)
        leftMotor.Stop();
    if (side == LEFT && speed > 0)
        leftMotor.Accelerate(speed);
    if (side == LEFT && speed < 0)
        leftMotor.Reverse(abs(speed));
    if (side == RIGHT && speed == 0)
        rightMotor.Stop();
    if (side == RIGHT && speed > 0)
        rightMotor.Accelerate(speed);
    if (side == RIGHT && speed < 0)
        rightMotor.Reverse(abs(speed));
}