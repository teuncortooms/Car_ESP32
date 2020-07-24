#ifndef SerialMessenger_h
#define SerialMessenger_h

#include <Arduino.h>

class SerialMessenger
{
    String _inputString;
    bool _stringComplete;
    char _endMarker;

public:
    SerialMessenger();
    void Setup();
    char GetEndMarker();
    String GetMessage();

private:
    void getInput();
    String handleInput();
};


#endif