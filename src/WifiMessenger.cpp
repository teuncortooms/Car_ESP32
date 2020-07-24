#include "WifiMessenger.h"

WifiMessenger::WifiMessenger() : _server(80)
{
    _message = "";
    _messageIsComplete = false;
    _endMarker = '\n';
}

void WifiMessenger::Setup()
{
    _message.reserve(200);
    _server.begin();
    Serial.println("Wifi control initialised.");
}

String WifiMessenger::GetMessage()
{
    getInputFromHtmlPage();
    return handleInput();
}

void WifiMessenger::getInputFromHtmlPage()
{
    if (!_client)
    {
        _client = _server.available();
    }
    else
    {
        if (_client.connected())
        {
            if (_client.available())
            {
                char c = _client.read();
                if (c == _endMarker)
                {
                    _messageIsComplete = true;
                    sendHtmlPage();
                    _client.stop();
                }
                else
                {
                    _message += c;
                }
            }
        }
    }
}

void WifiMessenger::sendHtmlPage()
{
    String htmlPage = R"HTMLPAGE(
            <!DOCTYPE HTML>
            <html>
            <head>
                <meta http-equiv="content-type" content="text/html;charset=UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1">
                <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
                <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
                <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
                <title>Wifi Robot</title>
            </head>

            <body>
                <div class="container">
                    <h1>Wifi Robot</h1>
                    <div class="row">
                        <div class="col-xs-12">
                            <input type=button class="btn btn-default btn-lg btn-block" value='UP' onmousedown=location.href='/?GO_UP'>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-xs-6">
                            <input type=button class="btn btn-default btn-lg btn-block" value='LEFT' onmousedown=location.href='/?GO_LEFT'>
                        </div>
                        <div class="col-xs-6">
                            <input type=button class="btn btn-default btn-lg btn-block" value='RIGHT' onmousedown=location.href='/?GO_RIGHT'>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-xs-12">
                            <input type=button class="btn btn-default btn-lg btn-block" value='DOWN' onmousedown=location.href='/?GO_DOWN'>
                        </div>
                    </div>
                    <div class="row">
                        <div class="col-xs-12">
                            <br/>
                            <input type=button class="btn btn-default btn-lg btn-block" value='STOP' onmousedown=location.href='/?STOP'>
                        </div>
                    </div>
                </div>
            </body>
            </html>
        )HTMLPAGE";

    // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
    // and a content-type so the client knows what's coming, then a blank line:
    _client.println("HTTP/1.1 200 OK");
    _client.println("Content-Type: text/html");
    _client.println("Connection: close");
    _client.println();
    _client.print(htmlPage);
}

String WifiMessenger::handleInput()
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
