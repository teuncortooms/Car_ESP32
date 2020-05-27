#include <Arduino.h>
#include <CarController.cpp>
#include <WifiMessenger.cpp>
#include <WifiPrinter.cpp>
#include "WiFi.h"

const char *ssid = "Teun";
const char *password = "jezes666";

CarController _carController;
WifiMessenger _wifiMessenger;
WifiPrinter _wifiPrinter;

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    _wifiPrinter.printConnecting(ssid);
  }
  _wifiPrinter.printSuccess();
  _wifiPrinter.printStatus();
  _wifiMessenger.Setup();
}

void loop()
{
  String message = _wifiMessenger.GetMessage();
  if (message != "")
    Serial.println(message);
  _carController.Enforce(message);
}
