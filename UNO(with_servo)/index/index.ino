#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 10, 4, 5, 6, 7);

//lcd
int work = 0;
int motor_speed = 150;
int x = 0;
int y = 0;
int Array[20][20] = {{}}; //4 x 4 meters square
int compas = 1;

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
  lcds();

  if (work == 2) {
    turn_right(motor_speed);
    work = 0;
  }
  switch (work) {
    case 2:
      calculate();
      break;
    case 4:
      Array_to_serial();
      break;
  }
}


