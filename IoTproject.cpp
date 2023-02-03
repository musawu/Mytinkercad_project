// library code
#include <LiquidCrystal.h>
//initialize the library with the number of pins interface
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//initialize LED pin
int rled=8;
int gled=9;

//initialize speaker pin
int speaker=13;
//initialize ultrasonic pin
int trig =7;
int echo=6;
long distance, duration;
void setup()
{
 //set LCD columns and rows
 lcd.begin(16,2);
  //pinMode command
  pinMode (rled,OUTPUT);
  pinMode (gled,OUTPUT);
  pinMode (speaker,OUTPUT);
  pinMode (trig,OUTPUT);
  pinMode (echo,INPUT);
  Serial.begin(9600);
  //lcd.begin(16,2);
  
}

void loop()
{
    digitalWrite(7,HIGH);
  delayMicroseconds(20);
  digitalWrite(7,LOW);
  delayMicroseconds(20);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  
  //if distance is more than 200cm/m
  //print"social distance well kept"
  //turn green led on 
  //turn speaker and red led off
  
  if(distance>200){
   
  
  lcd.setCursor(0,0);
  lcd.print("Safe Distance");
  lcd.setCursor(0,1);
  lcd.print(":)");
  
  delay(1000);
  digitalWrite(gled,HIGH);
  digitalWrite(rled,LOW);
  digitalWrite(speaker,LOW);
 
  
  }
  
  //else if distance is less than 200cm/m
  //print"please keep social distance"
  //turn green led off 
  //turn speaker and red led on
  
  
  
  else if (distance<200){
  
  lcd.setCursor(0,0);
  lcd.print("please keep social distance");
  lcd.setCursor(0,1);
  lcd.print(":(");
  delay(1000);
  digitalWrite(gled,LOW);
  digitalWrite(rled,HIGH);
  digitalWrite(speaker,HIGH);
    
  
  
  }
  
  
  
  
  
  
  
}