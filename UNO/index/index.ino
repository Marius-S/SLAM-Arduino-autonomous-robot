#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 10, 4, 5, 6, 7);

//lcd
int lcd_select = 0;
int work = 0;

//ultrasonic
long duration, cm;

void setup() {
  lcd_setup();
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  ultrasonic();
  lcds();

  if (cm >= 50) {
    go_straight();
  } else {
    stop_motors();
    turn_left();
  }

}


