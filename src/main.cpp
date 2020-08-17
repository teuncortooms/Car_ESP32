#include <Arduino.h>
#include <Wifi.h>
#include <Car.h>
#include <DS4CarController.h>
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
DS4CarController _DS4CarController(_car);

void setup()
{
  Serial.begin(115200);
  _DS4CarController.Setup(PS4_MAC);
}

void loop()
{
  _DS4CarController.WaitForController();
  _DS4CarController.HandleInput();
}
