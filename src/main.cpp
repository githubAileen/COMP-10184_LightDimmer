#include <Arduino.h>
// I Aileen Velasco, 000805966 certify that this material is my original work. 
//No other person's work has been used without due acknowledgement. 
//I have not made my work available to anyone else.

//Global variables
int iButton = 0; 
int buttonLED = 1;
boolean buttonPressed = false;
int iVal = 0;
 
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
  // read the push button input... 
  iButton = digitalRead(D5); 
  // read the analog input
  iVal = analogRead(A0);
  
  // Check if button is pressed
  if (iButton == 0 ){
    // If pressed toggle boolean buttonPressed
    buttonPressed = buttonPressed ? false : true;
  }


  // Check the state of the buttonPressed
  if(buttonPressed){
    //If button is pressed, toggle the LED light
    buttonLED = buttonLED ? 0 : 1;

    //Check if light is on or off
    if(buttonLED == 1){
      //If light is on, display dimmer
      analogWrite(D4, iVal);
    } else {
      //Else, turn off the light
      digitalWrite(D4, 1);
    }
  }

  // Debounce logic ...
  delay(1); 
} 