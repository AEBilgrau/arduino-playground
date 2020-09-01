/* https://www.makerguides.com/max7219-led-dot-matrix-display-arduino-tutorial/ */
/* Basic example code for MAX7219 LED dot matrix display with Arduino. More info: https://www.makerguides.com */
// Include the required Arduino libraries:
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   13  // or SCK
//#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

// Create a new instance of the MD_Parola class with hardware SPI connection:
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  // Intialize the object:
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(0);
  // Clear the display:
  myDisplay.displayClear();
}
void loop() {
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.print("Maria");
  delay(2000);
  
  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("er");
  delay(2000);
  
  myDisplay.setTextAlignment(PA_RIGHT);
  myDisplay.print("mega");
  delay(2000);
  
  myDisplay.setTextAlignment(PA_CENTER);
  myDisplay.setInvert(true);
  myDisplay.print("HOT!!!");
  delay(2000);
  
  myDisplay.setInvert(false);
  //myDisplay.print(1234);
  //delay(2000);

  myDisplay.displayClear();
  delay(2000);

  myDisplay.displayText("Scrolling text", PA_CENTER, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}
