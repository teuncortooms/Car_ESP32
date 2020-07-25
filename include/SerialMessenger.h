#ifndef SerialMessenger_h
#define SerialMessenger_h

#include <Arduino.h>

class SerialMessenger
{
    String _partialMessage;
    char _endMarker;

public:
    SerialMessenger();
    void Setup();
    char GetEndMarker();
    String GetMessage();
};

#endif