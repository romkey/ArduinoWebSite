#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP.h>

#include <BootstrapWebSite.h>
#include <BootstrapWebPage.h>

const char* ssid = "YOUR WIFI SSID";
const char* password = "YOUR WIFI PASSWORD";

ESP8266WebServer server(80);
BootstrapWebSite ws("en");

const char *branding_image_base64 = "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==";

unsigned long startTime;

void setup() {
  startTime = millis();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("derp");
  }

  ws.branding_image_type = String("image/jpeg");
  ws.branding_image_base64 = String(branding_image_base64);

  ws.addPageToNav(String("Info"), String("/info"));
  ws.addPageToNav(String("ESP"), String("/esp"));

  server.on("/info", handleInfo);
  server.on("/esp", handleESP);

  server.onNotFound(handleNotFound);

  server.begin();
}

void loop() {
  server.handleClient();
}

void handleInfo() {
  BootstrapWebPage page(&ws);

  page.addHeading(String("Info"));
  page.addList(String("Uptime ") + String((millis() - startTime) / 1000) + String(" seconds"),
	       String("IP address ") + String(WiFi.localIP().toString()),
	       String("Hostname ") + String(WiFi.hostname()),
	       String("MAC address ") + WiFi.macAddress(),
	       String("Subnet mask ") + WiFi.subnetMask().toString(),
	       String("router IP ") + WiFi.gatewayIP().toString(),
	       String("first DNS server ") + WiFi.dnsIP(0).toString(),
	       String("SSID ") + WiFi.SSID(),
	       String("RSSi ") + WiFi.RSSI());
	 
  server.send(200, "text/html", page.getHTML());
}

void handleESP() {
  BootstrapWebPage page(&ws);

  page.addHeading(1, String("ESP"));
  page.addList(String("VCC ") + ESP.getVcc(),
               String("Free heap ") + ESP.getFreeHeap(),
               String("Chip ID ") + ESP.getChipId() ,
               String("Flash chip ID ") + ESP.getFlashChipId(),
               String("Flash chip size ") + ESP.getFlashChipSize(),
               String("Flash chip speed ") + ESP.getFlashChipSpeed(),
               String("Sketch Size ") + ESP.getSketchSize(),
               String("Free Sketch Space ") + ESP.getFreeSketchSpace());

  server.send(200, "text/html", page.getHTML());
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

