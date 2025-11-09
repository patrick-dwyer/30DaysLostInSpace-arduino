//three lights only now, make more lights
//make dip switch into binary counter that can turn on 6 lights (1, 2, 6/7)
//0 to 2^(n-1)

#include "Arduino.h"  // include information about our HERO
#include <math.h>
#include <stdio.h>

//inputs
const byte ALIEN_LIGHTS_PIN = 7; //pin controlling bedroom lights
const byte BEDROOM_LIGHTS_PIN = 8; //pin controlling bedroom lights
const byte BATHROOM_LIGHTS_PIN = 9; //pin controlling bathroom lights
const byte CABIN_LIGHTS_PIN = 10; //pin controlling cabin lights
const byte STORAGE_LIGHTS_PIN = 11; //pin controlling storage lights
const byte COCKPIT_LIGHTS_PIN = 12; //pin controlling exterior lights


//outputs
const byte CABIN_LIGHTS_SWITCH_PIN = 2; //cabin lights controlled by switch 1
const byte STORAGE_LIGHTS_SWITCH_PIN = 3; //storage lights controlled by switch 2
const byte COCKPIT_LIGHTS_SWITCH_PIN = 4; //exterior lights controlled by switch 3

void setup() {
  //Configure our LED pins as OUTPUT pins
  pinMode(BEDROOM_LIGHTS_PIN, OUTPUT);
  pinMode(BATHROOM_LIGHTS_PIN, OUTPUT);
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
  pinMode(STORAGE_LIGHTS_PIN, OUTPUT);
  pinMode(COCKPIT_LIGHTS_PIN, OUTPUT);
  pinMode(ALIEN_LIGHTS_PIN, OUTPUT);

  //Configure our switch pins as INPUT pins
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(STORAGE_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(COCKPIT_LIGHTS_SWITCH_PIN, INPUT);

}

void loop() {
  int switch_count = digitalRead(CABIN_LIGHTS_SWITCH_PIN) + digitalRead(STORAGE_LIGHTS_SWITCH_PIN) + digitalRead(COCKPIT_LIGHTS_SWITCH_PIN);
  int binary_count = 1 << (switch_count-1);

  // Turn on all lights if all switches on
  if (binary_count <= 0) {  
    digitalWrite(COCKPIT_LIGHTS_PIN, 0);              
    digitalWrite(STORAGE_LIGHTS_PIN, 0);  
    digitalWrite(CABIN_LIGHTS_PIN, 0);
    digitalWrite(BATHROOM_LIGHTS_PIN, 0);
    digitalWrite(BEDROOM_LIGHTS_PIN, 0);
    digitalWrite(ALIEN_LIGHTS_PIN, 0);



  } else if (binary_count == 1) {
    digitalWrite(COCKPIT_LIGHTS_PIN, 0);              
    digitalWrite(STORAGE_LIGHTS_PIN, 0);  
    digitalWrite(CABIN_LIGHTS_PIN, 0);
    digitalWrite(BATHROOM_LIGHTS_PIN, 0);
    digitalWrite(BEDROOM_LIGHTS_PIN, 0);
    digitalWrite(ALIEN_LIGHTS_PIN, 1);

  } else if (binary_count == 2) {
    // do 2 lights
    digitalWrite(COCKPIT_LIGHTS_PIN, 0);              
    digitalWrite(STORAGE_LIGHTS_PIN, 1);  
    digitalWrite(CABIN_LIGHTS_PIN, 0);
    digitalWrite(BATHROOM_LIGHTS_PIN, 1);
    digitalWrite(BEDROOM_LIGHTS_PIN, 0);
    digitalWrite(ALIEN_LIGHTS_PIN, 0);
  
  } else if (binary_count == 4){
    //do all lights
    digitalWrite(COCKPIT_LIGHTS_PIN, 1);              
    digitalWrite(STORAGE_LIGHTS_PIN, 0);  
    digitalWrite(CABIN_LIGHTS_PIN, 1);
    digitalWrite(BATHROOM_LIGHTS_PIN, 0);
    digitalWrite(BEDROOM_LIGHTS_PIN, 1);
    digitalWrite(ALIEN_LIGHTS_PIN, 1);

  } else {
    digitalWrite(COCKPIT_LIGHTS_PIN, 0);              
    digitalWrite(STORAGE_LIGHTS_PIN, 0);  
    digitalWrite(CABIN_LIGHTS_PIN, 0);
    digitalWrite(BATHROOM_LIGHTS_PIN, 0);
    digitalWrite(BEDROOM_LIGHTS_PIN, 0);
    digitalWrite(ALIEN_LIGHTS_PIN, 0);
  }
  
  
}
