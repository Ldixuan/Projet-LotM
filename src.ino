
#include <LiquidCrystal.h>
#include <stdlib.h>


LiquidCrystal lcd(12,11,5,4,3,2);
int upper;
int lower;
int valid;
int t;
int taille=0;
int prof=0;
int marge=3;
bool v = true;

#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262


// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup()
{
lcd.begin(16,2);
  pinMode(A3, OUTPUT);
  
delay(1000);
}
void loop()
{
    upper = analogRead(A0);
    lower = analogRead(A1);
	valid = analogRead(A2);
  	prof = rand() % 10 + 1;
  
    t = 300;
    if(upper < t && lower > t)
    {
    taille = taille + 1;
    delay(900);
    }
    else
    {
    taille = taille;
    }
    if(upper > t && lower < t)
    {
    taille =taille -1;
    delay(900);
    }
    else
    {
    taille = taille;
    }
  
  if(valid > 10){
	v = false;
  }

  
  if(v){
  	lcd.setCursor(0,0);
    lcd.print("Taille : ");
    lcd.print(taille);
    lcd.print(" m");
    delay(500);
  
  	lcd.clear();
    

  }
  else{
    if(prof > (taille + marge)){
    	digitalWrite(A3, HIGH);
      	tone(8, 300, 2000);
      	  
     	
    }else{
      noTone(8);
    digitalWrite(A3, LOW);
    
    }
      
      
	 lcd.setCursor(0,0);
     lcd.print("Prof : ");
     lcd.print(prof);
     lcd.print(" m");

     lcd.setCursor(0,1);
     lcd.print("Date: ");
     lcd.print("18/06/2021");
     delay(2000);
  
  	lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("Loc: ");
    lcd.print("10.0, 32.3");
    delay(2000);
  
  	lcd.clear();
  }


}


