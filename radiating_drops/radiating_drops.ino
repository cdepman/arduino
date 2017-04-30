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

void drawDrop(){
  matrix.fillCircle(xCoord, yCoord, 0, 100);  
  delay(100);
  matrix.fillCircle(xCoord, yCoord, 1, 90); 
  matrix.fillCircle(xCoord, yCoord, 0, 0);
  delay(90);
  matrix.drawCircle(xCoord, yCoord, 2, 80);
  matrix.fillCircle(xCoord, yCoord, 1, 0);
  delay(80);
  matrix.drawCircle(xCoord, yCoord, 3, 70);
  matrix.fillCircle(xCoord, yCoord, 2, 0);
  delay(70);
  matrix.drawCircle(xCoord, yCoord, 4, 60);
  matrix.fillCircle(xCoord, yCoord, 3, 0);
  delay(60);
  matrix.drawCircle(xCoord, yCoord, 5, 50); 
  matrix.fillCircle(xCoord, yCoord, 4, 0);
  delay(50);
  matrix.drawCircle(xCoord, yCoord, 6, 40);
  matrix.fillCircle(xCoord, yCoord, 5, 0);
  delay(40);
  matrix.drawCircle(xCoord, yCoord, 7, 30);
  matrix.fillCircle(xCoord, yCoord, 6, 0);
  delay(30);
  matrix.drawCircle(xCoord, yCoord, 8, 20);
  matrix.fillCircle(xCoord, yCoord, 7, 0);
  delay(20);
}

void generateNewXYCoords(){
  xCoord = random(0,16);
  yCoord = random(0,8);
}

void loop() {
  matrix.clear();
  drawDrop();
  generateNewXYCoords();
}


