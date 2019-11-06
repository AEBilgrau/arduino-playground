// Pull in LCD headers
#include "rgb_lcd.h"

rgb_lcd lcd;

// Define the pin to which the sensors are connected.
const int pinTempSens  = A0;
const int pinLightSens = A1;
const int pinLed    = 2; //D2

float temperature;
float resistance;
const int B = 3975;

void setup()
{ 
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(0, 0, 0);
    
    // Print a message to the LCD.
    lcd.print("Temp: ");
    lcd.setCursor(0,1);
    lcd.print("Light sens:");

    // Configure the LED's pin for output signals.
    pinMode(pinLed, OUTPUT);
}

void loop()
{
    // Get the (raw) value of the temperature and light sensors.
    int value_temp_sens = analogRead(pinTempSens);
    int value_light_sens = analogRead(pinLightSens);
 
    // Determine the current resistance of the thermistor based on the sensor value.
    resistance = (float)(1023-value_temp_sens)*10000/value_temp_sens; 

    // Calculate the temperature based on the resistance value.
    temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15; 


    // Print to the LCD
    lcd.setCursor(6, 0);
    lcd.print(temperature);
    lcd.setCursor(12, 1);
    lcd.print(String(value_light_sens) + "   ");

    // Set LCD backligt color based on temp
    if (temperature > 25) {
      lcd.setRGB(255/3, 0, 0);
    }
    else if (temperature < 20) {
      lcd.setRGB(0, 0, 255/3);
    }
    else {
      lcd.setRGB(230/3, 190/3, 3/3);
    }

    // Wait one second between measurements.
    delay(2000);
    digitalWrite(pinLed, HIGH);
    delay(50);
    digitalWrite(pinLed, LOW);
}
