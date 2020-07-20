#include "SerialMessenger.h"

SerialMessenger::SerialMessenger()
{
    _inputString = "";
    _stringComplete = false;
    _endMarker = '#';
    _inputString.reserve(200);
}

char SerialMessenger::GetEndMarker()
{
    return _endMarker;
}

String SerialMessenger::GetMessage()
{
    getInput();
    return handleInput();
}

void SerialMessenger::getInput()
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

String SerialMessenger::handleInput()
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
