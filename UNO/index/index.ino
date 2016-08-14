#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 10, 4, 5, 6, 7);

//lcd
int lcd_select = 0;
int work = 1;
int motor_speed = 150;
int x = 0;
int y = 0;
int Array[20][20] = {{}};

//ultrasonic
long duration, cm;

void setup() {
  //lcd_setup();
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // laikinai ultrasonic();
  // lcds();
  //laikinai calculate();
  
  if (work == 1) {
    turn_right(motor_speed);
    work = 0;
  }
  }


