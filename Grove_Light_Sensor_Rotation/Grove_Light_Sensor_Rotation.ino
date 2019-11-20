const int pinLight = A2;


void setup()
{
     // Configure the serial communication line at 9600 baud (bits per second.)
    Serial.begin(9600);
}

void loop()
{
    // Read the value of the light sensor. The light sensor is an analog sensor.
    int sensorValue = analogRead(pinLight);
    Serial.println(sensorValue);

    delay(100);
}
