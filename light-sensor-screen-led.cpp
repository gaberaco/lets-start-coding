/*Using a Maker Screen, learn to display a sensor value with code.
 */

// include the library code:
#include "MakerScreenXVI.h"

//Create an object for the MakerScreenXVI library named 'lcd'
MakerScreenXVI lcd;

int light_reading;
int brightness;

void setup() {
  //Always type the lcd's name followed by .begin() in the void setup()
  lcd.begin(); //.begin() method 'turns on' a number of settings in the library
  pinMode(5, OUTPUT);
  pinMode(A5, INPUT_PULLUP); //Set a light sensor as an INPUT_PULLUP on A5 and GND
}

void loop() {
  light_reading = analogRead(A5);
  lcd.print("  darkness: ");
  lcd.print(light_reading); //the analogRead result is immediately printed.
  brightness = light_reading - 200;
  brightness = constrain(brightness, 0, 255); //constrain brightness between 0 and 255
  // lcd.print(" | ");
  lcd.setCursor(0,1);//set the cursor to the first column (0), second row (1)
  lcd.print("brightness: "); //the analogRead result is immediately printed.
  lcd.print(brightness); //the analogRead result is immediately printed.
  analogWrite(5, brightness);
  if (brightness > 200) {
    lcd.backlightOn();
  }
  else {
    lcd.backlightOff();
  }
  delay(125); //pause one second between prints. Change this number to see what happens.
  lcd.clear();//wipe the screen after each print. Remove this line to see the effect.
}

// Try to create a label for the reading, such as "Light Level:" on the screen

// (c) 2017 Let's Start Coding. License: www.letsstartcoding.com/bsdlicense
