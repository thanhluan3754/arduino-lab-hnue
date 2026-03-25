#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "DHSP-A8-WIFI-2G";
const char* password = "11101951";

WebServer server(80);
const int led1 = 2;
const int led2 = 4;

void handleRoot() {
  String html = "<html><head><meta charset='UTF-8'></head><body>";
  html += "<h1>Hệ thống bật / tắt 2 Led – WebServer cấu hình cơ bản</h1>";

  html += "<h3>LED 1</h3>";
  html += "<a href='/led1'><button style='width:80px;height:40px'>";
  html += (digitalRead(led1) ? "BAT" : "TAT");
  html += "</button></a>";

  html += "<h3>LED 2</h3>";
  html += "<a href='/led2'><button style='width:80px;height:40px'>";
  html += (digitalRead(led2) ? "BAT" : "TAT");
  html += "</button></a>";

  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleLed1() {
  digitalWrite(led1, !digitalRead(led1));
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLed2() {
  digitalWrite(led2, !digitalRead(led2));
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/led1", handleLed1);
  server.on("/led2", handleLed2);
  server.begin();
}

void loop() {
  server.handleClient();
}