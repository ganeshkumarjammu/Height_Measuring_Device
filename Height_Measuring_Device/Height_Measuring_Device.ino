#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
long WallHeight ;
#define trigPin 10 
#define echoPin 11
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  WallHeight = getDistance() ;
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print(" WELCOME TO");
  lcd.setCursor(0,1);
  lcd.print("     SOHAM");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Height On Wall");
  lcd.setCursor(0,1);
  lcd.print("distance: ");
  lcd.setCursor(11, 1);
  lcd.print(WallHeight);
  lcd.print(" cm");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     SOHAM");
  lcd.setCursor(0,1);
  lcd.print("Height: ");
}

void loop() {
  long distance = getDistance();
  float heightOfPerson = WallHeight - distance;
  lcd.setCursor(8, 1);
  lcd.print(heightOfPerson);
  lcd.print(" cm");
  delay(500);
}


long getDistance(){
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return distance = (duration/2) / 29.1;
}
