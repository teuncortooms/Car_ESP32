#include "SerialMessenger.h"

SerialMessenger::SerialMessenger()
{
    _partialMessage = "";
    _endMarker = '#';
    _partialMessage.reserve(200);
}

void SerialMessenger::Setup()
{
    Serial.println("Serial control initialised.");
}

char SerialMessenger::GetEndMarker()
{
    return _endMarker;
}

String SerialMessenger::GetMessage()
{

    if (Serial.available())
    {
        char c = (char)Serial.read();
        if (c == _endMarker)
        {
            String completeMessage = _partialMessage;
            _partialMessage = "";
            return completeMessage;
        }
        else
            _partialMessage += c;
    }
    return String();
}
