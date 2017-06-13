// LCD Screen, Switch & LED Setup
#include <LiquidCrystal.h>
#include "pitches.h"
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // adds LCD with pins used
const int LCDswitchPin = 7; // define menu/LCD switch name
int LCDswitchState = 0; // set menu/LCD switch state to off/low
int prevLCDswitchState = 0;
int redLED = 6;
int LCDswitchCounter = 0;   // counter for the number of menu button presses 
    // (this code counts the menu button pushes and starts from zero after ending "menu mode". 

// Music Note Keys - Set frequency values
int notes[] = {262, 294, 330, 349, 392, 440, 494}; // Set notes C, D, E, F, G, A, B



//////////////////////////////////////////////
void setup() {

    // Defines Input and Output pins, starts LCD screen
  lcd.begin(16, 2); 
  pinMode(LCDswitchPin, INPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(redLED, LOW); // LED stays off while piano keys are on
  

} // end setup


//////////////////////////////////////////////
void loop() {
  
  LCDswitchState = digitalRead(LCDswitchPin);
  int keyVal = analogRead(A0);
  lcd.noDisplay();
  digitalWrite(redLED, LOW); // Turn LED back off every time main loop starts
  


// ************** START "LCDstart" WHEN MENU BUTTON IS PUSHED ***********

    if (LCDswitchState == HIGH)  {
      digitalWrite(redLED, HIGH); // Turn LED on to show piano keys are disabled and device is in "menu mode"
      lcd.display();
      lcd.clear();
      LCDstart();
      }
   
   
// ***********************************************************************
  
  

////// KEYBOARD NOTES & FREQUENCY STATEMENTS //////
// Uses the resistor ladder to change the voltage of each piano key button
// Lower resistance, lower pitch
  if(keyVal == 1023)  {
    tone(8, notes[0]); // C
    } 
    
        else if(keyVal >= 990 & keyVal <=1010)  {
          tone(8, notes[1]); // D
          } 
    
        else if(keyVal >= 960 && keyVal <= 980)  {
          tone(8, notes[2]); // E
          } 
        
        else if(keyVal >= 900 && keyVal <= 945)  {
          tone(8, notes[3]); // F
          } 
        
        else if(keyVal >= 650 && keyVal <= 710)  {
          tone(8, notes[4]); // G
          } 
        
        else if(keyVal >= 500 && keyVal <= 550)  {
          tone(8, notes[5]); // A
          } 
        
        else if(keyVal >= 5 && keyVal <= 10)  {
          tone(8, notes[6]); // B
          } 
        
        else if(keyVal <= 1)  { // if no switch is pressed, do not play tone
          noTone(8);
          } 

} //end frequency tone loop





/////////////////////////////////////////////////////
void LCDstart()  {
  int keyVal = analogRead(A0);  
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button

    while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed
      LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button every time loop starts
      
      //************* START SONG 1 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 1
        delay(300); // min. time until counts adds 1 more

        Song1title();
        lcd.clear();
        break;
        }

      //************* ELSE SHOW MENU ****************
      else   {  // if menu button is not pressed,
        LCDswitchCounter=0; // set menu button count to 0
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WHICH SONG WOULD");
        lcd.setCursor(0, 1);
        lcd.print("YOU LIKE TO PLAY");
        delay(50); // return to main 
        }
     
      } // end while
  } // end LCDstart loop
  
  
  

// ************* SONG 1 LOOP STARTS HERE **************  
void Song1title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 2 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 2
        delay(300); // min. time until counts adds 1 more

        Song2title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed   
        int keyVal = analogRead(A0);

         if(keyVal >= 2)  {
           digitalWrite(redLED, HIGH);
           Song1();
           break;
           } // end if
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SUPER MARIO BROS");
        lcd.setCursor(0, 1);
        lcd.print("   THEME SONG");
        delay(50);
        }
    } // end while song 1 -> 2
        
} // end Song1title loop




// ************* SONG 2 LOOP STARTS HERE **************  
void Song2title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 3 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter++; // set button count to 3
        delay(300); // min. time until counts adds 1 more

        Song3title();
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
         
         if(keyVal >= 2)  {
           digitalWrite(redLED, HIGH);
           Song2();
           break;
           } // end if
           
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("HOCKEYLOVER99'S");
          lcd.setCursor(0, 1);
          lcd.print("   THEME SONG");
          delay(50);
          }
        
        } // end while song 2 -> 3
        
} // end Song2title loop




// ************* SONG 3 LOOP STARTS HERE **************  
void Song3title()  {
  int keyVal = analogRead(A0);
  LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again
  
  while (LCDswitchState == LOW)  { // continue loop while menu button isn't pressed  
    LCDswitchState = digitalRead(LCDswitchPin); // check state of menu button again 

      //************* START SONG 4 TITLE LOOP ********************
      if (LCDswitchState == HIGH)  { // if menu button is pressed, then...
        LCDswitchCounter=0; // set button count to 4
        delay(300); // min. time until counts adds 1 more
        lcd.clear();
        break;
        }
        
      else  { // if menu button is not pressed
        int keyVal = analogRead(A0);
     //   Serial.println(keyVal); 
         
         if(keyVal >= 2)  {
           digitalWrite(redLED, HIGH);
           Song3();
           break;
           } // end if
           
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("     HAPPY");
        lcd.setCursor(0, 1);
        lcd.print("    BIRTHDAY");
        delay(50);
        }
        
        } // end while song 3 -> 4
        
} // end Song3title loop










