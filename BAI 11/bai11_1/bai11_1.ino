#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "DHSP-A8-WIFI-2G";
const char* password = "11101951";

WebServer server(80);
const int ledPin = 2;

void handleRoot() {
  String html = "<html><head><meta charset='UTF-8'></head><body>";
  html += "<h1>Hệ thống bật / tắt Led – WebServer cấu hình cơ bản</h1>";
  html += "<h1>Nguyễn Thành Luân - 745114054</h1>";
  html += "<a href='/on'><button style='width:100px;height:50px'>ON</button></a>";
  html += "<a href='/off'><button style='width:100px;height:50px'>OFF</button></a>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleOff() {
  digitalWrite(ledPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
}

void loop() {
  server.handleClient();
}