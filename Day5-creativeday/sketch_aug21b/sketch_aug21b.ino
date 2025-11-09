//day 5 idea one: only allow one light at a time

#include "Arduino.h"  // include information about our HERO

//inputs
const byte CABIN_LIGHTS_PIN = 10; //pin controlling cabin lights
const byte STORAGE_LIGHTS_PIN = 11; //pin controlling storage lights
const byte COCKPIT_LIGHTS_PIN = 12; //pin controlling exterior lights

//outputs
const byte CABIN_LIGHTS_SWITCH_PIN = 2; //cabin lights controlled by switch 1
const byte STORAGE_LIGHTS_SWITCH_PIN = 3; //storage lights controlled by switch 2
const byte COCKPIT_LIGHTS_SWITCH_PIN = 4; //exterior lights controlled by switch 3


void setup() {
  //Configure our LED pins as OUTPUT pins
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
  pinMode(STORAGE_LIGHTS_PIN, OUTPUT);
  pinMode(COCKPIT_LIGHTS_PIN, OUTPUT);

  //Configure our switch pins as INPUT pins
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(STORAGE_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(COCKPIT_LIGHTS_SWITCH_PIN, INPUT);

}

void loop() {
  // Control exterior lights based on setting on switch 1
  if (digitalRead(CABIN_LIGHTS_SWITCH_PIN) == HIGH) {  
    digitalWrite(COCKPIT_LIGHTS_PIN, LOW);              
    digitalWrite(STORAGE_LIGHTS_PIN, LOW);  
    digitalWrite(CABIN_LIGHTS_PIN, HIGH);  
  // Control exterior lights based on setting on switch 2
  } else if (digitalRead(STORAGE_LIGHTS_SWITCH_PIN) == HIGH) {  
    digitalWrite(COCKPIT_LIGHTS_PIN, LOW);              
    digitalWrite(STORAGE_LIGHTS_PIN, HIGH);  
    digitalWrite(CABIN_LIGHTS_PIN, LOW);  
  // Control exterior lights based on setting on switch 3
  } else if (digitalRead(COCKPIT_LIGHTS_SWITCH_PIN) == HIGH) {  
    digitalWrite(COCKPIT_LIGHTS_PIN, HIGH);              
    digitalWrite(STORAGE_LIGHTS_PIN, LOW);  
    digitalWrite(CABIN_LIGHTS_PIN, LOW);  
  } else {
    digitalWrite(COCKPIT_LIGHTS_PIN, LOW);              
    digitalWrite(STORAGE_LIGHTS_PIN, LOW);  
    digitalWrite(CABIN_LIGHTS_PIN, LOW);  
  }
  


}
