//This is my algorith how robot should find best way to drive throw area with obstacles

void algo_1() {
  int z_value = 0; //Describes side into which robot going in line in Algo-1 algorithm, 0 - right, 1 - left
  int line = 0; //Value which describes if line is total analyzed, 0 - no, 1 - yes
  int check = 0 //Calculate how many times line used, 0 not used, 1 - drived, 2 - checked again

}

void check_line(int y, int c) {
  if (y == 0) {
    for (int z = 0; z != 9; z++) {
      x = check_point(z);
      if (x == 1) {
        if (check = 0) { // Check if line has been drived
          check = 1;
          z_value = 1;
          obstacle();

        }
        if (check = 1) { // Check if line has been drived
          check = 0;
          z_value = 0;
          obstacle();
          
          
        }
      }
    }
  }
  if (y == 1) {

  }
}

void check_point(int z) {
  int t = 0; //true or false variable
  if (Array[z][y] == 0) {
    t = 1;
  }
  return t;
}

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
    //go_straight(motor_speed);
  }


  if ((x == 9) or (x == 0)) {
    while ((x != 9) or (x != 0) or (Array[x][y] != 2)) {
      if (y_value == 1) {
        x++;
      } else {
        x--;
      }
      x--;
     // if (Array[x][y] == 0) {
        int needgo = 1;
        //Serial.print("Praleidai");
      }
    }
  }
 
}

