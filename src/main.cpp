#include <Arduino.h>
#include <Wifi.h>
#include <WifiPrinter.h>
#include <Car.h>
#include <WebController.h>
#include "config.h"

Car _car(
    CAR_LEFT_ACCELERATEPIN,
    CAR_LEFT_REVERSEPIN,
    CAR_LEFT_SPEEDPIN,
    CAR_LEFT_SPEEDCHANNEL,
    CAR_RIGHT_ACCELERATEPIN,
    CAR_RIGHT_REVERSEPIN,
    CAR_RIGHT_SPEEDPIN,
    CAR_RIGHT_SPEEDCHANNEL,
    CAR_MINSPEED,
    CAR_MAXSPEED);
WebController _webController(_car);

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  PrintWifiStatus();

  _webController.Setup();
}

void loop()
{
}
