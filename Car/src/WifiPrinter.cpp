#include "WifiPrinter.h"

void WifiPrinter::printConnecting(String ssid)
{
    Serial.print("Connecting to SSID: ");
    Serial.println(ssid);
}

void WifiPrinter::printSuccess()
{
    Serial.println("Connected to the WiFi network");
}

void WifiPrinter::printStatus()
{
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}
