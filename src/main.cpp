#include <Arduino.h>
// I Aileen Velasco, 000805966 certify that this material is my original work. 
//No other person's work has been used without due acknowledgement. 
//I have not made my work available to anyone else.

int iButton = 0; 
int buttonLED = 1;
boolean buttonPressed = false;
int iVal = 0;
 
  // read the push button input... 
  
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 

  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
  // set default PWM range 
  analogWriteRange(1023); 

} 
 
void loop() { 
  iButton = digitalRead(D5); 
  iVal = analogRead(A0);
  
  if (iButton == 0 ){
    buttonPressed = buttonPressed ? false : true;
  }

  if(buttonPressed){
    buttonLED = buttonLED ? 0 : 1;
    if(buttonLED == 1){
      analogWrite(D4, iVal);
    } else {
      digitalWrite(D4, 1);
    }
  }

  delay(1); 
} 