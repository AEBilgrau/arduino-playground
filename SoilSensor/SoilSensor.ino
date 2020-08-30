#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

//#include <dht.h>
//dht DHT;
//#define dht11_pin 7

int sensor_pin = A0; 
int soil_moisture_raw;
int soil_moisture_pct;
int llod=1020; // lower limit of detection

int relay_pin=8;
int relay_lower_threshold_pct=60;
int relay_upper_threshold_pct=90;

//int air_temperature;
//int air_humidity;

void setup() {
  pinMode(relay_pin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);

  dht.begin();
}

void loop() {
  delay(2000);

  //DHT.read11(dht11_pin);

  // Read, compute and print moisture
  soil_moisture_raw= analogRead(sensor_pin);
  soil_moisture_pct = min(100, max(0, map(soil_moisture_raw, llod, 0, 0, 100)));
  //air_temperature = DHT.temperature;
  //air_humidity = DHT.humidity;

  float air_humidity = dht.readHumidity();
  float air_temperature = dht.readTemperature(false); //isFahrenheit = false
  float hic = dht.computeHeatIndex(air_temperature, air_humidity, false);


  Serial.print("Raw: ");
  Serial.print(soil_moisture_raw);
  Serial.print(" - Soil Mositure: ");
  Serial.print(soil_moisture_pct);
  Serial.print("%");
  Serial.print(" - Air temp.: ");
  Serial.print(air_temperature);
  Serial.print(" C");
  Serial.print(" - Air RH: ");
  Serial.print(air_humidity);
  Serial.print("%");
  Serial.print(" - HIC: ");
  Serial.print(hic);
  Serial.print(" C");
  
  // Set relay based on miosture
  if (soil_moisture_pct < relay_lower_threshold_pct) {
    digitalWrite(relay_pin, HIGH);
    Serial.println(" - soil too dry, water needed!");
  } else if (soil_moisture_pct > relay_upper_threshold_pct) {
    digitalWrite(relay_pin, LOW);
    Serial.println(" - soil too wet, stop watering, stupid farmerboi!");
  } else {
    digitalWrite(relay_pin, LOW);
    Serial.println(" - soil OK");
  }

 }
