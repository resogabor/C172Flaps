#include <Arduino.h>
#include <Joystick.h>

byte flaps0 = 23;
byte flaps10 = 22;
byte flaps20 = 21;
byte flaps30 = 20;
int lastButton;



Joystick_ joy(0x21, 0x04, 4, 0, false, false, false, false, false, false, false, false, false, false, false);
void setup() {
  joy.begin();
  pinMode (flaps0, INPUT_PULLUP); 
  pinMode (flaps10, INPUT_PULLUP); 
  pinMode (flaps20, INPUT_PULLUP); 
  pinMode (flaps30, INPUT_PULLUP); 
}

void setButtonState(int buttonNum){
  int diff = lastButton-buttonNum; 
  if (diff > 0){
    joy.setButton(2, 1);
    delay(100);
    joy.setButton(2, 0);        
  }
  if (diff < 0){
    joy.setButton(1, 1);
    delay(100);
    joy.setButton(1, 0);    
  }
  lastButton = buttonNum;
}

void loop() {
  if(!digitalRead(flaps0)){
    delay(20);
    if(!digitalRead(flaps0)){
        if(lastButton != 0){
        joy.setButton(0, 1);
        lastButton = 0;
      }else{
        joy.setButton(0, 0);
      }
    }
  }else{
    joy.setButton(0, 0);
  }

  if(!digitalRead(flaps10)){
    delay(20);
    if(!digitalRead(flaps10)){
      setButtonState(1);
    }
  }

  if(!digitalRead(flaps20)){
    delay(20);
    if(!digitalRead(flaps20)){
      setButtonState(2);
    }
  }

  if(!digitalRead(flaps30)){
    delay(20);
    if(!digitalRead(flaps30)){
      if (lastButton != 3){
        joy.setButton(3, 1);
        lastButton = 3;
      }else{
        joy.setButton(3, 0);
      }
    }
  }else{
    joy.setButton(3, 0);
  }
}



