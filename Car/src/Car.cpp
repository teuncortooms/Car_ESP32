#include <Arduino.h>

class Car
{
    int _up;
    int _down;
    int _left;
    int _right;

public:
    Car(int up, int down, int left, int right)
    {
        _up = up;
        _down = down;
        _left = left;
        _right = right;
        setup();
    }

    void GoUp()
    {
        Serial.println("Going up");
        // Serial.println(_endMarker);
        startPin(_up);
    }

    void GoDown()
    {
        Serial.println("Going down");
        // Serial.println(_endMarker);
        startPin(_down);
    }

    void GoLeft()
    {
        Serial.println("Going left");
        // Serial.println(_endMarker);
        startPin(_left);
    }

    void GoRight()
    {
        Serial.println("Going right");
        // Serial.println(_endMarker);
        startPin(_right);
    }

private:
    void setup()
    {
        pinMode(_up, OUTPUT);
        pinMode(_down, OUTPUT);
        pinMode(_left, OUTPUT);
        pinMode(_right, OUTPUT);
    }

    void startPin(int pin)
    {
        digitalWrite(pin, HIGH);
        delay(500);
        digitalWrite(pin, LOW);
    }
};