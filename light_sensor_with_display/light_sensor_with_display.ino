#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};

const int LIGHT_THRESHOLD = 500;
int sensorValue;
bool isLight;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  Serial.println("ISSI manual animation test");
  if (! matrix.begin()) {
    Serial.println("IS31 not found");
    while (1);
  }
  Serial.println("IS31 Found!");
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(50);
}


void loop() {
  sensorValue = analogRead(A0);
  isLight = (sensorValue > LIGHT_THRESHOLD) ? true : false;
  String displayValue = isLight ? "light!" : "dark!";
  Serial.println(String(sensorValue));
  for (int8_t x = 0; x >= -42; x--) {
    sensorValue = analogRead(A0);
    if (sensorValue > LIGHT_THRESHOLD != isLight){
      isLight = false;
      for (uint8_t incr = 0; incr < 2; incr++)
        for (uint8_t x = 0; x < 16; x++)
          for (uint8_t y = 0; y < 9; y++)
            matrix.drawPixel(x, y, sweep[(x+y+incr)%24]);
      break;
    }
    matrix.clear();
    matrix.setCursor(x, 0);
    matrix.print(" " + displayValue);      
    delay(50);
  }
  delay(120);
}

