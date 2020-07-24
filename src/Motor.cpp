#include "Motor.h"

Motor::Motor(
    int AcceleratePin,
    int ReversePin,
    int SpeedPin,
    int SpeedPwmChannel)
{
    this->AcceleratePin = AcceleratePin;
    this->ReversePin = ReversePin;
    this->SpeedPin = SpeedPin;
    this->SpeedPwmChannel = SpeedPwmChannel;
    this->Speed = 255;
    Setup();
}

void Motor::Setup()
{
    pinMode(AcceleratePin, OUTPUT);
    pinMode(ReversePin, OUTPUT);
    ledcSetup(SpeedPwmChannel, 5000, 8);
    ledcAttachPin(SpeedPin, SpeedPwmChannel);
    ledcWrite(SpeedPwmChannel, Speed);
}

void Motor::Accelerate()
{
    digitalWrite(AcceleratePin, HIGH);
    digitalWrite(ReversePin, LOW);
}

void Motor::Reverse()
{
    digitalWrite(AcceleratePin, LOW);
    digitalWrite(ReversePin, HIGH);
}

void Motor::Stop()
{
    digitalWrite(AcceleratePin, LOW);
    digitalWrite(ReversePin, LOW);
}

void Motor::SetSpeed(int speed)
{
    this->Speed = speed;
    ledcWrite(SpeedPwmChannel, this->Speed);
}

void Motor::AdjustSpeed(int increment)
{
    this->Speed += increment;
    ledcWrite(SpeedPwmChannel, this->Speed);
}
