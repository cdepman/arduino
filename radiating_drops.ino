#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

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

int xCoord = 8;
int yCoord = 4;

void drawDrop(xCoord, yCoord){
  
}

void generateNewXYCoords(){
  xCoord = random(0,16);
  yCoord = random(0,8);
}

void loop() {
  matrix.clear();
  drawDrop(xCoord, yCoord);
  generateNewXYCoords();
}


