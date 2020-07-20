#include "Car.h"

Car::Car(int LeftAcceleratePin, int LeftReversePin, int RightAcceleratePin, int RightReversePin)
{
    this->LeftAccelerate = LeftAcceleratePin;
    this->LeftReverse = LeftReversePin;
    this->RightAccelerate = RightAcceleratePin;
    this->RightReverse = RightReversePin;
    setup();
}

void Car::setup()
{
    pinMode(this->LeftAccelerate, OUTPUT);
    pinMode(this->LeftReverse, OUTPUT);
    pinMode(this->RightAccelerate, OUTPUT);
    pinMode(this->RightReverse, OUTPUT);
}

void Car::GoUp()
{
    Stop();
    switchOn(this->LeftAccelerate);
    switchOn(this->RightAccelerate);
    Serial.println("going up");
    Serial.println(digitalRead(18));
    Serial.println(digitalRead(22));
}

void Car::GoDown()
{
    Stop();
    switchOn(this->LeftReverse);
    switchOn(this->RightReverse);
    Serial.println("going down");
    Serial.println(digitalRead(18));
    Serial.println(digitalRead(22));
}

void Car::GoLeft()
{
    Stop();
    switchOn(this->RightAccelerate);
    switchOn(this->LeftReverse);
    Serial.println("going left");
    Serial.println(digitalRead(18));
    Serial.println(digitalRead(22));
}

void Car::GoRight()
{
    Stop();
    switchOn(this->RightReverse);
    switchOn(this->LeftAccelerate);
    Serial.println("going right");
    Serial.println(digitalRead(18));
    Serial.println(digitalRead(22));
}

void Car::Stop()
{
    switchOff(this->LeftAccelerate);
    switchOff(this->LeftReverse);
    switchOff(this->RightAccelerate);
    switchOff(this->RightReverse);
    Serial.println("stopped");
    Serial.println(digitalRead(18));
    Serial.println(digitalRead(22));
}

void Car::switchOn(int pin)
{
    digitalWrite(pin, HIGH);
}

void Car::switchOff(int pin)
{
    digitalWrite(pin, LOW);
}
