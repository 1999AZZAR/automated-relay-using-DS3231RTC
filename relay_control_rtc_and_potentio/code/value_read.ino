void value_read (void) {
  Value1 = analogRead(sen1);
  Value2 = analogRead(sen2);
  Value3 = analogRead(sen3);

  Serial.println(Value1);
  Serial.println(Value2);
  Serial.println(Value3);

  Value1 =  map(analogRead(sen1), 0, 1023, 1, 24); // map(sensor, minsensor, maxsensor, min, max)
  Value2 =  map(analogRead(sen2), 0, 1023, 0, 59);
  Value3 =  map(analogRead(sen3), 0, 1023, 1, 59);

  Value4 = Value1;
  Value5 = Value2 + Value3;
  if (Value3 > 59) {
    Value4 = Value1 + 1;
    Value5 = 0;
  }
}
