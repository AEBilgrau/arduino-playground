// Pull in LCD headers
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

// Define the pin to which the temperature sensor is connected.
const int pinTemp = A0;

// Define the B-value of the thermistor.
// This value is a property of the thermistor used in the Grove - Temperature Sensor,
// and used to convert from the analog value it measures and a temperature value.
const int B = 3975;

float temperature;
float resistance;

// Defines the pin to which the LED is connected.
// Any pin that supports PWM can also be used:
// 3, 5, 6, 9, 10, 11
const int pinLed    = 3;
const int minT = 16;
const int maxT = 24;

void setup()
{ 
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(0, 0, 0);
    
    // Print a message to the LCD.
    lcd.print("Temperature:");

    // Turn on cursor blinking
    lcd.blink();
    
    delay(1000);
    
    // Configure the serial communication line at 9600 baud (bits per second.)
    Serial.begin(9600);

    // Configure the LED's pin for output signals.
    pinMode(pinLed, OUTPUT);
    
}

void loop()
{
    // Get the (raw) value of the temperature sensor.
    int val = analogRead(pinTemp);

    // Determine the current resistance of the thermistor based on the sensor value.
    resistance = (float)(1023-val)*10000/val; 

    // Calculate the temperature based on the resistance value.
    temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15; 

    // Print the temperature to the serial console.
    Serial.println(temperature);

    // Print to the LCD
    lcd.setCursor(0, 1);
    lcd.print(temperature);

    analogWrite(pinLed, min(255, max(0, (int) 255*(temperature - minT)/(maxT - minT) + minT)));
 
    // Set LCD backligt color based on temp
    if (temperature > 25) {
      lcd.setRGB(255, 0, 0);
    }
    else if (temperature < 20) {
      lcd.setRGB(0, 0, 255);
    }
    else {
      lcd.setRGB(125, 255, 0);
    }

    // Wait one tenth of a second between measurements.
    delay(10);
}
