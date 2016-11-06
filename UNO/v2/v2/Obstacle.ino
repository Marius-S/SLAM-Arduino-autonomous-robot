void obstacle() {
  //If I can't go anymore and I must go back
  if ((Array[x][y] == 2) && (Array[x - 1][y + 1] == 2)) {
    kill();
    Serial.println("Obstacle-1");
    print_steps();
    if (y_value == 0) {
      y_value = 1;
    }
    if (y_value == 1) {
      y_value = 0;
    }
  }

  //Do not know well about this part of code
  while ((Array[x][y + 1] == 2) && (x == 9) && ( y == 0) && ((Array[x - 1][y] == 1))) {
    Serial.print("Obstacle-2");
    y_value = 1;
    x = 8;
    y++;
  }

  //Simple solution
  while (Array[x][y] == 2) {
    Serial.println("Obstacle-3");
    y++;
    x--;
  }
}

