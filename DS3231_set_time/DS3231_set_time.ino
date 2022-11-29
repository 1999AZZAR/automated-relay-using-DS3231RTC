#include <DS3232RTC.h>    //Get library here http://github.com/JChristensen/DS3232RTC
#include <Wire.h>

DS3232RTC RTC;

void setup()
{
  Serial.begin(9600);

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
}
