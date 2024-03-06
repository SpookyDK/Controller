#include <Arduino.h>
#include <WiFi.h>
#include <AsyncUDP.h>

const char *ssid = "kage";
const char *password = "123456789";

AsyncUDP Udp;
void setup()
{
  pinMode(33, INPUT);
  pinMode(32, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Serial.println("kageeeeeeee");
  digitalWrite(13, HIGH);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("not yes");
  }
}
void loop()
{

  WiFi.config(WiFi.localIP(), WiFi.gatewayIP(), WiFi.subnetMask(), IPAddress(0, 0, 0, 0));

  Udp.connect(IPAddress(0, 0, 0, 0), 69);
  String xAxis = (String)analogRead(32);
  String yAxis = (String)analogRead(33);

  Udp.print(xAxis.substring(0,4)+ ':' + yAxis.substring(0,4));
  delay(10);
}
