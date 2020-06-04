#include <Arduino.h>

class Car
{
    int indexOfLeftMotorForwards;
    int indexOfLeftMotorBackwards;
    int indexOfRightMotorForwards;
    int indexOfRightMotorBackwards;
    int pinsCount = 4;
    int pins[pinsCount];
    int states[pinsCount];

public:
    Car(int pinOfLeftMotorForwards, int down, int left, int right)
    {
        this.indexOfLeftMotorForwards = 0;
        this.indexOfLeftMotorBackwards = 1;
        this.indexOfRightMotorForwards = 2;
        this.indexOfRightMotorBackwards = 3;
        this.pins[indexOfLeftMotorForwards] = pinOfLeftMotorForwards;
        this.pins[indexOfLeftMotorBackwards] = down;
        this.pins[indexOfRightMotorForwards] = left;
        this.pins[indexOfRightMotorBackwards] = right;
        for (int index : this.states)
        {
            this.states[index] = LOW;
        }
        setup();
    }

    void GoUp()
    {
        switchAllOff();
        switchOn(this.indexOfLeftMotorForwards);
    }

    void GoDown()
    {
        switchAllOff();
        switchOn(this.indexOfLeftMotorBackwards);
    }

    void GoLeft()
    {
        switchAllOff();
        switchOn(this.indexOfRightMotorForwards);
    }

    void GoRight()
    {
        switchAllOff();
        switchOn(this.indexOfRightMotorBackwards);
    }

private:
    void setup()
    {
        for (int index : this.pins)
        {
            pinMode(index, OUTPUT);
        }
    }

    void togglePin(int pinIndex)
    {
        this.states[pinIndex] = !this.states[pinIndex];
        digitalWrite(this.pins[pinIndex], this.states[pinIndex]);
    }

    void switchOn(int pinIndex)
    {
        this.states[pinIndex] = HIGH;
        digitalWrite(this.pins[pinIndex], this.states[pinIndex]);
    }

    void switchOff(int pinIndex)
    {
        states[pinIndex] = LOW;
        digitalWrite(pins[pinIndex], states[pinIndex]);
    }

    void switchAllOff()
    {
        for (int i = 0; i < this.pinsCount; i++)
        {
            switchOff(i);
        }
    }
};