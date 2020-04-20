/*
 * Tune a multicolor LED's colors with buttons
 * The analogWrite() function works on digital pins 3,5,6,9,10,11.
 */

int brightness1; //holds the brightness of the outputs. Range is 0-255
int brightness2;
int brightness3;

//function that takes in the pin number and changes brightness on that pin
void changeBrightness(int _pin, int _brightness){          //'pass in' a pin number to the function
  analogWrite(_pin, _brightness);                          //write 'brightness' to the pin you passed in.
}

void setup(){
  //Set all LEDS to output
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  //one button per LED color
  pinMode(A5, INPUT_PULLUP); 
  pinMode(A1, INPUT_PULLUP); 
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}
void loop(){
  /* 
   * When a button is held down, pass the corresponding LED pin number
   * to the function over and over again
   */
  if(digitalRead(A5) == LOW){
     brightness1++;                                           //increase the brightness variable by one
     changeBrightness(9, brightness1); //pass the LED pin number to the function
     if(brightness1 == 255){                                   //reset brightness to 0 if it reaches max (255)
        brightness1 = 0;
     }
  }      
  else if(digitalRead(A1) == LOW){ 
     brightness2++;                                           //increase the brightness variable by one
     changeBrightness(10, brightness2);
     if(brightness2 == 255){                                   //reset brightness to 0 if it reaches max (255)
        brightness2 = 0;
     }
  } 
  else if(digitalRead(2) == LOW){ 
     brightness3++;                                           //increase the brightness variable by one
     changeBrightness(11, brightness3);
     if(brightness3 == 255){                                   //reset brightness to 0 if it reaches max (255)
        brightness3 = 0;
     }
  }
  else if (digitalRead(4) == LOW){
    brightness1 = 0;
    brightness2 = 0;
    brightness3 = 0;
    changeBrightness(9, brightness1); //pass the LED pin number to the function
    changeBrightness(10, brightness2);
    changeBrightness(11, brightness3);
  }
  
  delay(10); //Speed of fade while button is LOW. Longer delay = slower fade
}
