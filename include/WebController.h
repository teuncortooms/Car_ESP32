#ifndef WebController_h
#define WebController_h

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <Car.h>

class WebController
{
    AsyncWebServer _server;
    Car &_car;

public:
    WebController(Car &car);
    void Setup();

private:
    void configureRoutes();
    void sendIndex(AsyncWebServerRequest *request);
    String processPlaceholders(const String &var);
};

#endif