void MoveToPoint(int xPos, int yPos){
  while(yPrev != yPos){
    if(yPrev > yPos){
      Serial.println("Moving y--");
      yPos++;
    }
    else{
      Serial.println("Moving y++");
      yPos--;
    }
  }
  while(xPrev != xPos){
    if(xPrev > xPos){
      Serial.println("Moving x--");
      xPos++;
    }
    else{
       Serial.println("Moving x++");
      xPos--;
    }
  }
}

