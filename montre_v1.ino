#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16




#include <SoftwareSerial.h>

char message;

SoftwareSerial mySerial(0, 1); // (RX, TX) (pin Rx BT, pin Tx BT)

void setup()
{
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();

  display.setTextSize(2);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);
  display.println("Hello");
  display.println("world!");
  display.display();
  delay(3000);
  display.clearDisplay();
  //pixel();
  //display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();



  mySerial.begin(9600);
  String message;

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() // run over and over
{
  if (mySerial.available()) {
    message = (mySerial.read());
    if (message == 'A') {
      digitalWrite(LED_BUILTIN, HIGH);
      display.clearDisplay();
      display.setTextSize(2);      // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE); // Draw white text
      display.setCursor(0, 0);
      display.println("A");
      display.display();

    }
    if (message == 'B') {
      digitalWrite(LED_BUILTIN, LOW);
      display.clearDisplay();
      display.setTextSize(2);      // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE); // Draw white text
      display.setCursor(0, 0);
      display.println("B");
      display.display();
    }
    if (message == 'C') {
      display.clearDisplay();
      display.setTextSize(2);      // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE); // Draw white text
      display.setCursor(0, 0);
      display.println("C");
      display.display();
    }
    if (message == 'D') {
      display.clearDisplay();
      display.setTextSize(2);      // Normal 1:1 pixel scale
      display.setTextColor(SSD1306_WHITE); // Draw white text
      display.setCursor(0, 0);
      display.println("D");
      display.display();
    }
    if (message == '/') {
      String messageString = "";
      messageString = (mySerial.readString());
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(messageString);
      display.display();
    }
    if (message == '$') {
      String imageString = "";
      char[] imageTab;
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println("attendre  svp...");
      display.display();
      imageString = (mySerial.readString());
      //imageString.toCharArray(imageTab, len)
      const unsigned String myBitmap [] PROGMEM = {imageString};
      //const unsigned char myBitmap [] PROGMEM = {imageString};
      display.clearDisplay()
      display.drawBitmap(0,0,myBitmap,128,64,WHITE);
      display.display();
    }
    if (message == 'T') {
      String messageString = "";
      messageString = (mySerial.readString());
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(SSD1306_WHITE);
      display.setCursor(0, 0);
      display.println(messageString);
      display.display();
    }
  }
}




void pixel()
{
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.display();
}
