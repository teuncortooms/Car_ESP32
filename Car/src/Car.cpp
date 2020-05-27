#include <Arduino.h>

class Car
{
    int _upIndex;
    int _downIndex;
    int _leftIndex;
    int _rightIndex;
    int pins[4];
    int states[4];

public:
    Car(int up, int down, int left, int right)
    {
        _upIndex = 0;
        _downIndex = 1;
        _leftIndex = 2;
        _rightIndex = 3;
        pins[_upIndex] = up;
        pins[_downIndex] = down;
        pins[_leftIndex] = left;
        pins[_rightIndex] = right;
        for (int index : states)
        {
            states[index] = LOW;
        }
        setup();
    }

    void GoUp()
    {
        togglePin(_upIndex);
    }

    void GoDown()
    {
        togglePin(_downIndex);
    }

    void GoLeft()
    {
        togglePin(_leftIndex);
    }

    void GoRight()
    {
        togglePin(_rightIndex);
    }

private:
    void setup()
    {
        for (int index : pins)
        {
            pinMode(index, OUTPUT);
        }
    }

    void togglePin(int pinIndex)
    {
        states[pinIndex] = !states[pinIndex];
        digitalWrite(pins[pinIndex], states[pinIndex]);
    }
};