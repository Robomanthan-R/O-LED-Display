#include <SoftwareSerial.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET    -1
Adafruit_SSD1306 display(OLED_RESET);
const int rxPin = 2; 
const int txPin = 3; 
SoftwareSerial bluetooth(rxPin, txPin);
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  bluetooth.begin(9600);
}
void loop() {
  if (bluetooth.available()) {
    char receivedChar = bluetooth.read();
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(receivedChar);
    display.display();
  }
}

