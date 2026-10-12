#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

byte smiley[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

int trig = 8;
int echo = 9;

int red = 11;
int green = 6;
int blue = 10;

int buzzer = 7;

long duration;
float distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  lcd.begin(16, 2);
  lcd.createChar(0, smiley);
  lcd.setCursor(0, 0);
  lcd.print("Parking System ");
  lcd.write(byte(0));
  delay(2000);
  lcd.clear();
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH, 38000);
  distance = duration * 0.034 / 2;

  if (distance > 21) {
    noTone(buzzer);
    lcd.setCursor(0, 0);
    lcd.print("Status: Far     ");
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distance, 1);
    lcd.print ("cm");
    rgbcolor(0, 150, 0);
  }
  else if (distance > 6) {
    noTone(buzzer);
    lcd.setCursor(0, 0);
    lcd.print("Status: Safe    ");
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distance, 1);
    lcd.print ("cm");
    rgbcolor(0, 80, 0);
  }
  else if (distance > 2) {
    tone(buzzer, 2000);
    delay(200);
    noTone (buzzer);
    lcd.setCursor(0, 0);
    lcd.print("Status: Caution ");
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distance, 1);
    lcd.print ("cm");
    rgbcolor(255, 255, 0);
  }
  else {
    tone(buzzer, 2000);
    lcd.setCursor(0, 0);
    lcd.print("Status: Stop    ");
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distance, 1);
    lcd.print ("cm");
    rgbcolor(255, 0, 0);
  }

  delay(300);
}

void rgbcolor(int redvalue, int greenvalue, int bluevalue) {
  analogWrite(red, redvalue);
  analogWrite(green, greenvalue);
  analogWrite(blue, bluevalue);
}
