/*
 * Play a tone on a speaker attached to pin A5 and light an LED on
 * pin 2 when buttons attached to pins 4,6,9,12 are pressed.
 */

void setup() {
  pinMode(A5, OUTPUT); //speaker
  pinMode(1, OUTPUT); //set the LED as an OUTPUT
  pinMode(2, OUTPUT); //set the LED as an OUTPUT
  pinMode(3, OUTPUT); //set the LED as an OUTPUT

  //initialize the buttons as inputs:
  pinMode(4,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
}

void loop() {
  //if a button is pressed, play the tone (in hertz) and light up the LED.
  if (digitalRead(4) == LOW) {
    tone(A5, 250);
    digitalWrite(1, HIGH);
  }
  else if (digitalRead(6) == LOW) {
    tone(A5, 350);
    digitalWrite(2, HIGH);
  }
  else if (digitalRead(9) == LOW) {
    tone(A5, 450);
    digitalWrite(3, HIGH);
  }
  else if (digitalRead(12) == LOW) {
    tone(A5, 550);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);

  }
  else {
    noTone(A5);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
}
