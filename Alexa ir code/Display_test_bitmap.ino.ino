#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


const unsigned char PROGMEM BMP_DEMO[] =
{ 0xFF, 0xFE, 0x80, 0x02, 0xA0, 0x03, 0xA0, 0x03, 0xA0, 0x03, 0xA0, 0x03, 0x80, 0x02, 0xFF, 0xFE };



void setup()   {                
  Serial.begin(9600);
  
  display.begin(SSD1306_SWITCHCAPVCC);
  
   

  // miniature bitmap display
  display.clearDisplay();
  display.drawBitmap(0, 0,  BMP_DEMO, 16, 8, 1);
  display.display();


}


void loop() {
  
}
