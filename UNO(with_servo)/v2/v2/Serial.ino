void listener() { //Read Serial monitor
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch == 'P') //If 'P' print grid
    {
      print_array();
    }
    if (ch == 'B') //If 'B' print as list
    {
      print_array_full();
    }
  }
}

void print_array() { //Print array as grid
  if (x == 0) {
    if (y >= 9) {
      x = 0;
      y = 0;
      //Array print
      while (y < 10) {
        while (x < 10) {
          Serial.print(Array[x][y]);
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

void print_array_full() { //Print array as line for map draw application
  if (x == 0) {
    if (y >= 9) {
      x = 0;
      y = 0;
      //Array print
      while (y < 10) {
        while (x < 10) {
          Serial.println(Array[x][y]);
          x++;
        }
        y++;
        x = 0;
        //Serial.println();
        endd = 1;
      }
    }
  }
}
