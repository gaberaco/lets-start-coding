/*
 * Use a button to cycle through three LEDs or a multi-color LED.
 * Hold down the button to strobe!
 */

// License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>
// Copyright (c) 2020 Gabriel Raco <gaberaco@gmail.com>

int pressCount = 0;     // How many times the button has been pressed.

void setup() {
  pinMode(9, OUTPUT);  // Set up your LED pins as outputs
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(A5, INPUT_PULLUP);  // button
  // digitalWrite(10, HIGH);
}


void loop() {
  // If the button is pressed, increase the counter variable by 1
  if (digitalRead(A5) == LOW) {
    pressCount++;
    // Delay before next button press is sensed. Lower delay = faster strobe
    delay(250);
  }
  // Use the pressCount to determine which light is on.
  if (pressCount == 1) {
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);      // turn off the light on pin 10 and...
    digitalWrite(11, HIGH);  // blue     // turn on the light on pin 11
  } else if (pressCount == 2) {
    digitalWrite(11, LOW);
    digitalWrite(9, HIGH);  // red
  } else if (pressCount == 3) {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);  // green
  // No matter how many LEDs you add, the last "if" sets pressCount to 0
  } else if (pressCount == 4) {
    digitalWrite(9, HIGH);      // turn off the light on pin 10 and...
    digitalWrite(11, HIGH);     // turn on the light on pin 11
    digitalWrite(10, LOW);
  } else if (pressCount == 5) {
    digitalWrite(11, LOW);     // turn on the light on pin 11
    digitalWrite(10, HIGH);
  } else if (pressCount == 6) {
    digitalWrite(9, LOW);      // turn off the light on pin 10 and...
    digitalWrite(11, HIGH);     // turn on the light on pin 11
  } else if (pressCount == 7) {
    digitalWrite(9, HIGH);      // turn off the light on pin 10 and...
    digitalWrite(11, HIGH);     // turn on the light on pin 11
    digitalWrite(10, HIGH);
    pressCount = 0;
  }
}
