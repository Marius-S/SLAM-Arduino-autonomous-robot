#include <Servo.h> //include servo library

long duration, cm; //Ultrasonic sensor calculations variable
int endd = 0; //Show if area analysis were done or not
int motors = 0; //If 0 - engine commands will freeze, if 1 - active
int jump = 0; //Variable which show if robot changed direction
int motor_speed = 150; // Motors speed
int x = 0; //Array X value
int y = 0; //Array Y value
int y_value = 0; //Describes side into which robot going in line, 0 - right, 1 - left
int Array[10][10] = {{}}; //4 x 4 meters square Array[X][Y]
int Array_rez[10][10] = {{}}; //4 x 4 meters square Array[X][Y]
int line[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int check_line = 0;

int Steps = 0;

int turn = 700; //How many time needed to rotate servo
//Servo left;
//Servo right;

void setup() {
//  pinMode(12, OUTPUT); //Setup motors
//  pinMode(9, OUTPUT); //Setup motors
//  pinMode(13, OUTPUT); //Setup motors
//  pinMode(8, OUTPUT); //Setup motors
//  digitalWrite(13, HIGH);
//  digitalWrite(12, HIGH);
//  digitalWrite(8, LOW);
//  digitalWrite(9, LOW);
//  analogWrite(11, 0);
//  analogWrite(3, 0);
  Serial.begin(9600); //Begin serial port 9600
  Test(8); //Choose test
  //right.attach(6);//desine
  //left.attach(10);//kaire
  Serial.println("Start");
}

void loop() {
  algo_1();
}
//void ultrasonic();
