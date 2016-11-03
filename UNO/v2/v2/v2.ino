long duration, cm;
int start = 0;
int endd = 0;

int x = 0;
int y = 0;
int y_value = 0;
int Array[10][10] = {{}}; //4 x 4 meters square


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Kliuciu sarasas
Array[5][5]=2;
Array[5][2]=2;
}

void loop() {
  if (endd == 0){
  ultrasonic();
  if (cm <= 50) {
    Serial.print("Labas");
    delay(1200);
  }

  //Driving
  if (cm > 50) {


    if (y_value == 0) {
      print_array(x,y);
//      if (start == 1) {
//        x++;
//      } else {
//        start = 1;
//      }
      while (x < 10) {
        //delay(500);
        Serial.print("Driving ");
        Serial.print(x);
        Serial.print(" ");
        Serial.print(y);
        Serial.println();
        //Kliutis
        if (Array[x][y]==2){
          y++;
        }
        //Kliuties pabaiga
        Array[x][y] = 1;
        x++;
        if (x >= 10) {
          y_value = 1;
          y++;
          print_array(x,y);
        }
      }
    } else {
      
      //x--;
      while (x > 0) {
        x--;
        delay(500);
        Serial.print("Driving ");
        Serial.print(x);
        Serial.print(" ");
        Serial.print(y);
        Serial.println();
        //Kliutis
        if (Array[x][y]==2){
          y++;
        }
        //Kliuties pabaiga
        Array[x][y] = 1;

        if (x <= 0) {
          y_value = 0;
          y++;
          print_array(x,y);
        }
      }
    }
  }
  }
 
  
}

void print_array(int x, int y){
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
        endd=1;
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
