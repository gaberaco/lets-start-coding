/*
 * Button held on pin A5 turns LED attached to pin 11 on
 */

void setup(){ 
  pinMode(10, OUTPUT);  //LED pin
  pinMode(13, OUTPUT);  //LED pin
  pinMode(A5, INPUT_PULLUP); //pushbutton pin    
}

void loop(){
  //if the pushbutton is pressed, hold the LED on
  if (digitalRead(A5) == LOW){ 
    delay(250);
    if (digitalRead(10) == HIGH){
      digitalWrite(10, LOW);
    }
    else {
        digitalWrite(10, HIGH);
    }
  }
}
// (c) 2018 Let's Start Coding. License: www.letsstartcoding.com/bsdlicense
