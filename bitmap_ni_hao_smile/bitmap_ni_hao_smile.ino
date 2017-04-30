#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

static const uint8_t PROGMEM
  smile_bmp[] =
  { B00111100,
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100 
  };

const unsigned char ni [] PROGMEM = {
  0x02, 0x40, 0x04, 0xfe, 0x09, 0x04, 0x14, 0x20, 0x04, 0xa8, 0x04, 0xa8, 0x05, 0x24, 0x04, 0x20, 
  0x04, 0xe0, 
};

const unsigned char hao [] PROGMEM = {
  0x08, 0x00, 0x10, 0xf8, 0x7e, 0x10, 0x22, 0x20, 0x44, 0x20, 0x29, 0xfc, 0x10, 0x20, 0x28, 0xa0, 
  0x44, 0x60, 
};


void setup() {
  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  Serial.println("ISSI manual animation test");
  if (! matrix.begin()) {
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 Found!");
  
}


void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  String sensorValString = String(voltage);
  Serial.println(sensorValString);
  matrix.clear();
  matrix.drawBitmap(-1, 0, ni, 16, 9, 50);
  delay(900);
  matrix.clear();
  matrix.drawBitmap(1, 0, hao, 16, 9, 50);
  delay(900);
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(50);
  for (int8_t x=0; x>=-96; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(" me llamo Carlos");
    delay(70);
  }
  delay(100);
  matrix.clear();
  matrix.drawBitmap(4, 0, smile_bmp, 8, 9, 100);
  delay(1300);
  Serial.println("Loop complete!");
}
