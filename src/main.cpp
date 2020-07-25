#include <Arduino.h>
#include <Wifi.h>
#include <WifiPrinter.h>
#include <Car.h>
#include <CarController.h>
#include <WebMessenger.h>
#include "config.h"

Car _car(
    CAR_LEFT_ACCELERATEPIN,
    CAR_LEFT_REVERSEPIN,
    CAR_LEFT_SPEEDPIN,
    CAR_LEFT_SPEEDCHANNEL,
    CAR_RIGHT_ACCELERATEPIN,
    CAR_RIGHT_REVERSEPIN,
    CAR_RIGHT_SPEEDPIN,
    CAR_RIGHT_SPEEDCHANNEL);
CarController _carController(_car);
WifiPrinter _wifiPrinter;
WebMessenger _webMessenger(_car);

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  _wifiPrinter.printStatus();

  _webMessenger.Setup();
}

void loop()
{
  String message = _webMessenger.GetMessage();
  _carController.Exec(message);
}
