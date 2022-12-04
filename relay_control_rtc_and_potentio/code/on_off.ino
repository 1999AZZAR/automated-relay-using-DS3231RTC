void on_off(void) {
  /**************
    waktu hidup
  ***************/
  if (hour() == Value1 && minute() == Value2) {
    digitalWrite(Relay, !HIGH);
    Serial.println("LIGHT ON");
  }

  /*************
     waktu mati
  **************/
  else if (hour() == Value4 && minute() == Value3) {
    digitalWrite(Relay, !LOW);
    Serial.println("LIGHT OFF");
  }
}
