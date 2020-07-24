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
    <!-- Bootstrap -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css" integrity="sha384-9aIt2nRpC12Uk9gS9baDl411NQApFmC26EwAOH8WgZl5MYYxFfc+NcPb1dKGj7Sk" crossorigin="anonymous">
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js" integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js" integrity="sha384-OgVRvuATP1z7JjHLkuOU7Xw704+h835Lr+6QL9UvYjZE3Ipu6Tp75j7Bh/kR0JKI" crossorigin="anonymous"></script>

    <title>Wifi Robot</title>

    <style>
        .row {
            height: 50px;
        }
    </style>
</head>



<body>
    <div class="container-fluid">
        <h1>Wifi Robot</h1>
        <div class="row">
            <div class="col-xs-12 col-sm-6">
                <div class="row">
                    <div class="col"></div>
                    <input type=button class="btn btn-primary btn-lg col" value='UP' onmousedown=location.href='/?GO_UP'>
                    <div class="col"></div>
                </div>
                <div class="row">
                    <input type=button class="btn btn-primary btn-lg col" value='LEFT' onmousedown=location.href='/?GO_LEFT'>
                    <div class="col"></div>
                    <input type=button class="btn btn-primary btn-lg col" value='RIGHT' onmousedown=location.href='/?GO_RIGHT'>
                </div>
                <div class="row">
                    <div class="col"></div>
                    <input type=button class="btn btn-primary btn-lg col" value='DOWN' onmousedown=location.href='/?GO_DOWN'>
                    <div class="col"></div>
                </div>
            </div>
            <div class="col-12 col-sm-6">
                <div class="row"></div>
                <div class="row">
                    <div class="col-1"></div>
                    <input type=button class="btn btn-primary btn-lg col-10" value='STOP' onmousedown=location.href='/?STOP'>
                    <div class="col-1"></div>
                </div>
                <div class="row"></div>
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
