#ifndef WifiPrinter_h
#define WifiPrinter_h

#include <Arduino.h>
#include "WiFi.h"

class WifiPrinter
{
public:
    void printConnecting(String ssid);
    void printSuccess();
    void printStatus();
};

#endif