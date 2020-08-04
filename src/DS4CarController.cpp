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
    if (PS4.data.button.down)
        _car.GoDown();
    if (PS4.data.button.left)
        _car.GoLeft();
    if (PS4.data.button.right)
        _car.GoRight();
    if (PS4.data.button.upleft)
        Serial.println("Up Left");
    // _car.GoUpLeft();
    if (PS4.data.button.upright)
        Serial.println("Up Right");
    // _car.GoUpRight();
    if (PS4.data.button.downleft)
        Serial.println("Down Left");
    if (PS4.data.button.downright)
        Serial.println("Down Right");

    // handleStick("Left", PS4.data.analog.stick.ly);
    // handleStick("Right", PS4.data.analog.stick.ry);

    if (noMovementButtonsPressed())
        _car.Stop();
}

void DS4CarController::handleStick(String side, int coord)
{
    bool isBelowThreshold = abs(coord) < analogStickThreshold;
    bool &wasBelowThreshold = (side == "Left") ? wasLYBelowThreshold : wasRYBelowThreshold;
    // to make sure it doesn't continually break when trying to drive with arrow keys
    if (isBelowThreshold && !wasBelowThreshold)
    {
        driveMotor(side, 0);
        wasBelowThreshold = true;
    }
    else if (!isBelowThreshold)
    {
        driveMotor(side, coord);
        wasBelowThreshold = false;
    }
}

void DS4CarController::driveMotor(String side, int coords)
{
    int speed = convertCoordToSpeed(coords);
    _car.DriveMotor(side, speed);
}

int DS4CarController::convertCoordToSpeed(int coord)
{
    if (abs(coord) < analogStickThreshold)
        return 0;

    int minCoord = analogStickThreshold;
    int maxCoord = (coord > 0) ? 127 : 128;
    int speed = map(abs(coord), minCoord, maxCoord, _car.GetMinSpeed(), _car.GetMaxSpeed());
    return (coord > 0) ? speed : -speed;
}

bool DS4CarController::noMovementButtonsPressed()
{
    return (!PS4.data.button.up &&
            !PS4.data.button.down &&
            !PS4.data.button.left &&
            !PS4.data.button.right &&
            !PS4.data.button.upleft &&
            !PS4.data.button.upright &&
            !PS4.data.button.downleft &&
            !PS4.data.button.downright &&
            abs(PS4.data.analog.stick.ly) < analogStickThreshold &&
            abs(PS4.data.analog.stick.ry) < analogStickThreshold);
}
