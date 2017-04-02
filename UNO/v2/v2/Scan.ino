//void scan() { //scaning obsticles
//  int scan_f = 0;//Scan front
//  int scan_l = 0;//Scan lover after robot
//  ultrasonic();
//  if (cm < 20) {
//    scan_f = 1; //Obstacle in front
//    Serial.println("In front");
//    turn_right(turn);
//    delay(500);
//    ultrasonic();
//    if (cm < 20) {
//      Serial.println("In right");
//      scan_l = 1;
//      Array[x][y + 1] = 2;
//      x--;
//      if (y_value == 0) {
//        y_value = 1;
//        x--;
//      } else
//      {
//        y_value = 0;
//        x--;
//      }
//    } else {
//      go_straight(turn);
//      turn_left(turn);
//      if (y_value == 1) {
//        Array[x + 1][y] = 2;
//        y++;
//        x++;
//      }
//      else {
//        Array[x - 1][y] = 2;
//        y++;
//        x--;
//      }
//    }
//  }
//}

