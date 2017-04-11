void FindMin() { //Finding minimum value in Array
  //Serial.println("Starting minimum finding funkction");
  minimum = 999; //Minimum variable which we will return
  int tempX = 0; //Temporary X value for checking
  int tempY = 0; //Temporary Y value for checking
  while (tempX <= MaxX) { //Checking if X reached max
    while (tempY <= MaxY) { //Checking if Y reached max
      if (Array[tempX][tempY] >= 1) { //Checking only places which has value
        if (Array[tempX][tempY] < minimum) { //If place is bigger than minimum
          if (ArrayMap[tempX][tempY] != 3) { //Don't do anything if point analyzed
            minimum = Array[tempX][tempY]; //Minimum becomes min place value
            x = tempX; //x becomes equal to temporary value
            y = tempY; //y becomes equal to temporary value
          } //End of checking if point analyzed
        } //End of checking if place is bigger than minimum
      } // End of checking if place has value
      tempY++; //Increasing X value in cicle
    } //End of checking if Y reached max
    tempX++; //Increasing X value in cicle
    tempY = 0; //Retrun tempY value to zero
  } //End of checking if X reached max
  Serial.print("Minimum function value: ");
  Serial.println(minimum);
} //End of funkction

void Check(int x, int y) { //Check if variable confirms all requirements
  if ((ArrayMap[x][y] != 2) || (ArrayMap[x][y] != 3)) { //If point no obstatacle and
    //still do not analyzed
    Serial.print("Checking X:");
    Serial.print(x);
    Serial.print(" Y:");
    Serial.print(y);
    Serial.print(" - ");
    if ((x <= MaxX) && (x >= 0)) { //Check if x is not over max
      if ((y <= MaxY) && (y >= 0)) { //Check if y is not over max
        if (ArObs[x][y] == 2) { //Check if point exist in obstacles map
          ArrayMap[x][y] = 2; //If exists than mark it as object in Draw map
          Serial.println("Obstacle exists in square");
        } //End of check if point exist in obstacles map
        else { //If not obstacle
          if (ArrayMap[x][y] == 0) { //If point not analyzed yet
            ArrayMap[x][y] = 1; //Mark it as free space in Draw map
            Array[x][y] = value + 1; //Get space value current value +1
          } //End of check if point not analyzed yet
          Serial.println("All clear during check - free space");
        } //End of if point is not obstacle
      } //End of if y is not over max
      else { //If y out of range
        Serial.println("Out of range");
      } //End of if y out of range
    } //End of if x is not over max
    else { //If x out of range
      Serial.println("Out of range");
    } //End of if x out of range
  } //End of check if point no obstatacle and still do not analyzed
} //End of function

void PrintAllValues() { //Prints all values of array of points
  int tempX = 0; //Temporary X value for checking
  int tempY = 0; //Temporary Y value for checking
  while (tempX <= MaxX) { //Checking if X reached max
    while (tempY <= MaxY) { //Checking if Y reached max
      Serial.print("Value of:[");
      Serial.print(tempX);
      Serial.print("][");
      Serial.print(tempY);
      Serial.print("]=");
      Serial.println(Array[tempX][tempY]);
      tempY++; //Increasing X value in cicle
    } //End of checking if Y reached max
    tempX++; //Increasing X value in cicle
    tempY = 0; //Retrun tempY value to zero
  } //End of checking if X reached max
} //End of function

void PrintMap() { //Prints all values of array of points
  int tempX = 0; //Temporary X value for checking
  int tempY = 0; //Temporary Y value for checking
  while (tempX <= MaxX) { //Checking if X reached max
    while (tempY <= MaxY) { //Checking if Y reached max
      Serial.print("Value of:[");
      Serial.print(tempX);
      Serial.print("][");
      Serial.print(tempY);
      Serial.print("]=");
      Serial.println(ArrayMap[tempX][tempY]);
      tempY++; //Increasing X value in cicle
    } //End of checking if Y reached max
    tempX++; //Increasing X value in cicle
    tempY = 0; //Retrun tempY value to zero
  } //End of checking if X reached max
} //End of function

void MovingCicle(int x, int y) {
  MoveToPoint(x, y);
  value = Array[x][y]; //Current point value
  ArrayMap[x][y] = 3; //Select point as full analized and already moved around it
  Check(x, y); //Check all points around current
  //Serial.println("Engine - turn left");
  Score = Score + 1;
  Check(x + 1, y);
  //Serial.println("Engine - turn left");
  Score = Score + 1;
  Check(x - 1, y);
  //Serial.println("Engine - turn left");
  Score = Score + 1;
  Check(x, y + 1);
  //Serial.println("Engine - turn left");
  Score = Score + 1;
  Check(x, y - 1);
  //Serial.println("Engine - turn left");
  Score = Score + 1;
  Check(x - 1, y - 1);
  //Serial.println("Engine - turn left");
  Score = Score + 1;
  Check(x + 1, y + 1);
}
