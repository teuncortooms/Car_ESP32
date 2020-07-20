#include <Arduino.h>
#include <CarController.h>
#include <WifiMessenger.h>
#include <WifiPrinter.h>
#include "WiFi.h"
#include "config.h"

const char *ssid = WIFI_SSID;
const char *password = WIFI_PASSWORD;

CarController _carController(CAR_ACCELERATELEFT, CAR_REVERSELEFT, CAR_ACCELERATERIGHT, CAR_REVERSERIGHT);
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
  {
    _carController.Exec(message);
  }
}
