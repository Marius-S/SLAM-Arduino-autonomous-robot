void MoveToPoint(int xPos, int yPos) {
  while (yPrev != yPos) {
    if (yPrev > yPos) {
      yPrev--;
      Serial.print("Moving y-- (");
      PrintStep();
    }
    else {
      yPrev++;
      Serial.print("Moving y++ (");
      PrintStep();
    }
  }
  while (xPrev != xPos) {
    if (xPrev > xPos) {
      xPrev--;
      Serial.print("Moving x-- (");
      PrintStep();
    }
    else {
      xPrev++;
      Serial.print("Moving x++ (");
      PrintStep();
    }
  }
}

void PrintStep() {
  Serial.print(xPrev);
  Serial.print(" ");
  Serial.print(yPrev);
  Serial.println(")");
}

