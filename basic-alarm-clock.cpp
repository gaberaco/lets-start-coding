/*
 * In the last lesson, you turned a timer into a clock. Next you'll
 * add in an alarm function to that clock. The 'alarm' will  be a 
 * message displayed on the screen.
 * 
 * To add this functionality, you'll create a set of
 * variables which will hold the time that the alarm should go
 * off and a check to trigger the alarm when reaching that time.
 */
 
 
 
 
/*
 *VERY IMPORTANT : THE BUTTON ON PIN A0 IS TO STOP THE ALARM AND THE BUTTON
 *ON PIN A4 IS TO TOGGLE BACKLIGHT.  ALARM TIME AND REGUALR TIME MUST BE SET
 *IN ORDER FOR THIS AMAZING CLOCK TO WORK.  YOU CAN TOY AROUND WITH THE MESSSAGE
 *AND THE BEEPING IF YOU WANT.  THIS IS A BASIC ALARM CLOCK.  TIME SETTING WITH
 *BUTTONS COMING SOON
 */

#include "MakerScreenXVI.h"

MakerScreenXVI lcd;

int seconds = 55;//USE THIS
int minutes = 59;//AND THIS
int hours = 1;//AND THIS TO SET THE TIME.
bool AMPM = 1;//1 = pm 0 = am

long timer;

// Set the alarm times, currently set for 2:30 PM.
//Because there isn't a 'second' variable, the alarm will last 1 minute.
int alarmMinute = 0;//use these to set alarm time
int alarmHour = 2;
int alarmSecond = 0;//DO NOT TOUCH THIS
bool alarmAMPM = 1;

// This variable tells you if you should be showing the alarm message.
bool alarmState = 0; //alarmState will equal either 0 or 1. 

void setup() {
  lcd.begin();

  lcd.backlightOn();
  pinMode(A5, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);

  timer = millis();//start the timer as equal to the internal counter.
}

void loop() {
    noTone(A5);
    
    if (digitalRead (A0) == LOW) {
      alarmState = 0;
  }
    if (digitalRead (A4) == LOW) {
        lcd.backlightToggle();
    }

  if (millis() - timer >= 1000){
    seconds = seconds + 1;
    timer = timer + 1000;
  }

  // Insert the check into the seconds update so that it will
  // register the alarm once when the minute changes
  if (seconds >= 60){
    seconds = seconds - 60;
    minutes = minutes + 1;

    // Reset alarmState every minute so the alarm goes off after
    // 60 seconds
    alarmState = 0;
  }

  if (minutes >= 60){
    minutes = minutes - 60;
    hours = hours + 1;

    if (hours == 12){
      AMPM = 1 - AMPM;
    }
    if (hours == 13){
      hours = 1;
    }
  }

  /*
   * Combine 'if' conditions with && (shift + 7).
   * && (Boolean 'and') checks all of the conditions and performs
   * the code in the following {} block only if all are true. 
   * This checks if the hours, minutes, and AMPM all match that of 
   * the alarm
    */
  if ((hours == alarmHour)&&(minutes == alarmMinute)&&(AMPM == alarmAMPM)&&(seconds == alarmSecond)){
    // If all the current times match the alarm time, set
    // the alarm variable to 1 so that you're in 'alarm state'.
    alarmState = 1;
  }

  /*
   * Now that alarmState has been set, decide what to do.
   * If alarmState is 0, then you are in the normal non-alarm
   * mode, and display the time normally. 
   * 
   * Note that there are 4 'if' statements inside the alarmState 'if'
   * statement. These are only checked if alarmState is 0. This situation
   * shows how indentation, spacing, and placement of braces can increase
   * code clarity for yourself or anyone else who reads your code.
   */
   
  if (alarmState == 0){
    lcd.clear();
    lcd.print(hours);
    lcd.print(":");
    
    if (minutes < 10){
      lcd.print("0");
    }
    lcd.print(minutes);
    lcd.print(":");
    
    if (seconds < 10){
      lcd.print("0");
    }
    lcd.print(seconds);

    if (AMPM == 0){
      lcd.print(" AM");}
      
    if (AMPM == 1){
      lcd.print(" PM");
    }
  }
  
  // If alarmState is not 0, then display the alarm message:
  else{
    lcd.backlightOn();
    lcd.clear();
    lcd.print("Wake Up!");
    noTone(A5);
    lcd.backlightToggle();
    lcd.clear();
    delay(100);
    tone(A5, 987);
    lcd.print("Wake Up!");
    lcd.backlightToggle();
    delay(150);
  }
  /*  
   * You will see "Wake Up!" for one minute straight.
   * The void loop() is still running in the background, checking the
   * time against the alarm many times per second. When it finally sees
   * that alarmMinute no longer matches minute, it will display time again.
   * What is displayed is not all that is happening in a clock!
 */
 
  delay(300);
}

/*
 * In this lesson, you modified your time checks to add in
 * the alarm function. Just like the AM/PM check,
 * you added this new check to be made when one of the time counters
 * ticks up (in this case, the minutes counter), so that it only
 * runs once each time that condition is met (every minute).
 * 
 * You saw the use of two new additions to the 
 * conditional checks: && and else. && combines multiple checks into one 
 * statement. 
 * 
 * Else specifies what should happen when an 'if' statement is false, 
 * covering all cases not addressed by the original 'if'.
 * 
 * Try changing the 1000 in "if(millis()-timer>=1000)...." to a smaller
 * number. That will increase the 'speed of time' and allow you to more
 * quickly test your alarms.
 * 
 * Think about how you could create an alarm each hour on the same minute.
 * Hint: You'll only need the 'delete' key!
 * 
 * In the next lesson, you'll learn to set the time on the clock with a
 * button so that you don't have to carefully time your code uploads.
 * 
 */

// (c) 2017 Let's Start Coding. License: www.letsstartcoding.com/bsdlicense

