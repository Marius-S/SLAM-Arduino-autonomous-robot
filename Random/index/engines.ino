void SelectMovement() {
  x3 = x2;
  y3 = y2;
  x2 = x1;
  y2 = y1;
  x1 = xPrev;
  y1 = yPrev;
  Serial.print("Line:");
  Serial.print(x1);
  Serial.print(",");
  Serial.print(y1);
  Serial.print("; ");
  Serial.print(x2);
  Serial.print(",");
  Serial.print(y2);
  Serial.print("; ");
  Serial.print(x3);
  Serial.print(",");
  Serial.print(y3);
  Serial.print(" | ");

  //Engines movements
  //1
  if ((x2 == x1) && (y2 == y1 + 1) && (x3 == x2) && (y3 == y2 + 1)) {
    Serial.print("Engine - straight | ");
    Score = Score + 1;
  }
  //2
  if ((x2 == x1) && (y2 == y1 - 1) && (x3 == x2) && (y3 == y2 - 1)) {
    Serial.print("Engine - straight | ");
    Score = Score + 1;
  }
  //3
  if ((x2 == x1 - 1) && (y2 == y1) && (x3 == x2 - 1) && (y3 == y2)) {
    Serial.print("Engine - straight | ");
    Score = Score + 1;
  }
  //4
  if ((x2 == x1 + 1) && (y2 == y1) && (x3 == x2 + 1) && (y3 == y2)) {
    Serial.print("Engine - straight | ");
    Score = Score + 1;
  }
  //5
  if ((x2 == x1) && (y2 == y1 + 1) && (x3 == x2 + 1) && (y3 == y2)) {
    Serial.print("Engine - turn right, straight | ");
    Score = Score + 2;
  }
  //6
  if ((x2 == x1) && (y2 == y1 + 1) && (x3 == x2 - 1) && (y3 == y2)) {
    Serial.print("Engine - turn left, straight | ");
    Score = Score + 2;
  }
  //7
  if ((x2 == x1) && (y2 == y1 - 1) && (x3 == x2 + 1) && (y3 == y2)) {
    Serial.print("Engine - turn left, straight | ");
    Score = Score + 2;
  }
  //8
  if ((x2 == x1) && (y2 == y1 - 1) && (x3 == x2 - 1) && (y3 == y2)) {
    Serial.print("Engine - turn right, straight | ");
    Score = Score + 2;
  }
  //9
  if ((x2 == x1 - 1) && (y2 == y1) && (x3 == x2) && (y3 == y2 + 1)) {
    Serial.print("Engine - turn right, straight | ");
    Score = Score + 2;
  }
  //10
  if ((x2 == x1 + 1) && (y2 == y1) && (x3 == x2) && (y3 == y2 + 1)) {
    Serial.print("Engine - turn left, straight | ");
    Score = Score + 2;
  }
  //11
  if ((x2 == x1 - 1) && (y2 == y1) && (x3 == x2) && (y3 == y2 - 1)) {
    Serial.print("Engine - turn left, straight | ");
    Score = Score + 2;
  }
  //12
  if ((x2 == x1 + 1) && (y2 == y1) && (x3 == x2) && (y3 == y2 - 1)) {
    Serial.print("Engine - turn right, straight | ");
    Score = Score + 2;
  }
  //13
  if ((x2 == x1) && (y2 == y1 - 1) && (x3 == x2) && (y3 == y2 + 1)) {
    Serial.print("Engine - turn left, turn left, straight | ");
    Score = Score + 3;
  }
  //14
  if ((x2 == x1) && (y2 == y1 + 1) && (x3 == x2) && (y3 == y2 - 1)) {
    Serial.print("Engine - turn left, turn left, straight | ");
    Score = Score + 3;
  }
  //15
  if ((x2 == x1 + 1) && (y2 == y1) && (x3 == x2 - 1) && (y3 == y2)) {
    Serial.print("Engine - turn left, turn left, straight | ");
    Score = Score + 3;
  }
  //16
  if ((x2 == x1 - 1) && (y2 == y1) && (x3 == x2 + 1) && (y3 == y2)) {
    Serial.print("Engine - turn left, turn left, straight | ");
    Score = Score + 3;
  }
}

