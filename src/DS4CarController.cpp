#include "DS4CarController.h"

DS4CarController::DS4CarController(Car &car)
    : _car(car)
{
    threshold = 10;
}

void DS4CarController::Setup(char ps4Mac[18])
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

        if (PS4.event.button_down.l1)
        {
            _car.AdjustSpeed(-1);
            Serial.println(_car.GetSpeed());
        }
        if (PS4.event.button_down.r1)
        {
            _car.AdjustSpeed(1);
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

        if (PS4.data.status.charging)
            Serial.println("The controller is charging");
        if (PS4.data.status.audio)
            Serial.println("The controller has headphones attached");
        if (PS4.data.status.mic)
            Serial.println("The controller has a mic attached");

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
    else if (analogSticksMoved())
        handleAnalogSticks();
    else if (L2OrR2Moved())
        handleL2andR2();
    else
        _car.Stop();

    // if (PS4.data.button.upleft)
    //     Serial.println("Up Left");
    // // _car.GoUpLeft();
    // if (PS4.data.button.upright)
    //     Serial.println("Up Right");
    // // _car.GoUpRight();
    // if (PS4.data.button.downleft)
    //     Serial.println("Down Left");
    // if (PS4.data.button.downright)
    //     Serial.println("Down Right");
}

bool DS4CarController::analogSticksMoved()
{
    return abs(PS4.data.analog.stick.ly) >= threshold ||
           abs(PS4.data.analog.stick.ry) >= threshold;
}

void DS4CarController::handleAnalogSticks()
{
    handleAnalogInput(LEFT, PS4.data.analog.stick.ly);
    handleAnalogInput(RIGHT, PS4.data.analog.stick.ry);
}

bool DS4CarController::L2OrR2Moved()
{
    return PS4.data.button.l2 || PS4.data.button.r2;
}

void DS4CarController::handleL2andR2()
{
    handleAnalogInput(LEFT, PS4.data.analog.button.l2);
    handleAnalogInput(RIGHT, PS4.data.analog.button.r2);
}

void DS4CarController::handleAnalogInput(Side side, int coord)
{
    if (abs(coord) > threshold)
    {
        int speed = convertCoordToSpeed(coord);
        _car.DriveMotor(side, speed);
    }
}

int DS4CarController::convertCoordToSpeed(int coord)
{
    if (abs(coord) < threshold)
        return 0;

    int minCoord = threshold;
    int maxCoord = (coord > 0) ? 127 : 128;
    int speed = map(abs(coord), minCoord, maxCoord, _car.GetMinSpeed(), _car.GetMaxSpeed());
    return (coord > 0) ? speed : -speed;
}