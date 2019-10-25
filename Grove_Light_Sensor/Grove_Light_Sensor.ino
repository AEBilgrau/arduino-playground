// Demo for Grove - Starter Kit V2.0
//
// Uses the Grove - Light Sensor to measure the ambient light, and turns on the Grove - LED
// when the value drops below a certain threshold.
// In a bright room, try covering the Grove - Light Sensor with your hand.
// Connect the Grove - Light Sensor to the socket marked A2
// Connect the Grove - LED to D3

// Defines the pins to which the light sensor and LED are connected.
const int pinLight = A2;
const int pinLed   = 3;

// Defines the light-sensor threshold value below which the LED will turn on.
// Decrease this value to make the device more sensitive to ambient light, or vice-versa.
int thresholdvalue = 200;

void setup()
{
      // Configure the serial communication line at 9600 baud (bits per second.)
    Serial.begin(9600);
    
    // Configure the LED's pin for output signals.
    pinMode(pinLed, OUTPUT);
}

void loop()
{
    // Read the value of the light sensor. The light sensor is an analog sensor.
    int sensorValue = analogRead(pinLight);
    Serial.println(sensorValue);

    // Turn the LED on if the sensor value is below the threshold.
    if(sensorValue > thresholdvalue)
    {
        digitalWrite(pinLed, HIGH);
    }
    else
    {
        digitalWrite(pinLed, LOW);
    }
    delay(100);
}
