long duration, cm; //Ultrasonic sensor calculations variable
int endd = 0; //Show if area analysis were done or not
int motors = 0; //If 0 - engine commands will freeze, if 1 - active
int jump = 0;

int x = 0; //Array X value
int y = 0; //Array Y value
int y_value = 0; //Describes side into which robot going
int Array[10][10] = {{}}; //4 x 4 meters square Array[X][Y]


void setup() {
  Serial.begin(9600); //Begin serial port 9600
  //Obstacles list. Uncomment obstacle variant to active it testing variant
  //Test1();
  //Test2();
  Test3();
  //Test4();
  //Test5();
  //Test6();
  //Test7();
  //Test8();
}

void loop() {
  if (endd == 0) {
    jump--;
    //Driving
    obstacle();
    print_steps();
    Array[x][y] = 1;
    if ((x == 9) && (y_value == 0)) {
      y_value = 1;
      y++;
      print_array();
      jump = 1;
    }
    if ((x <= 0) && (y_value == 1)) {
      y_value = 0;
      y++;
      print_array();
      jump = 1;
    }
    if ((y_value == 0) && (jump != 1)) {
      x++;
    }
    if ((y_value == 1) && (jump != 1)) {
      x--;
    }
  }
}

void print_steps() {
  Serial.print("Driving ");
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.println();
}

void print_array() {
  if (x == 0) {
    if (y >= 9) {
      x = 0;
      y = 0;
      //Array print
      while (y < 10) {
        while (x < 10) {
          Serial.print(Array[x][y]);
          //For applicaiton Serial.println(Array[x][y]);
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
