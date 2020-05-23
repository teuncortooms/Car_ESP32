#include <Arduino.h>

class SerialMessenger
{

    String _inputString;
    bool _stringComplete;
    char _endMarker;

public:
    SerialMessenger()
    {
        _inputString = "";
        _stringComplete = false;
        _endMarker = '#';
        _inputString.reserve(200);
    }

    char GetEndMarker()
    {
        return _endMarker;
    }

    String GetMessage()
    {
        getInput();
        return handleInput();
    }

private:
    void getInput()
    {
        if (Serial.available())
        {
            char c = (char)Serial.read();
            if (c == _endMarker)
                _stringComplete = true;
            else
                _inputString += c;
        }
    }

    String handleInput()
    {
        if (_stringComplete)
        {
            String returnvalue = _inputString;
            _inputString = "";
            _stringComplete = false;
            return returnvalue;
        }
        else
            return "";
    }
};