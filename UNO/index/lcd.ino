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
    //UP
  }
  else if (x < 400) {
    //Down - Push array values into monitor
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Push to Serial");
    work = 3;
  }
  else if (x < 600) {
    //LEFT - start
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Start");
    work = 1;
  }
  else if (x < 800) {
    //SELECT
    if (work == 1) {
      work = 2;
    }
    switch (work) {
      case 1:
        work = 2;
        break;
      case 3:
        work = 4;
        break;
    }
  }
}

