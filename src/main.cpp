#include <Arduino.h>
#include <CarController.h>
#include <Wifi.h>
#include <WifiPrinter.h>
#include <SerialMessenger.h>
#include <WifiMessenger.h>
#include <DS4Messenger.h>
#include "config.h"

CarController _carController(
    CAR_LEFT_ACCELERATEPIN,
    CAR_LEFT_REVERSEPIN,
    CAR_LEFT_SPEEDPIN,
    CAR_LEFT_SPEEDCHANNEL,
    CAR_RIGHT_ACCELERATEPIN,
    CAR_RIGHT_REVERSEPIN,
    CAR_RIGHT_SPEEDPIN,
    CAR_RIGHT_SPEEDCHANNEL);
WifiPrinter _wifiPrinter;
SerialMessenger _serialMessenger;
WifiMessenger _wifiMessenger;
DS4Messenger _DS4Messenger;

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (!WiFi.isConnected())
    ;
  _wifiPrinter.printStatus();

  _serialMessenger.Setup();
  _wifiMessenger.Setup();
  _DS4Messenger.Setup(PS4_MAC);
}

void loop()
{
  String message = _serialMessenger.GetMessage();
  if (message.isEmpty())
    message = _wifiMessenger.GetMessage();
  if (message.isEmpty())
    message = _DS4Messenger.GetMessage();

  _carController.Exec(message);
}
