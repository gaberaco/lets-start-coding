/*
 * Bowser's theme song
 * Send 3 rising tones to a speaker
 * and blink lights
 */

void setup(){
  pinMode(A5,OUTPUT); //Set up your speaker on pin A5 & the other pin in GND
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
} 

void loop(){

  tone(A5,300); //Send a tone of 250 hertz     
  digitalWrite(12,HIGH);
  delay(100);
  digitalWrite(12,LOW);
  noTone(A5);
  delay(100);

  tone(A5,310); //Send a tone of 250 hertz     
  digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);
  noTone(A5);
  delay(100);

  tone(A5,320); //Send a tone of 250 hertz     
  digitalWrite(12,HIGH);
  delay(100);
  digitalWrite(12,LOW);
  noTone(A5);
  delay(100);
 
  tone(A5,310); //Send a tone of 250 hertz
  digitalWrite(13,HIGH);
  delay(100);
  digitalWrite(13,LOW);
  noTone(A5);
  delay(100);
}


  


// (c) 2018 Let's Start Coding. License: www.letsstartcoding.com/bsdlicense
