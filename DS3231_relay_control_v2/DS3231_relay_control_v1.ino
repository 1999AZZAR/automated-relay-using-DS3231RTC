#include <DS3232RTC.h>    //Get library here http://github.com/JChristensen/DS3232RTC
#include <Wire.h>

DS3232RTC RTC;
int Relay = 4;
int hours ;
int minutes;

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT); //relay1

  /////////Uncomment both lines below when you want to set the time
  /////////AFTER SETTING TIME COMMENT the lines.
  setTime(04, 29, 00, 20, 10, 2022);//Hours / minutes / second / day of month / month / year
  RTC.set(now());

  setSyncProvider(RTC.get);   // the function to get the time from the RTC
  if (timeStatus() != timeSet)
    Serial.println("Unable to sync with the RTC");
  else
    Serial.println("RTC has set the system time");
    
  digitalWrite(4, !LOW);
}

void loop()
{
  digitalClockDisplay();
  auto_onoff();
}

void auto_onoff()
{ //we are using hour as a value the rest is ignored.
  hours = (hour());
  minutes = (minute());
  
  if (hours == 4 && minutes == 30)
  {
    digitalWrite(4, !HIGH);
  }
  else if (hours == 4 && minutes == 31)
  {
    digitalWrite(4, !LOW);
  }
}

void digitalClockDisplay()
{
  // digital clock display of the time
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
}
