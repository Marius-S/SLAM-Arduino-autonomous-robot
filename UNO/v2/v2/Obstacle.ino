void obstacle() {
  int trigger = 0;
  //Obstacle - 1
  if ((Array[x][y] == 2) && (Array[x - 1][y + 1] == 2)) {
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
  }

    Serial.println("Obstacle-2");
    y++;
    x--;
      y_value = 1;
      x--;
    } else
    {
      y_value = 0;
      x--;
    }
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
  }
}

