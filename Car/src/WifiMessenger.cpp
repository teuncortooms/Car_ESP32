#include <Arduino.h>
#include "WiFi.h"

class WifiMessenger
{
    WiFiServer _server;
    WiFiClient _client;
    String _message;
    bool _messageIsComplete;
    char _endMarker;

public:
    WifiMessenger() : _server(80)
    {
        _message = "";
        _messageIsComplete = false;
        _endMarker = '\n';
    }

    void Setup()
    {
        _message.reserve(200);
        _server.begin();
    }

    String GetMessage()
    {
        getInput();
        return handleInput();
    }

private:
    void getInput()
    {
        delay(500);
        if (_client)
        {
            // Serial.println("h");
            if (_client.connected())
            {
                // Serial.println("a");
                if (_client.available())
                {
                    // Serial.println("l");
                    char c = (char)_client.read();
                    if (c == _endMarker)
                    {
                        // Serial.println("o");
                        _messageIsComplete = true;
                        sendNewPage();
                        _client.stop();
                    }
                    else
                    {
                        // Serial.println("u");
                        _message += c;
                    }
                }
            }
            else
            {
                // Serial.println("q");
                _client = _server.available();
            }
        }
    }

    String handleInput()
    {
        if (_messageIsComplete)
        {
            String returnvalue = _message;
            _message = "";
            _messageIsComplete = false;
            return returnvalue;
        }
        else
            return "";
    }

    void sendNewPage()
    {
        _client.println("HTTP/1.1 200 OK");
        _client.println("Content-Type: text/html");
        _client.println("Connection: close"); // the connection will be closed after completion of the response
        //_client.println("Refresh: 5");  // refresh the page automatically every 5 sec
        _client.println();
        _client.println("<!DOCTYPE HTML>");
        _client.println("<head><title>WiFi Robot</title></head>");
        _client.println("<center><hr/><p> Click the Buttons to move the robot <p/><hr/></center>");
        _client.println("<center><input type=button value='GO UP' onmousedown=location.href='/?GO_UP'></center><br/>");
        _client.println("<center><input type=button value='GO LEFT' onmousedown=location.href='/?GO_LEFT'><input type=button value='GO RIGHT' onmousedown=location.href='/?GO_RIGHT'></center><br/>");
        _client.println("<center><input type=button value='GO DOWN' onmousedown=location.href='/?GO_DOWN'></center><br/><br/>");
        _client.println("<hr/>");
        _client.println("</body>");
        _client.println("</html>");
    }
};