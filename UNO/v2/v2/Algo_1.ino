void algo_1() {
  listener(); //Listen in entered value into Serial monitor
  delay(1000); //Delay between robot moves
  if (endd == 0) { //Chech is robot must stop or can go
    jump--; //Every loop jump variable starts from 0
    //scan();
    obstacle_algo(); //Checking if obstacle exist in front of robot
    print_steps();
    Array[x][y] = 1;
    if ((x == 9) && (y_value == 0)) { //if robot is near the wall, when change direction
      y_value = 1; //change direction
      go_to_next_y();
    }
    if ((x <= 0) && (y_value == 1)) { //if robot is near the wall, when change direction
      y_value = 0; //change direction
      go_to_next_y();
    }
    if ((y_value == 0) && (jump != 1)) { //if robot isn't near the wall or object
      x++;
    }
    if ((y_value == 1) && (jump != 1)) { //if robot isn't near the wall or object
      x--;
    }
  }
}

void obstacle_algo() {
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
    //y++;
    go_to_next_y();
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
  }

  //Some improvisations
  if ((x == 9) or (x == 0)) {
    while ((x != 9) or (x != 0) or (Array[x][y] != 2)) {
      if (y_value == 1) {
        x++;
      } else {
        x--;
      }
      x--;
      if (Array[x][y] == 0) {
        int needgo = 1;
      }
    }
  }
}

void go_to_next_y() { //If goint to next y line when use this
  if (check_line == 0) {
    if (y_value == 1) {
      y_value = 0;
      check_line++;
    }
    if (y_value == 0) {
      y_value = 1;
      check_line++;
    }
  }
  if (check_line == 1) {
    y++;
    print_array();
    jump = 1;
    check_line = 0;
  }
}



