#include <Arduino.h>

class SerialSoldier
{
    int _up;
    int _down;
    int _left;
    int _right;
    String _inputString;
    bool _stringComplete;

public:
    SerialSoldier(int up, int down, int left, int right)
    {
        _up = up;
        _down = down;
        _left = left;
        _right = right;
        _inputString = "";
        _stringComplete = false;
        setup();
    }

    void FollowOrders()
    {
        readInput();
        handleInput();
    }

private:
    void setup()
    {
        pinMode(_up, OUTPUT);
        pinMode(_down, OUTPUT);
        pinMode(_left, OUTPUT);
        pinMode(_right, OUTPUT);
        Serial.begin(115200);
        _inputString.reserve(200);
    }

    void readInput()
    {
        if (Serial.available())
        {
            char inChar = (char)Serial.read();
            if (inChar == '.')
                _stringComplete = true;
            else
                _inputString += inChar;
        }
    }

    void startPin(int pin)
    {
        digitalWrite(pin, HIGH);
        delay(500);
        digitalWrite(pin, LOW);
    }

    void handleInput()
    {
        if (_stringComplete)
        {
            int pin = -1;
            if (_inputString == "Up")
                pin = _up;
            if (_inputString == "Down")
                pin = _down;
            if (_inputString == "Left")
                pin = _left;
            if (_inputString == "Right")
                pin = _right;
            if (pin)
                startPin(pin);
            _inputString = "";
            _stringComplete = false;
        }
    }
};