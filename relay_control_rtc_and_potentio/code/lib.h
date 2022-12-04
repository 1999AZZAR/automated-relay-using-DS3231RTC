#include <Wire.h>              //lib urusan i2c
#include <DS3232RTC.h>         //lib sensor rtc
#include <LiquidCrystal_I2C.h> //lib layar

DS3232RTC RTC;                      //pemnaggilan awal rtc
LiquidCrystal_I2C lcd(0x27, 16, 2); //layar (alamat, kolom, baris)

int Relay = 4;  //pinout relay/pompa/led etc...
int sen1 = A0;  //pinout potensio 1 (jam)
int sen2 = A1;  //pinout potensio 2 (menit)
int sen3 = A2;  //pinout potensio 3 (interval)

/**********************************************************************
   nilai yang dapat berubah digunakan untuk menyimpan nilai sementara
 **********************************************************************/
int Value1 = 0;
int Value2 = 0;
int Value3 = 0;
int Value4 = 0;
int Value5 = 0;
