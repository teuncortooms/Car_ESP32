#ifndef WifiMessenger_h
#define WifiMessenger_h

#include <Arduino.h>
#include "WiFi.h"

class WifiMessenger
{
    WiFiServer _server;
    WiFiClient _client;
    String _message;
    bool _messageIsComplete;
    char _endMarker;

public:
    WifiMessenger();
    void Setup();
    String GetMessage();

private:
    void getInput();
    void sendNewPage();
    String handleInput();
};



#endif