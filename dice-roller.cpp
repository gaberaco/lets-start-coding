/*
 * Press a button to 'roll a die' and get the outcome in blinks.
 * Placing loops inside loops is called 'nesting'.
 */

// License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>
// Copyright (c) 2020 Gabriel Raco <gaberaco@gmail.com>

// Change dice range if you want
void setup() {
  pinMode(11, OUTPUT);  // LED
  pinMode(A5, INPUT_PULLUP);  // button
  pinMode(A1, OUTPUT);
}
int pitch = 40;
int roll;

void loop() {
  // While the button is held down, 'roll the dice' by flickering the LED
  while (digitalRead(A5) == LOW) {
    tone(A1, pitch);
    pitch = random(40, 1000);
    digitalWrite(11, HIGH);
    delay(50);
    digitalWrite(11, LOW);
    delay(50);

    if (digitalRead(A5) == HIGH) {  // if the button is released
      noTone(A1);
      delay(500);
      // choose a random number 1-6 and blink the LED that number of times
      roll = random(1, 7);          // this generates between 1 and 6, not 7
      for (int blinks = 1; blinks <= roll; blinks++) {
        digitalWrite(11, HIGH);
        if (blinks == roll) {
           tone(A1, 600);
           delay(500);
        } else {
           tone(A1, 400);
           delay(230);
        }
        digitalWrite(11, LOW);
        noTone(A1);
        delay(230);
      }  // close the 'for' loop
    }    // close the 'if' statement
  }      // close the 'while' loop
}
