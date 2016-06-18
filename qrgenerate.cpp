#include <Arduino.h>
#include "qrencode.h"
#include <Wire.h>
#include "SSD1306.h"

// Initialize the OLED display using Wire library
SSD1306 display(0x3c, 4, 5);

int offsetsX = 42;
int offsetsY = 10;
int screenwidth = 128;
int screenheight = 64;

void qrsetup(){
	display.init();
    display.flipScreenVertically();
	Serial.println("inti...");
	display.setColor(WHITE);
	Serial.println("inti...");
}

void qrrender(int x, int y, int color){
  x=x+offsetsX;
  y=y+offsetsY;
  if(color==1) {
	display.setColor(BLACK);
    display.setPixel(x, y);
  }
  else {
	display.setColor(WHITE);
    display.setPixel(x, y);
  }
}

void qrscreenwhite(){
	display.clear();
	display.setColor(WHITE);
	display.fillRect(0, 0, screenwidth, screenheight);
	display.display();
}

void qrcreate(String message) {
	
  // create QR code
  message.toCharArray((char *)strinbuf,260);
  qrencode();
  qrscreenwhite();
  // print QR Code
  for (byte x = 0; x < WD; x+=2) {
    for (byte y = 0; y < WD; y++) {
      if ( QRBIT(x,y) &&  QRBIT((x+1),y)) { 
        // black square on top of black square
        Serial.print("8");
        qrrender(x, y, 1);
        qrrender((x+1), y, 1);
      }  
      if (!QRBIT(x,y) &&  QRBIT((x+1),y)) { 
        // white square on top of black square
        Serial.print(" ");
        qrrender(x, y, 0);
        qrrender((x+1), y, 1);
      }  
      if ( QRBIT(x,y) && !QRBIT((x+1),y)) { 
        // black square on top of white square
        Serial.print("8");
        qrrender(x, y, 1);
        qrrender((x+1), y, 0);
      }  
      if (!QRBIT(x,y) && !QRBIT((x+1),y)) { 
        // white square on top of white square
        Serial.print(" "); 
        qrrender(x, y, 0);
        qrrender((x+1), y, 0);
      }  
    }
    Serial.println(); 
  }
  Serial.println(); 
  display.display();
}
