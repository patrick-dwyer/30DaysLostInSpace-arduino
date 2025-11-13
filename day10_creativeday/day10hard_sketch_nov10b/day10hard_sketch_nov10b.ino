// RGB LED pins
const byte RED_PIN = 13;
const byte GREEN_PIN = 12;
const byte BLUE_PIN = 11;

// Photoresistor on analog pin
const byte PHOTORESISTOR_PIN = A0;

// DIP switch pins
const byte DIP1 = 2;

//display color for RBG LED settings, 0-255
void displayColor(byte red_intensity, byte green_intensity, byte blue_intensity){
  analogWrite(RED_PIN, red_intensity);
  analogWrite(GREEN_PIN, green_intensity);
  analogWrite(BLUE_PIN, blue_intensity);
}

void setup() {
  // Declare RGB LED pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Declare DIP switch as input
  pinMode(DIP1, INPUT);

  // Start serial monitor
  Serial.begin(9600);

}

void loop() {
  
  // Read analog and add to battery level
  short light_value = analogRead(PHOTORESISTOR_PIN);

  // Print photoresistor value for debugging
  Serial.println(analogRead(PHOTORESISTOR_PIN));
  delay(100);

  int switchState = digitalRead(DIP1);

  // Conditional: low light, light on. High light, light off.
  if (light_value < 30){
    displayColor(255, 255, 255);
  }
  else if (switchState == HIGH) {
    displayColor(255, 0, 0);
    Serial.println("DIP is on.");
  }
  else {
    displayColor(0, 0, 0);
  }



}
