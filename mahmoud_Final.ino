#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3E, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // 
//#define DS3231_I2C_ADDRESS 0x68
#include "RTClib.h"
RTC_DS1307 RTC;
String x;
String y;
String z;
int T1=800, T2=8500, T3=9400, TA=10300, T4=10500, T5=11400, TB=12300, T6=12500, T7=13400, TF=14300;
int Bell1 = 10;
int Bell2 = 11;
void setup () {
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();
    lcd.begin(16,2);
    lcd.backlight();
  if (! RTC.isrunning())
  {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  pinMode(Bell1,OUTPUT);
  pinMode(Bell2,OUTPUT);
  digitalWrite(Bell1, HIGH);
  digitalWrite(Bell2, HIGH);
}
void loop () {
    DateTime now = RTC.now();
    lcd.clear();
    lcd.print("Date: "); 
    lcd.print(now.year(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.day(), DEC);
    lcd.setCursor (0,1);
    lcd.print("Time: ");
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
    //* ***********************
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    x = now.hour();
    y = now.minute();
    z = now.second();
    String  DX  = x;
            DX += y;
            DX += z;
    int DX1 = DX.toInt();
    // Class Start
    if (DX1 == T1 || DX1 == T2 || DX1 == T3 || DX1 == T4 || DX1 == T5 || DX1 == T6 || DX1 == T7)
    {
      Serial.print("Class Start: ");
      digitalWrite(Bell1, LOW);
      delay(3000);
      digitalWrite(Bell1, HIGH);
    }
    // Class Reccess
    if (DX1 == TA || DX1 == TB)
    {
      Serial.print("Class Reccess: ");
      digitalWrite(Bell1, LOW);
      delay(500);
      digitalWrite(Bell1, HIGH);
      delay(500);
      digitalWrite(Bell1, LOW);
      delay(500);
      digitalWrite(Bell1, HIGH);
      delay(500);
      digitalWrite(Bell1, LOW);
      delay(500);
      digitalWrite(Bell1, HIGH);
    }
    // Class Finish
    if (DX1 == TF)
    {
      Serial.print("Class Reccess: ");
      digitalWrite(Bell1, LOW);
      delay(500);
      digitalWrite(Bell1, HIGH);
      delay(500);
      digitalWrite(Bell1, LOW);
      delay(500);
      digitalWrite(Bell1, HIGH);
      delay(500);
      digitalWrite(Bell1, LOW);
      delay(2000);
      digitalWrite(Bell1, HIGH);
    }
    /*
    if (  DX1 == 100 ||
          DX1 == 111 ||
          DX1 == 11111
        )
    {
      digitalWrite(Bell2, LOW);
      Serial.print("XXXXXXXX: ");
      delay(3000);
      digitalWrite(Bell2, HIGH);
    }
    */
    Serial.print(DX);
    /*
    Serial.print("Number: ");
    if (x<10) { Serial.print('0'); }
    Serial.print(x);
    if (y<10) { Serial.print('0'); }
    Serial.print(y);
    if (z<10) { Serial.print('0'); }
    Serial.print(z);
    */
    Serial.println();
    delay(1000);
}
