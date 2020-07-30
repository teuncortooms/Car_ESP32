#include "DS4CarController.h"

DS4CarController::DS4CarController(Car &car)
    : _car(car)
{
    analogStickThreshold = 10;
}

void DS4CarController::Setup(char *ps4Mac)
{
    PS4.begin(ps4Mac);
    Serial.print("DS4 control initialized for ");
    Serial.println(ps4Mac);
}

void DS4CarController::WaitForController()
{
    while (!PS4.isConnected())
    {
        Serial.println("Looking for controller...");
        delay(1000);
    }
}

void DS4CarController::HandleInput()
{
    if (PS4.isConnected())
    {
        handleMovement();

        if (PS4.data.button.triangle)
            Serial.println("Triangle Button");
        if (PS4.data.button.circle)
            Serial.println("Circle Button");
        if (PS4.data.button.cross)
            Serial.println("Cross Button");
        if (PS4.data.button.square)
            _car.Stop();

        if (PS4.data.button.l1)
        {
            // TODO: add millis check, to gradually process input
            _car.AdjustSpeed(-1);
            Serial.println(_car.GetSpeed());
        }
        if (PS4.data.button.r1)
        {
            _car.AdjustSpeed(10);
            Serial.println(_car.GetSpeed());
        }

        if (PS4.data.button.l3)
            Serial.println("l3 Button");
        if (PS4.data.button.r3)
            Serial.println("r3 Button");

        if (PS4.data.button.share)
            Serial.println("Share Button");
        if (PS4.data.button.options)
            Serial.println("Options Button");

        if (PS4.data.button.ps)
            Serial.println("PS Button");
        if (PS4.data.button.touchpad)
            Serial.println("Touch Pad Button");

        if (PS4.data.button.l2)
        {
            Serial.print("l2 button at ");
            Serial.println(PS4.data.analog.button.l2, DEC);
        }
        if (PS4.data.button.r2)
        {
            Serial.print("r2 button at ");
            Serial.println(PS4.data.analog.button.r2, DEC);
        }

        // if (PS4.event.analog_move.stick.lx)
        // {
        //     Serial.print("Left Stick x at ");
        //     Serial.println(PS4.data.analog.stick.lx);
        // }

        // if (PS4.event.analog_move.stick.rx)
        // {
        //     Serial.print("Right Stick x at ");
        //     Serial.println(PS4.data.analog.stick.rx, DEC);
        // }

        if (PS4.data.status.charging)
            Serial.println("The Messenger is charging");
        if (PS4.data.status.audio)
            Serial.println("The Messenger has headphones attached");
        if (PS4.data.status.mic)
            Serial.println("The Messenger has a mic attached");

        // Serial.print("Battery Percent : ");
        // Serial.println(PS4.data.status.battery, DEC);

        // Serial.println();
        // This delay is to make the Serial Print more human readable
        // Remove it when you're not trying to see the output
        // delay(1000);
    }
}

void DS4CarController::handleMovement()
{
    if (PS4.data.button.up)
        _car.GoUp();
    else if (PS4.data.button.down)
        _car.GoDown();
    else if (PS4.data.button.left)
        _car.GoLeft();
    else if (PS4.data.button.right)
        _car.GoRight();
    else if (PS4.data.button.upleft)
        Serial.println("Up Left");
    else if (PS4.data.button.upright)
        Serial.println("Up Right");
    else if (PS4.data.button.downleft)
        Serial.println("Down Left");
    else if (PS4.data.button.downright)
        Serial.println("Down Right");
    else if (eitherAnalogStickIsMoved())
    {
        Serial.println("handling sticks!");
        handleAnalogSticks();
    }
    else
    {
        _car.Stop();
    }
}

bool DS4CarController::eitherAnalogStickIsMoved()
{
    return (abs(PS4.event.analog_move.stick.lx) > analogStickThreshold ||
            abs(PS4.event.analog_move.stick.ly) > analogStickThreshold ||
            abs(PS4.event.analog_move.stick.rx) > analogStickThreshold ||
            abs(PS4.event.analog_move.stick.ry) > analogStickThreshold);
}

void DS4CarController::handleAnalogSticks()
{
    if (abs(PS4.event.analog_move.stick.ly) > analogStickThreshold)
        handleAnalogStickY(PS4.event.analog_move.stick.ly, "Left");
    if (abs(PS4.event.analog_move.stick.ry) > analogStickThreshold)
        handleAnalogStickY(PS4.event.analog_move.stick.ry, "Right");
}

void DS4CarController::handleAnalogStickY(int coord, String side)
{
    int minCoord = 0;
    int maxCoord = 127;
    int speed = map(abs(coord), minCoord, maxCoord, _car.GetMinSpeed(), _car.GetMaxSpeed());
    Serial.println(speed);
    if (coord > analogStickThreshold)
        activateMotor(side, "Up", speed);
    if (coord < -analogStickThreshold)
        activateMotor(side, "Down", speed);
}

void DS4CarController::activateMotor(String side, String direction, int speed)
{
    if (side == "Left" && direction == "Up")
        _car.LeftMotorUp(speed);
    if (side == "Left" && direction == "Down")
        _car.LeftMotorDown(speed);
    if (side == "Right" && direction == "Up")
        _car.RightMotorUp(speed);
    if (side == "Right" && direction == "Down")
        _car.RightMotorDown(speed);
}