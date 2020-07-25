#include <Arduino.h>
#include <Wifi.h>
#include <Car.h>
#include <CarController.h>
#include <SerialMessenger.h>
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
SerialMessenger _serialMessenger;

void setup()
{
  Serial.begin(115200);
  _serialMessenger.Setup();
}

void loop()
{
  String message = _serialMessenger.GetMessage();
  _carController.Exec(message);
}
