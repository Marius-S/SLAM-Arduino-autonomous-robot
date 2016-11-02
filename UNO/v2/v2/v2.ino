long duration, cm;
int start = 0;


int x = 0;
int y = 0;
int y_value = 0;
int Array[5][5] = {{}}; //4 x 4 meters square


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  ultrasonic();
  if (cm <= 50) {
    Serial.print("Labas");
    delay(1200);
  }

  //Driving
  if (cm > 50) {


    if (y_value == 0) {
//      if (start == 1) {
//        x++;
//      } else {
//        start = 1;
//      }
      while (x < 5) {
        delay(500);
        Serial.print("Driving ");
        Serial.print(x);
        Serial.print(" ");
        Serial.print(y);
        Serial.println();
        Array[x][y] = 1;
        x++;
        if (x >= 5) {
          y_value = 1;
          y++;
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
        Array[x][y] = 1;

        if (x <= 0) {
          y_value = 0;
          y++;
        }
      }
    }
  }

  //print aray
  if (x >= 4) {
    if (y >= 4) {
      x = 0;
      y = 0;
      //Array print
      while (y < 5) {
        while (x < 5) {
          Serial.print(Array[x][y]);
          //For applicaiton Serial.println(Array[x][y]);
          x++;
        }
        y++;
        x = 0;
        Serial.println();
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
