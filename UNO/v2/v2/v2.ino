long duration, cm; //Ultrasonic sensor calculations variable
int endd = 0; //Show if area analysis were done or not
int motors = 0; //If 0 - engine commands will freeze, if 1 - active
int jump = 0; //Variable which show if robot changed direction
int motor_speed = 150; // Motors speed
int x = 0; //Array X value
int y = 0; //Array Y value
int y_value = 0; //Describes side into which robot going
int Array[10][10] = {{}}; //4 x 4 meters square Array[X][Y]

void setup() {
  pinMode(12, OUTPUT); //Setup motors
  pinMode(9, OUTPUT); //Setup motors
  pinMode(13, OUTPUT); //Setup motors
  pinMode(8, OUTPUT); //Setup motors
  Serial.begin(9600); //Begin serial port 9600
  //Obstacles list. Uncomment obstacle variant to active it testing variant
  //Test1();
  Test2();
  //Test3();
  //Test4();
  //Test5();
  //Test6();
  //Test7();
  //Test8();
}

void loop() {
  listener(); //Listen in entered value into Serial monitor
  delay(1000); //Delay between robot moves
  if (endd == 0) { //Chech is robot must stop or can go
    jump--; //Every loop jump variable starts from 0
    //scan();
    obstacle(); //Checking if obstacle exist in front of robot
    print_steps();
    Array[x][y] = 1;
    if ((x == 9) && (y_value == 0)) { //if robot is near the wall, when change direction
      y_value = 1; //change direction
      go_to_next_y();
      turn_left(motor_speed); //Turn robot left
      go_straight(motor_speed); //Go robot straight
      turn_left(motor_speed); //Turn robot left
    }
    if ((x <= 0) && (y_value == 1)) { //if robot is near the wall, when change direction
      y_value = 0; //change direction
      go_to_next_y();
      turn_right(motor_speed); //Turn robot right
      go_straight(motor_speed); //Go robot straight
      turn_right(motor_speed); //Turn robot right
    }
    if ((y_value == 0) && (jump != 1)) { //if robot isn't near the wall or object
      x++;
    }
    if ((y_value == 1) && (jump != 1)) { //if robot isn't near the wall or object
      x--;
    }
  }
}

void print_steps() { //Print steps to Serial monitor that robot do
  Serial.print("Driving ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.println();
}

void listener() { //Read Serial monitor
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == 'P') //If 'P' print grid
    {
      print_array();
    }
    if (ch == 'B') //If 'B' print as list
    {
      print_array_full();
    }
  }
}

void print_array() { //Print array as grid
  if (x == 0) {
    if (y >= 9) {
      x = 0;
      y = 0;
      //Array print
      while (y < 10) {
        while (x < 10) {
          Serial.print(Array[x][y]);
          x++;
        }
        y++;
        x = 0;
        Serial.println();
        endd = 1;
      }
    }
  }
}

void print_array_full() { //Print array as line for map draw application
  if (x == 0) {
    if (y >= 9) {
      x = 0;
      y = 0;
      //Array print
      while (y < 10) {
        while (x < 10) {
          Serial.println(Array[x][y]);
          x++;
        }
        y++;
        x = 0;
        //Serial.println();
        endd = 1;
      }
    }
  }
}

void go_to_next_y() { //If goint to next y line when use this
  y++;
  print_array();
  jump = 1;
}

void ultrasonic() {
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
  delayMicroseconds(2);
  digitalWrite(A3, HIGH);
  delayMicroseconds(5);
  digitalWrite(A3, LOW);
  pinMode(A2, INPUT);
  duration = pulseIn(A2, HIGH);
  cm = microsecondsToCentimeters(duration);
  delay(100);
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
