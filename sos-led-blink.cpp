/*
 * Blink - makes a single LED blink on and off
 */

void setup() {
  pinMode(13, OUTPUT); // pin 13 - change value if you have LED on diff pin
}

void loop() {

  // S
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(500);             // wait 500 milliseconds, or half second.

  // O
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(500);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(500);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(500);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(500);             // wait 500 milliseconds, or half second.

  // S
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, HIGH);  // set pin 13 to high voltage, turning LED on
  delay(100);             // wait 500 milliseconds, or half second.
  digitalWrite(13, LOW);   // set pin 13 to low voltage, or zero. LED off.
  delay(1000);             // wait 1000 milliseconds, or one second.

}

// (c) 2018 Let's Start Coding. License: www.letsstartcoding.com/bsdlicense
