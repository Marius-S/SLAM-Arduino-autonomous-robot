void FindMin(){ //Finding minimum value in Array
  Serial.println("Starting minimum finding funkction");
  minimum = 999; //Minimum variable which we will return
  int tempX = 0; //Temporary X value for checking
  int tempY = 0; //Temporary Y value for checking
  while(tempX <= MaxX){ //Checking if X reached max
    while(tempY <= MaxY){ //Checking if Y reached max
      if(Array[tempX][tempY] >= 1){ //Checking only places which has value
        if(Array[tempX][tempY] < minimum){ //If place is bigger than minimum
          minimum = Array[tempX][tempY]; //Minimum becomes min place value
        } //End of checking if place is bigger than minimum
      } // End of checking if place has value
      tempY++; //Increasing X value in cicle
    } //End of checking if Y reached max
    tempX++; //Increasing X value in cicle
    tempY = 0; //Retrun tempY value to zero
  } //End of checking if X reached max
} //End of funkction
