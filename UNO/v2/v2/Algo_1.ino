void algo_1() {
  listener(); //Listen in entered value into Serial monitor
  delay(1000); //Delay between robot moves
  while (endd == 0) { //Chech is robot must stop or can go
    jump--; //Every loop jump variable starts from 0
    obstacle_algo(); //Checking if obstacle exist in front of robot
    if (y == 10) {
      print_array();
      Serial.println(Steps);
    } else {
      print_steps();
      Array_rez[x][y] = 1;
      if ((x == 9) && (y_value == 0)) { //if robot is near the wall, when change direction
        go_to_next_y();
        Array_rez[x][y]=1;
      }
      if ((x <= 0) && (y_value == 1)) { //if robot is near the wall, when change direction
        Array_rez[x][y]=1;
        go_to_next_y();
      }
      if ((y_value == 0) && (jump != 1)) { //if robot isn't near the wall or object
        x++;
        Array_rez[x][y]=1;
        Steps++;
      }
      if ((y_value == 1) && (jump != 1)) { //if robot isn't near the wall or object
        x--;
        Array_rez[x][y]=1;
        Steps++;
      }
    }
  }
}

void obstacle_algo() {
  int trigger = 0;
  int straight = 1;
  //Obstacle - 1
  if ((Array[x][y] == 2) && (Array[x - 1][y + 1] == 2)) {
    Serial.println("Obstacle-1");
    Array_rez[x][y]=2;
    go_to_next_y();
    x--;
    Steps++;
    trigger = 1;
    straight = 0;
  }

  if ((x == 10) && (trigger != 1) && (Array[x - 1][y + 1] == 2)) {
    Serial.println("Obstacle-2");
    //y++;
    Array_rez[x][y]=2;
    go_to_next_y();
    x--;
    Steps++;
    if (y_value == 0) {
      Array_rez[x][y]=2;
      y_value = 1;
      x--;
      Steps++;
      Steps++;
      Steps++;
    } else
    {
      y_value = 0;
      x--;
      Steps++;
      Steps++;
      Steps++;
    }
    trigger = 1;
    straight = 0;
  }

  if ((Array[x][y] == 2) && (trigger != 1)) {
    Serial.println("Obstacle-3");
    Array_rez[x][y]=2;
    if (y_value == 1) {
      Serial.println("Going to next line Y1");
      x++;
      Steps++;
      go_to_next_y();
    }
    else {
      Serial.println("Going to next line Y0");
      x--;
      Steps++;
      go_to_next_y();
    }
    straight = 0;
    trigger = 1;
  }

  if ((Array[x][y + 1] == 2) && (trigger != 1)) {
    if ((x == 9) || (x == 0)) {
      Serial.println("Obstacle bottom");
      if (y_value == 1) {
        if (x == 9) {
          x = 8;
        }
        if (x == 0) {
          x = 1;
        }
        go_to_next_y();
      }
      if (y_value == 0) {
        if (x == 9) {
          x = 8;
        }
        if (x == 0) {
          x = 1;
        }
        go_to_next_y();
      }
    }
  }
}

void go_to_next_y() { //If goint to next y line when use this
  if (line[y] != 2) {
    if (y_value == 0) {
      Serial.println("JUMP Y0");
      y_value = 1;
      Steps++;
      Steps++;
      Steps++;
      //check_line++;
      jump = 1;
      line[y]++;
    } else
    {
      Serial.println("JUMP Y1");
      y_value = 0;
      Steps++;
      Steps++;
      Steps++;
      //check_line++;
      line[y]++;
      jump = 1;
    }
  }
  if (line[y] == 2) {
    y++;
    Steps++;
    Steps++;
    Steps++;
    Serial.println("JUMP");
    jump = 1;
    check_line = 0;
    if (y_value == 0) {
      y_value = 1;
    } else
    {
      y_value = 0;
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
