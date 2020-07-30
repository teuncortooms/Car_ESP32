#include <Arduino.h>
#include <Wifi.h>
#include <Car.h>
#include <CarController.h>
#include <DS4Messenger.h>
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
DS4Controller _DS4Controller(_car);

void setup()
{
  Serial.begin(115200);
  _DS4Messenger.Setup(PS4_MAC);
}

void loop()
{
  String message = _DS4Messenger.GetMessage();
  _carController.Exec(message);
}
