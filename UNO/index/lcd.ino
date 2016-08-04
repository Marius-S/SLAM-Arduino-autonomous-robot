void lcd_setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("VMU project");
  lcd.setCursor(0, 1);
  lcd.print("Choose: ");
}

void lcds() {
  int x;
  x = analogRead (4);
  lcd.setCursor(10, 1);
  if (x < 60) {
    //RIGHT - stop
    work = 0;
  }
  else if (x < 200) {
    //UP - about
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Owner:");
    lcd.setCursor(0, 1);
    lcd.print("Marius S.");
    //delay(5000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Stakeholder:");
    lcd.setCursor(0, 1);
    lcd.print("T. Krilavicius");
    //delay(5000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("VMU project");
    lcd.setCursor(0, 1);
    lcd.print("Choose: ");
  }
  else if (x < 400) {
    //Down
  }
  else if (x < 600) {
    //LEFT - start
    work = 1;
  }
  else if (x < 800) {
    //SELECT
  }
  if (work == 1) {
    Serial.println("working");
  }
}
