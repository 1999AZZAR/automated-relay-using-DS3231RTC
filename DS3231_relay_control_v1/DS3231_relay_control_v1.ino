#include <DS3232RTC.h>    //Get library here http://github.com/JChristensen/DS3232RTC
#include <Wire.h>

DS3232RTC RTC;
int Relay = 4;

int hours ;
int minutes;

const int OnHour  = 4; //SET TIME TO ON RELAY (24 HOUR FORMAT)
const int OnMin   = 30;
const int OffHour = 4; //SET TIME TO OFF RELAY
const int OffMin  = 31;

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT); //relay1
  digitalWrite(4, !LOW);

  setTime(04, 29, 00, 20, 10, 2022);//Hours / minutes / second / day of month / month / year
  RTC.set(now());

  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if (timeStatus() != timeSet)
    Serial.println("Unable to sync with the RTC");
  else
    Serial.println("RTC has set the system time");
}

void loop()
{

  hours = (hour());
  minutes = (minute());

  Serial.print(hour());
  Serial.print(' ');
  Serial.print(minute());
  Serial.print(' ');
  Serial.print(second());
  Serial.print(' ');
  Serial.print(day());
  Serial.print(' ');
  Serial.print(month());
  Serial.print(' ');
  Serial.print(year());
  Serial.println();
  delay(500);

  if (hours == OnHour && minutes == OnMin) {
    digitalWrite(Relay, !HIGH);
    Serial.println("LIGHT ON");
  }

  else if (hours == OffHour && minutes == OffMin) {
    digitalWrite(Relay, !LOW);
    Serial.println("LIGHT OFF");
  }
}
