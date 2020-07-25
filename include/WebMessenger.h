#ifndef WebMessenger_h
#define WebMessenger_h

#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <CircularBuffer.h>
#include <Car.h>

class WebMessenger
{
    AsyncWebServer _server;
    CircularBuffer<String, 10> _messageQueue;
    Car &_car;

public:
    WebMessenger(Car &car);
    void Setup();
    String GetMessage();

private:
    void configureRoutes();
    void sendIndex(AsyncWebServerRequest *request);
    String processPlaceholders(const String &var);
};

#endif