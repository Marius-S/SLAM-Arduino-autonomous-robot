void algo_1() {

  listener(); //Listen in entered value into Serial monitor
  delay(1000); //Delay between robot moves
  while (endd == 0) { //Chech is robot must stop or can go
   // Serial.println("1");
    jump--; //Every loop jump variable starts from 0
    //scan();
    obstacle_algo(); //Checking if obstacle exist in front of robot
   // Serial.println("1,2");
    print_steps();
    Array[x][y] = 1;
    if ((x == 9) && (y_value == 0)) { //if robot is near the wall, when change direction
      //y_value = 1; //change direction
      go_to_next_y();
     // Serial.println("2");
    }
    if ((x <= 0) && (y_value == 1)) { //if robot is near the wall, when change direction
     // y_value = 0; //change direction
      go_to_next_y();
     // Serial.println("3");
    }
    if ((y_value == 0) && (jump != 1)) { //if robot isn't near the wall or object
      x++;
     // Serial.println("4");
    }
    if ((y_value == 1) && (jump != 1)) { //if robot isn't near the wall or object
      x--;
     // Serial.println("5");
    }
  }
}

void obstacle_algo() {
  int trigger = 0;
  int straight = 1;
  //Obstacle - 1
  if ((Array[x][y] == 2) && (Array[x - 1][y + 1] == 2)) {
    Serial.println("Obstacle-1");
     go_to_next_y();
    x--;
//    if (y_value == 0) {
//      y_value = 1;
//      x--;
//    } else
//    {
//      y_value = 0;
//      x--;
//    }
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
    trigger = 1;
    straight = 0;
  }

  //Obstacle - 3
  if ((Array[x][y] == 2) && (trigger != 1)) {
    Serial.println("Obstacle-3");
   
    if (y_value == 1) {
      Serial.println("Going to next line Y1");
      x++;
      go_to_next_y();
    }
    else {
      Serial.println("Going to next line Y0");
      x--;
      go_to_next_y();
    }
    straight = 0;
    trigger = 1; 
  
  }

   if ((Array[x][y+1] == 2) && (trigger != 1)) {
    if ((x==9)||(x==0)){
    Serial.println("Obstacle bottom");
    if (y_value == 1) {
    if (x==9){
      x=8;
    }
    if (x==0){
      x=1;
    }
     go_to_next_y();
//x++;
     
    }
    if (y_value == 0) {
      if (x==9){
      x=8;
    }
    if (x==0){
      x=1;
    }
       
     go_to_next_y();
//x--;
     
    }
    }
   }
  

  if ((straight == 1) && (endd == 0)) {
  }

  //Some improvisations
//  if ((x == 9) or (x == 0)) {
//    while ((x != 9) or (x != 0) or (Array[x][y] != 2)) {
//      if (y_value == 1) {
//        x++;
//      } else {
//        x--;
//      }
//      x--;
//      if (Array[x][y] == 0) {
//        int needgo = 1;
//      }
//    }
//  }
}

void go_to_next_y() { //If goint to next y line when use this
  if (check_line != 2) {
    if (y_value == 0) {
      Serial.println("JUMP Y0");
      y_value = 1;
      check_line++;
      jump = 1;
    }else
    {
      Serial.println("JUMP Y1");
      y_value = 0;
      check_line++;
      jump = 1;
    }
  }
  if (check_line == 2) {
    y++;
    Serial.println("JUMP");
    print_array();
    jump = 1;
    check_line = 0;
    if (y_value == 0) {
      //Serial.println("JUMP Y0");
      y_value = 1;
      //check_line++;
      //jump = 1;
    }else
    {
     // Serial.println("JUMP Y1");
      y_value = 0;
      //check_line++;
     // jump = 1;
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


