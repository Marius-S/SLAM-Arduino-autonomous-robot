void MoveToPoint(int xPos, int yPos) {
  while (yPrev != yPos) {
    if (yPrev > yPos) {
      if (ArObs[xPrev][yPrev - 1] == 2) {
        Serial.println("VARDUMP");
        AvoidX(xPos);
      } else {
        yPrev--;
        Serial.print("Moving y-- (");
        PrintStep();
      }
    }
    else {
      if (ArObs[xPrev][yPrev + 1] == 2) {
        Serial.println("VARDUMP");
        AvoidX(xPos);
      } else {
        yPrev++;
        Serial.print("Moving y++ (");
        PrintStep();
      }
    }
  }
  while (xPrev != xPos) {
    if (xPrev > xPos) {
      if (ArObs[xPrev - 1][yPrev] == 2) {
        Serial.println("VARDUMP");
        AvoidY(yPos);
      } else {
        xPrev--;
        Serial.print("Moving x-- (");
        PrintStep();
      }
    }
    else {
      if (ArObs[xPrev + 1][yPrev] == 2) {
        Serial.println("VARDUMP");
        AvoidY(yPos);
      } else {
        xPrev++;
        Serial.print("Moving x++ (");
        PrintStep();
      }
    }
  }
}

void PrintStep() {
  Serial.print(xPrev);
  Serial.print(" ");
  Serial.print(yPrev);
  Serial.println(")");
}

void AvoidX(int xPos) {
  xPrev--;
  Serial.print("Moving x-- (");
  PrintStep();
}

void AvoidY(int yPos) {
  yPrev--;
  Serial.print("Moving y-- (");
  PrintStep();
}

