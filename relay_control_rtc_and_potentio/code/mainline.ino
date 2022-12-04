void mainline(void) {
  Serial.begin(9600);  //serial monitar
  lcd.init();          //inisialisasi lcd
  lcd.backlight();     //backlight lcd
  lcd.setCursor(0, 0); //tempat pertama text (kolom, baris)
  lcd.print("timer penyiraman");
  lcd.setCursor(1, 1);
  lcd.print("by : 1999azzar");

  pinMode(4, OUTPUT);    // relay/motor (output = keluaran, input = sensor)
  digitalWrite(4, !LOW); // ! = not, !LOW = HIGH / !HIGH = LOW

  setTime(04, 29, 00, 20, 10, 2022);//Hours / minutes / second / day of month / month / year
  RTC.set(now());                   //set waktu rtc

  setSyncProvider(RTC.get);    // membaca waktu dari rtc
  if (timeStatus() != timeSet) // jika waktu rtc tak terbaca
    Serial.println("Unable to sync with the RTC");
  else
    Serial.println("RTC has set the system time");

  delay(2500);
  lcd.clear(); //membersihkan semua teks di lcd
}
