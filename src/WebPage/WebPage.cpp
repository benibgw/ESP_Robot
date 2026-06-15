#include "WebPage.h"

WebPageClass::WebPageClass(char* ssid, char* password){
  SSID = ssid;
  PASSWORD = password;
}

String WebPageClass::GetPage(){
  return R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">
  <style>
    * { touch-action: none; user-select: none; -webkit-user-select: none; }
    body { background: #1a1a1a; display: flex; justify-content: center; align-items: center; min-height: 100vh; margin: 0; }
    .dpad { display: grid; grid-template-columns: 80px 80px 80px; gap: 6px; }
    .dpad button {
      width: 80px; height: 80px; font-size: 28px; border: none; border-radius: 12px;
      background: #333; color: #fff; cursor: pointer; -webkit-tap-highlight-color: transparent;
    }
    .dpad button:active { background: #555; }
    .dpad .blank { visibility: hidden; }
  </style>
</head>
<body>
  <div class="dpad">
    <div class="blank"></div>
    <button ontouchstart="p('F')" ontouchend="r('F')" onmousedown="p('F')" onmouseup="r('F')">&#9650;</button>
    <div class="blank"></div>
    <button ontouchstart="p('L')" ontouchend="r('L')" onmousedown="p('L')" onmouseup="r('L')">&#9668;</button>
    <button ontouchstart="p('S')" ontouchend="r('S')" onmousedown="p('S')" onmouseup="r('S')" style="background:#c0392b;">&#9632;</button>
    <button ontouchstart="p('R')" ontouchend="r('R')" onmousedown="p('R')" onmouseup="r('R')">&#9658;</button>
    <div class="blank"></div>
    <button ontouchstart="p('B')" ontouchend="r('B')" onmousedown="p('B')" onmouseup="r('B')">&#9660;</button>
    <div class="blank"></div>
  </div>

  <script>
    let s = {};
    function p(d) { s[d] = true; send(); }
    function r(d) { delete s[d]; send(); }

    function send() {
      let cmd = 'STOP';
      if(s.F && s.L) cmd = 'FORWARD_LEFT';
      else if(s.F && s.R) cmd = 'FORWARD_RIGHT';
      else if(s.B && s.L) cmd = 'BACKWARD_LEFT';
      else if(s.B && s.R) cmd = 'BACKWARD_RIGHT';
      else if(s.F) cmd = 'FORWARD';
      else if(s.B) cmd = 'BACKWARD';
      else if(s.L) cmd = 'LEFT';
      else if(s.R) cmd = 'RIGHT';
      fetch('/move?dir=' + cmd);
    }
  </script>
</body>
</html>
)rawliteral";
}

void WebPageClass::begin(){
  WiFi.softAP(SSID, PASSWORD);
  MDSN.begin("Robo_CTISMART")

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

WebPageClass WebPage("Robo_CTISMART", "Abacaxi123");
