#include "WebPage.h"

WebPageClass::WebPageClass(char* ssid, char* password){
  SSID = ssid;
  PASSWORD = password;
}

String WebPageClass::GetPage(){
  return R"rawliteral()rawliteral"; //Adicionar HTML funcional.
}

void WebPageClass::begin(){
  WiFi.softAP(SSID, PASSWORD);

  server.on("/", [this](){
    server.send(200, "text/html", GetPage());
  });

  server.on("/move", [this](){
    if(server.hasArg("dir")){
      currentCommand = server.arg("dir");
    }
    server.send(200, "text/plain", "OK");
  });

  server.onNotFound([this](){
    server.send(404, "text/plain", "Not Found");
  });

  server.begin();
}

void WebPageClass::update(){
  server.handleClient();
}

String WebPageClass::query(){
  return currentCommand;
}
