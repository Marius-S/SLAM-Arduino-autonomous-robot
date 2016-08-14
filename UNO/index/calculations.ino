void calculate() {
  if (work == 1) {
    go_straight(motor_speed);

    //write to array information
    while ((cm >= 50) || (x > 20))  {
      switch (compas) {
        case 1:
          delay(1200);
          Array[x][y] = 1;
          x++;
          ultrasonic();
          break;
        case 2:
          delay(1200);
          Array[x][y] = 1;
          y--;
          ultrasonic();
          break;
        case 3:
          delay(1200);
          Array[x][y] = 1;
          y++;
          ultrasonic();
          break;
        case 4:
          delay(1200);
          Array[x][y] = 1;
          x--;
          ultrasonic();
          break;
      }
    }

    //if in front is wall, then stop
    stop_motors();
    work = 0;
  }
}

void Array_to_serial() {
  //print values in to serial monitor
  Serial.println("Values");
  int total = 0;
  for (int i = x; i >= 0; i = i - 1) {
    if (Array[i][0] == 1) {
      total++;
      Serial.print("[");
      Serial.print(i);
      Serial.print("]");
      Serial.print("[");
      Serial.print("0");
      Serial.print("]");
      Serial.print(" = ");
      Serial.print(Array[i][0]);
      Serial.println();
    }
  }
  Serial.print("Total traveled stright = ");
  Serial.print(total * 20);
  Serial.print(" cm");
  Serial.println();
}


