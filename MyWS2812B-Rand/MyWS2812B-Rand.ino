include <FastLED.h>

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
  return 1/sqrt(2*pi*sq(sd))*exp(1/(2*pi*sq(sd))*sq(x - mean));
}


void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
  Serial.begin(9600);
  
  randomSeed(analogRead(A5));
}



void loop() { 

  int pot =  map(analogRead(A0), 0, 1023, 0, NUM_LEDS);
//  Serial.println(pot);


  // Turn the LED on, then pause
  /*
  for (int i=0; i < NUM_LED; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(dly);
  }
  for (int i=NUM_LED; i >= 0; i--) {
     // Now turn the LED off, then pause
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(dly);
  }

  */

  /*
  i = random(30);
  //leds[i] = CRGB::Blue;
  leds[i] = CHSV(random(255), random(255), random(255));
  FastLED.show();
  delay(dly);

  i = random(30);
  leds[i] = CRGB::Black;
  FastLED.show();
  delay(dly);

  */

  // Pick a color
  CRGB color = CHSV(random(255), random(255), random(255));


//dnorm(, 15, 5)
  int j = int(rnorm(pot, 2));
  int i = constrain(j, 0, 30);
  Serial.println(i);


  leds[i] = color;
  FastLED.show();
  delay(dly);

  i = random(30);
  leds[i] = CRGB::Black;
  FastLED.show();
  delay(dly);


}
