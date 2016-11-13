void obstacle() {
  int trigger = 0;
  int straight = 1;
  //Obstacle - 1
  if ((Array[x][y] == 2) && (Array[x - 1][y + 1] == 2)) {
    Serial.println("Obstacle-3");
    x--;
    if (y_value == 0) {
      y_value = 1;
      x--;
    } else
    {
      y_value = 0;
      x--;
    }
    trigger = 1;
    straight = 0;
  }

  //Obstacle - 2
  if ((x == 10) && (trigger != 1) && (Array[x - 1][y + 1] == 2)) {
    Serial.println("Obstacle-2");
    y++;
    x--;
    if (y_value == 0) {
      y_value = 1;
      x--;
    } else
    {
      y_value = 0;
      x--;
    }
    straight = 0;
  }

  //Obstacle - 3
  if ((Array[x][y] == 2) && (trigger != 1)) {
    Serial.println("Obstacle-3");

    turn_right(motor_speed);

    go_straight(motor_speed);

    turn_left(motor_speed);



    if (y_value == 1) {
      y++;
      x++;
    }
    else {
      y++;
      x--;
    }
    straight = 0;
  }

  if ((straight == 1) && (endd == 0)) {
    go_straight(motor_speed);
  }
}

