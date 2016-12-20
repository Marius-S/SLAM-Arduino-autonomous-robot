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
int check_line = 0;

int turn = 700; //How many time needed to rotate servo
Servo left;
Servo right;

void setup() {
  pinMode(12, OUTPUT); //Setup motors
  pinMode(9, OUTPUT); //Setup motors
  pinMode(13, OUTPUT); //Setup motors
  pinMode(8, OUTPUT); //Setup motors
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  analogWrite(11, 0);
  analogWrite(3, 0);
  Serial.begin(9600); //Begin serial port 9600
  Test(1); //Choose test 
  right.attach(6);//desine
  left.attach(10);//kaire
  Serial.println("Start");
}

void loop() {

algo_1();
  //main rotating commands
//  turn_left(turn);
//  go_straight(turn);
//  turn_right(turn);

  //  listener(); //Listen in entered value into Serial monitor
  //  delay(1000); //Delay between robot moves
  //  if (endd == 0) { //Chech is robot must stop or can go
  //    jump--; //Every loop jump variable starts from 0
  //    //scan();
  //    obstacle(); //Checking if obstacle exist in front of robot
  //    print_steps();
  //    Array[x][y] = 1;
  //    if ((x == 9) && (y_value == 0)) { //if robot is near the wall, when change direction
  //      y_value = 1; //change direction
  //      go_to_next_y();
  //      turn_left(motor_speed); //Turn robot left
  //      go_straight(motor_speed); //Go robot straight
  //      turn_left(motor_speed); //Turn robot left
  //    }
  //    if ((x <= 0) && (y_value == 1)) { //if robot is near the wall, when change direction
  //      y_value = 0; //change direction
  //      go_to_next_y();
  //      turn_right(motor_speed); //Turn robot right
  //      go_straight(motor_speed); //Go robot straight
  //      turn_right(motor_speed); //Turn robot right
  //    }
  //    if ((y_value == 0) && (jump != 1)) { //if robot isn't near the wall or object
  //      x++;
  //    }
  //    if ((y_value == 1) && (jump != 1)) { //if robot isn't near the wall or object
  //      x--;
  //    }
  //  }
}



//void ultrasonic();
