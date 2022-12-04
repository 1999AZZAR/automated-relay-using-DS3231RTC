void print_text (void) {
  /*******************************
    printing text data on a lcd
  *******************************/
  lcd.setCursor(0, 1);
  lcd.print("timeset:");
  lcd.setCursor(8, 1);
  lcd.print(Value1);
  lcd.setCursor(10, 1);
  lcd.print(":");
  lcd.setCursor(11, 1);
  lcd.print(Value2);
  lcd.setCursor(14, 1);
  lcd.print(Value3);
  delay(250);
  lcd.setCursor(9, 1);
  lcd.print("       ");

  lcd.setCursor(0, 0);
  lcd.print("timertc:");
  lcd.setCursor(8, 0);
  lcd.print(hour());
  lcd.setCursor(10, 0);
  lcd.print(":");
  lcd.setCursor(11, 0);
  lcd.print(minute());
  lcd.setCursor(14, 0);
  lcd.print("in");
  delay(250);
  lcd.setCursor(9, 1);
  lcd.print("       ");
}
