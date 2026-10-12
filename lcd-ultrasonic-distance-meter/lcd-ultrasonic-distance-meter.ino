#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int trig=8;
int echo=9;
long duration;
float distance;

void setup() {
  pinMode (trig,OUTPUT);
  pinMode (echo,INPUT);
  Serial.begin (9600);
  lcd.begin (16,2);
 

}

void loop() {
  digitalWrite (trig,LOW);
  delayMicroseconds (2);
  digitalWrite (trig,HIGH);
  delayMicroseconds (10);
  digitalWrite (trig,LOW);

  duration= pulseIn (echo,HIGH);
  distance= duration * 0.034 / 2;
  lcd.setCursor(0, 0);
  lcd.print("Distance:");

  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm     ");
  delay (500);
}
