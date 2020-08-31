// #include <Arduino.h>
// #include <PS4Controller.h>

// int CAR_LEFT_ACCELERATEPIN = 23;
// int CAR_LEFT_REVERSEPIN = 22;
// int CAR_LEFT_SPEEDPIN = 25;
// int CAR_LEFT_SPEEDCHANNEL = 0;
// int CAR_RIGHT_ACCELERATEPIN = 18;
// int CAR_RIGHT_REVERSEPIN = 19;
// int CAR_RIGHT_SPEEDPIN = 26;
// int CAR_RIGHT_SPEEDCHANNEL = 1;
// int CAR_MINSPEED = 100;
// int CAR_MAXSPEED = 255;

// void setup()
// {
//   Serial.begin(115200);

//   pinMode(CAR_LEFT_ACCELERATEPIN, OUTPUT);
//   pinMode(CAR_LEFT_REVERSEPIN, OUTPUT);
//   ledcSetup(CAR_LEFT_SPEEDCHANNEL, 5000, 8);
//   ledcAttachPin(CAR_LEFT_SPEEDPIN, CAR_LEFT_SPEEDCHANNEL);
//   ledcWrite(CAR_LEFT_SPEEDCHANNEL, CAR_MAXSPEED);

//   pinMode(CAR_RIGHT_ACCELERATEPIN, OUTPUT);
//   pinMode(CAR_RIGHT_REVERSEPIN, OUTPUT);
//   ledcSetup(CAR_RIGHT_SPEEDCHANNEL, 5000, 8);
//   ledcAttachPin(CAR_RIGHT_SPEEDPIN, CAR_RIGHT_SPEEDCHANNEL);
//   ledcWrite(CAR_RIGHT_SPEEDCHANNEL, CAR_MAXSPEED);

//   PS4.begin("03:03:03:03:03:03");
//   while (!PS4.isConnected())
//   {
//     Serial.println("Looking for controller...");
//     delay(1000);
//   }
// }

// void loop()
// {
//   if (PS4.isConnected())
//   {
//     if (PS4.data.button.up)
//     {
//       digitalWrite(CAR_LEFT_ACCELERATEPIN, HIGH);
//       digitalWrite(CAR_LEFT_REVERSEPIN, LOW);
//       digitalWrite(CAR_RIGHT_ACCELERATEPIN, HIGH);
//       digitalWrite(CAR_RIGHT_REVERSEPIN, LOW);
//     }
//     else
//     {
//       digitalWrite(CAR_LEFT_ACCELERATEPIN, LOW);
//       digitalWrite(CAR_LEFT_REVERSEPIN, LOW);
//       digitalWrite(CAR_RIGHT_ACCELERATEPIN, LOW);
//       digitalWrite(CAR_RIGHT_REVERSEPIN, LOW);
//     }
//   }
// }