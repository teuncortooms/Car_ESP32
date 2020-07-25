#ifndef DS4Messenger_h
#define DS4Messenger_h

#include <Arduino.h>
#include <PS4Controller.h>

class DS4Messenger
{

public:
    void Setup(char *ps4Mac);
    void WaitForController();
    String GetMessage();
};

#endif