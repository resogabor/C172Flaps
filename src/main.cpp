#include <Arduino.h>
#include <Joystick.h>

byte flaps0 = 23;
byte flaps10 = 22;
byte flaps20 = 21;
byte flaps30 = 20;




Joystick_ joy(0x21, 0x04, 4, 0, false, false, false, false, false, false, false, false, false, false, false);
void setup() {
  joy.begin();
  pinMode (flaps0, INPUT_PULLUP); 
  pinMode (flaps10, INPUT_PULLUP); 
  pinMode (flaps20, INPUT_PULLUP); 
  pinMode (flaps30, INPUT_PULLUP); 
}

void loop() {
  if(!digitalRead(flaps0)){
    joy.setButton(0, 1);
  }else{
    joy.setButton(0, 0);
  }

  if(!digitalRead(flaps10)){
    joy.setButton(1, 1);
  }else{
    joy.setButton(1, 0);
  }

  if(!digitalRead(flaps20)){
    joy.setButton(2, 1);
  }else{
    joy.setButton(2, 0);
  }

  if(!digitalRead(flaps30)){
    joy.setButton(3, 1);
  }else{
    joy.setButton(3, 0);
  }
}

