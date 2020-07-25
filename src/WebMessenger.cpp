#include "WebMessenger.h"

WebMessenger::WebMessenger(Car &car) : _server(80), _car(car)
{
}

void WebMessenger::Setup()
{
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
    configureRoutes();
    _server.begin();
    Serial.println("Wifi control initialised.");
}

void WebMessenger::configureRoutes()
{
    _server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request) {
        sendIndex(request);
    });

    _server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/style.css", "text/css");
    });

    _server.on("/?GO_UP", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _messageQueue.push("Up");
        sendIndex(request);
    });

    _server.on("/?GO_DOWN", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _messageQueue.push("Down");
        sendIndex(request);
    });

    _server.on("/?GO_LEFT", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _messageQueue.push("Left");
        sendIndex(request);
    });

    _server.on("/?GO_RIGHT", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _messageQueue.push("Right");
        sendIndex(request);
    });

    _server.on("/?STOP", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _messageQueue.push("Stop");
        sendIndex(request);
    });
}

void WebMessenger::sendIndex(AsyncWebServerRequest *request)
{
    request->send(SPIFFS, "/index.html", "text/html", false,
                  // last argument must be this lambda function and cannot be simply processor
                  // because it is a method and not a local function (?)
                  [this](const String &var) -> String { return this->processPlaceholders(var); });
}

String WebMessenger::processPlaceholders(const String &var)
{
    if (var == "SPEED")
    {
        return String(_car.GetSpeed());
    }
    return String();
}

String WebMessenger::GetMessage()
{
    return _messageQueue.shift();
}