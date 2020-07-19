#include "Car.h"

Car::Car(int LeftAcceleratePin, int LeftReversePin, int RightAcceleratePin, int RightReversePin)
{
    this->indexLeftAccelerate = 0;
    this->indexLeftReverse = 1;
    this->indexRightAccelerate = 2;
    this->indexRightReverse = 3;
    this->pins[indexLeftAccelerate] = LeftAcceleratePin;
    this->pins[indexLeftReverse] = LeftReversePin;
    this->pins[indexRightAccelerate] = RightAcceleratePin;
    this->pins[indexRightReverse] = RightReversePin;
    for (int index : this->states)
    {
        this->states[index] = LOW;
    }
    setup();
}

void Car::GoUp()
{
    switchAllOff();
    switchOn(this->indexLeftAccelerate);
    switchOn(this->indexRightAccelerate);
}

void Car::GoDown()
{
    switchAllOff();
    switchOn(this->indexLeftReverse);
    switchOn(this->indexRightReverse);
}

void Car::GoLeft()
{
    switchAllOff();
    switchOn(this->indexRightAccelerate);
    switchOn(this->indexLeftReverse);
}

void Car::GoRight()
{
    switchAllOff();
    switchOn(this->indexRightReverse);
    switchOn(this->indexLeftAccelerate);
}

void Car::setup()
{
    for (int index : this->pins)
    {
        pinMode(index, OUTPUT);
    }
}

void Car::togglePin(int pinIndex)
{
    this->states[pinIndex] = !this->states[pinIndex];
    digitalWrite(this->pins[pinIndex], this->states[pinIndex]);
}

void Car::switchOn(int pinIndex)
{
    this->states[pinIndex] = HIGH;
    digitalWrite(this->pins[pinIndex], this->states[pinIndex]);
}

void Car::switchOff(int pinIndex)
{
    states[pinIndex] = LOW;
    digitalWrite(pins[pinIndex], states[pinIndex]);
}

void Car::switchAllOff()
{
    for (int i : this->pins)
    {
        switchOff(pins[i]);
    }
}

