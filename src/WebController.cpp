#include "WebController.h"

WebController::WebController(Car &car) : _server(80), _car(car)
{
    // issue: initializing _server takes 20% of Flash memory space
}

void WebController::Setup()
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

void WebController::configureRoutes()
{
    _server.on("/", HTTP_GET, [this](AsyncWebServerRequest *request) {
        sendIndex(request);
    });

    _server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/style.css", "text/css");
    });

    _server.on("/GO_UP", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _car.GoUp();
        sendIndex(request);
    });

    _server.on("/GO_DOWN", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _car.GoDown();
        sendIndex(request);
    });

    _server.on("/GO_LEFT", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _car.GoLeft();
        sendIndex(request);
    });

    _server.on("/GO_RIGHT", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _car.GoRight();
        sendIndex(request);
    });

    _server.on("/STOP", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _car.Stop();
        sendIndex(request);
    });

    _server.on("/SLOWDOWN", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _car.AdjustSpeed(-10);
        sendIndex(request);
    });

    _server.on("/SPEEDUP", HTTP_GET, [this](AsyncWebServerRequest *request) {
        _car.AdjustSpeed(10);
        sendIndex(request);
    });
}

void WebController::sendIndex(AsyncWebServerRequest *request)
{
    request->send(SPIFFS, "/index.html", "text/html", false,
                  // last argument must be this lambda function and cannot be simply processPlaceholders
                  // because it is a method and not a local function (?)
                  [this](const String &var) -> String { return this->processPlaceholders(var); });
}

String WebController::processPlaceholders(const String &var)
{
    if (var == "SPEED")
    {
        return String(_car.GetSpeed());
    }
    return String();
}
