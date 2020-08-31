#include "Motor.h"

Motor::Motor(
    int acceleratePin,
    int reversePin,
    int speedPin,
    int speedPwmChannel,
    int minSpeed,
    int maxSpeed)
{
    this->acceleratePin = acceleratePin;
    this->reversePin = reversePin;
    this->speedPin = speedPin;
    this->speedPwmChannel = speedPwmChannel;
    this->speed = maxSpeed;
    this->minSpeed = minSpeed;
    this->maxSpeed = maxSpeed;
    Setup();
}

void Motor::Setup()
{
    pinMode(acceleratePin, OUTPUT);
    pinMode(reversePin, OUTPUT);
    ledcSetup(speedPwmChannel, 5000, 8);
    ledcAttachPin(speedPin, speedPwmChannel);
    SetSpeed(speed);
}

void Motor::Accelerate()
{
    digitalWrite(acceleratePin, HIGH);
    digitalWrite(reversePin, LOW);
}

void Motor::Accelerate(int tempSpeed)
{
    int baseSpeed = this->speed;
    SetSpeed(tempSpeed);
    Accelerate();
    SetSpeed(baseSpeed);
}

void Motor::Reverse()
{
    digitalWrite(acceleratePin, LOW);
    digitalWrite(reversePin, HIGH);
}

void Motor::Reverse(int tempSpeed)
{
    int baseSpeed = this->speed;
    SetSpeed(tempSpeed);
    Reverse();
    SetSpeed(baseSpeed);
}

void Motor::Stop()
{
    digitalWrite(acceleratePin, LOW);
    digitalWrite(reversePin, LOW);
}

void Motor::SetSpeed(int input)
{
    int newSpeed;
    if (input < minSpeed)
        newSpeed = minSpeed;
    else if (input > maxSpeed)
        newSpeed = maxSpeed;
    else
        newSpeed = input;
    this->speed = newSpeed;
    ledcWrite(speedPwmChannel, this->speed);
}

void Motor::AdjustSpeed(int increment)
{
    int newSpeed = this->speed + increment;
    SetSpeed(newSpeed);
}
