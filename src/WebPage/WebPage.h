#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

class WebPageClass{
  public:
    WebPageClass(char* ssid, char* password);
    String GetPage();
    void begin();
    String query();
    void update();
  private:
    WebServer server{80};
    char* SSID;
    char* PASSWORD;
    String currentCommand;
};

extern WebPageClass WebPage;
