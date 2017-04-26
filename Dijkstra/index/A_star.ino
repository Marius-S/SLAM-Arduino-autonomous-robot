void FindMinA() { //Finding minimum value in Array
  //Serial.println("Starting minimum finding funkction");
  minimum = 999; //Minimum variable which we will return
  int tempX = 0; //Temporary X value for checking
  int tempY = 0; //Temporary Y value for checking
  int mathX = 0;
  int mathY = 0;
  while (tempX <= MaxX) { //Checking if X reached max
    while (tempY <= MaxY) { //Checking if Y reached max
      if (Array[tempX][tempY] >= 1) { //Checking only places which has value
        //if (Array[tempX][tempY] < minimum) { //If place is bigger than minimum
          if (ArrayMap[tempX][tempY] != 3) { //Don't do anything if point analyzed

            mathX = 0;
            mathY = 0;
            if (TargetX > tempX){
              mathX = TargetX - tempX;
            }else{
              mathX = tempX - TargetX;
            }
             if (TargetY > tempY){
              mathY = TargetY - tempY;
            }else{
              mathY = tempY - TargetY;
            }
            if((mathX + mathY) < minimum){
            minimum = mathX + mathY;
            
            //minimum = Array[tempX][tempY]; //Minimum becomes min place value
            x = tempX; //x becomes equal to temporary value
            y = tempY; //y becomes equal to temporary value
            }
          //} //End of checking if point analyzed
        } //End of checking if place is bigger than minimum
      } // End of checking if place has value
      tempY++; //Increasing X value in cicle
    } //End of checking if Y reached max
    tempX++; //Increasing X value in cicle
    tempY = 0; //Retrun tempY value to zero
  } //End of checking if X reached max
    Serial.print("Minimum function value: ");
    Serial.println(minimum);
    Serial.println(mathX);
    Serial.println(mathY);
    Serial.println(minimum);
} //End of funkction
