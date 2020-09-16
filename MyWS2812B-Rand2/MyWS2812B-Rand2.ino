#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 30

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 5
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

const int dly = 10;
int i;

const float pi = 3.1415;

float rnorm(float mean = 0, float sd = 1) {
  float U = random(1e6)/(1e6-1);
  float V = random(1e6)/(1e6-1);

  return mean + sd*sqrt(-2*log(U))*cos(2*pi*V);
}

float dnorm(float x, float mean = 0, float sd = 1) {
  return 1/sqrt(2*pi*sq(sd))*exp(-1/(2*pi*sq(sd))*sq(x - mean));
}


void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
  Serial.begin(9600);
  
  randomSeed(analogRead(A5));
}

  // Pick a color
  int H = random(255);
  int S = 255;

void loop() { 

  int pot_raw = analogRead(A0);
  int pot = map(pot_raw, 0, 1023, NUM_LEDS, 0);
  //pot = constrain(pot, 0, 30);
  
  // Pick mean
  float sd = 1.0;
 
//  int int_norm = int(rnorm(pot, sd));
//  int rand_mean = constrain(int_norm, 0, 30);
  Serial.println(pot);

  for (int x=0; x < NUM_LEDS; x++) {
    H++;
    float dens = dnorm(x, pot, sd);
    int V = int(255*dens);
    CRGB color = CHSV(H, S, V);
    Serial.print(H);
    Serial.print(" ");
    
    leds[x] = color;
  }
  FastLED.show();
  delay(dly);
  Serial.println("\\");
//  i = random(30);
//  leds[i] = CRGB::Black;
//  FastLED.show();
//  delay(dly);


}
