#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

char* ssid = "SSID";
char* password = "pass";

#define OLED_SDA 2
#define OLED_SCL 0

WiFiServer server(80);

void setup() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  server.begin();
  Wire.begin(0,2);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.setTextColor(WHITE);
  display.println(WiFi.localIP().toString());
  display.display();
  delay(5000);
  display.clearDisplay();
  display.display();
}

void loop() {
  // Check for incoming connections
  WiFiClient client = server.available();
  if(client){
  while (client){
    // Print the client's IP address
    // Read the data
    String data = client.readStringUntil('_');
    if(data != ""){
    client.println("received data: "+data);
    client.print("> ");
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0,0);
    display.setTextColor(WHITE);
    display.print(data);
    display.display();
    }}
   client.stop();
    }}
