#include <Arduino.h>
#include <SerialSoldier.cpp>

SerialSoldier soldier(2, 4, 2, 2);

void setup()
{
}

void loop()
{
  soldier.FollowOrders();
}
