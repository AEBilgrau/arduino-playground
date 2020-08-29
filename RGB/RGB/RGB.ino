int redPin= 9; // PWM!
int greenPin = 6;
int bluePin = 5;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void setWhite() {
  setColor(255, 255, 255);
}

void loop() {
  setColor(0, 255, 255);
  /*
  setColor(255, 0, 0); // Red Color
  delay(1000);
  setColor(0, 255, 0); // Green Color
  delay(1000);
  setColor(0, 0, 255); // Blue Color
  delay(1000);
  setWhite(); // White Color
  delay(1000);
  setColor(155, 155, 155);
  delay(1000);
  setColor(55, 55, 55);
  delay(1000);
  setColor(5, 5, 5);
  delay(1000);
  setColor(170, 0, 255); // Purple Color
  delay(1000);
  */
/* 
  for (int i = 0; i <= 255; i++) {
    for (int j = 0; j <= 255; j++) {
      for (int k = 0; k <= 255; k++) {
        setColor(i, j, k);
        delay(1);
      } 
    }
  }
  */
}
