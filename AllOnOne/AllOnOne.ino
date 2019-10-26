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
const int pinLed = 3;
const int minT = 16;
const int maxT = 24;

// Define the pin to which the angle sensor is connected.
const int potentiometer = A1;

// Defines the pins to which the light sensor and LED are connected.
const int pinLight = A2;

// Defines the light-sensor threshold value below which the LED will turn on.
// Decrease this value to make the device more sensitive to ambient light, or vice-versa.
int thresholdvalue = 200;


// Define the pins to which the button and relay are attached.
const int buttonPin = 4;
const int relayPin =  8;

void setup()
{ 
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(0, 0, 0);
    
    // Print a message to the LCD.
    lcd.print("Temp: ");
    lcd.setCursor(0,1);
    lcd.print("Light sens:");

    // Turn on cursor blinking
    //lcd.blink();
    
    delay(1000);
    
    // Configure the serial communication line at 9600 baud (bits per second.)
    Serial.begin(9600);

    // Configure the LED's pin for output signals.
    pinMode(pinLed, OUTPUT);

    // Configure the angle sensor's pin for input.
    pinMode(potentiometer, INPUT);
 
    // Configure the relay's pin for output signals.
    pinMode(relayPin, OUTPUT);

    // Configure the button's pin for input signals.
    pinMode(buttonPin, INPUT);   
}

void loop()
{
    // Get the (raw) value of the temperature sensor.
    // Read the value of the light sensor. The light sensor is an analog sensor.
    int value_temp = analogRead(pinTemp);
    int value_pot = analogRead(potentiometer);
    int value_light_sens = analogRead(pinLight);
 
    // Determine the current resistance of the thermistor based on the sensor value.
    resistance = (float)(1023-value_temp)*10000/value_temp; 

    // Calculate the temperature based on the resistance value.
    temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15; 

 

    // Print to the LCD
    lcd.setCursor(6, 0);
    lcd.print(temperature);
    lcd.setCursor(12, 1);
    lcd.print(String(value_light_sens)  + "   ");
    
    //analogWrite(pinLed, min(255, max(0, (int) 255*(temperature - minT)/(maxT - minT) + minT)));
    analogWrite(pinLed, map(value_pot, 0, 1023, 0, 255));
    
    // Set LCD backligt color based on temp
    if (temperature > 25) {
      lcd.setRGB(255, 0, 0);
    }
    else if (temperature < 20) {
      lcd.setRGB(0, 0, 255);
    }
    else {
      lcd.setRGB(125, 155, 0);
    }

    // Print the temperature and pot to the serial console.
    //Serial.println(temperature);
    //Serial.println(value_pot);
    Serial.println(value_light_sens);


    // Read the state of the button.
    int buttonState = digitalRead(buttonPin);

    // If the button is pressed, activate (close) the relay.
    if (buttonState == 1)   
    {
        digitalWrite(relayPin, HIGH);
    }
    else   
    {
        digitalWrite(relayPin, LOW);
    }
    
    // Wait one tenth of a second between measurements.
    delay(300);
}
