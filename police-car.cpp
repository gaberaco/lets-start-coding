/*
 * Play a tone ascending, then descending, on a speaker using 'for' loops
 */

void setup() {
  pinMode(A5, OUTPUT); //speaker
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

  //starting at 40, increase pitch by 1 until it equals 1999
  for (int pitch = 40; pitch < 2000; pitch++) {
    tone(A5, pitch); //play the pitch
    //delay(1);
    digitalWrite(12, HIGH);
    digitalWrite(10, LOW);
  }
  //starting at 2000, decrease pitch by 1 until it equals 41
  for (int pitch = 2000; pitch > 40; pitch--) {
    tone(A5, pitch); //play the pitch
    //delay(1);
    digitalWrite(10, HIGH);
    digitalWrite(12, LOW);

  }
}

// (c) 2017 Let's Start Coding. License: www.letsstartcoding.com/bsdlicense
