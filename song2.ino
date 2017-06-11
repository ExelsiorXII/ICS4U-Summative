void Song2()  {
  
  lcd.clear();


// notes in the melody:
int melody[] = {
  NOTE_G4, NOTE_A4, NOTE_AS4, 
  NOTE_F4, NOTE_G4, NOTE_D4, 
  NOTE_G4, NOTE_AS3, NOTE_G4, NOTE_AS3,
  NOTE_C4, NOTE_D4, NOTE_G3

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  16,16,16,
  8,8,2,
  8,16,8,16,
  16,16,4
  
};


      lcd.setCursor(1, 0);
      lcd.print("Now playing...");
      lcd.setCursor(0, 1);
      lcd.print("JUSTIN SONG");
     
      


    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
 
      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 2000 / noteDurations[thisNote];
 
      tone(8, melody[thisNote], noteDuration);
 
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
 
      // stop the tone playing:
      tone(8, 0, noteDuration);
 
    }


Song2title();

  
  } // end Song2 loop
