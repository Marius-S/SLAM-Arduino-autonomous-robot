//TODO Need to create engine movments
int Array[10][10] = {{}}; //Our area array
int ArrayMap[10][10] = {{}}; //Our area array which we use for map draw
int ArObs[10][10] = {{}}; //Our area array of obstacles
int start = 1; //This variable helps to use loop only one single time
int x = 0; //Array X value
int y = 0; //Array Y value
int MaxX = 9; //Maximum X value
int MaxY = 9; //Maximum Y value
int minimum = 0; //Minimum variable which we will return
int value = 0; //Current point value which we will use to add to near points
int xPrev = 0;
int yPrev = 0;

//Target values
int TargetX = 0;
int TargetY = 9;

//Variables for engine movements
int x1 = 0;
int y1 = 0;
int x2 = 0;
int y2 = 0;
int x3 = 0;
int y3 = 0;
int Score = 0;

//A start random
int obstaclesz = 0;
int AllMap = 1;
long MainScore = 0;
int counter = 1;
int min_c = 0;
int min_c2 = 0;
//End of A star random

void setup() {
  Serial.begin(9600); //Begin serial port 9600
  Serial.println("Starting Dijkstra algorithm"); //Message to Serial that Arduino started
}

void loop() {
    Obstacles(obstaclesz);
    if (start == 1) { //If loop is available to start
      Array[0][0] = 1; //Primary point value
      while (AllMap == 1) {
       
        TargetX = random(0, 9);
        TargetY = random(0, 9);
        while (Array[TargetX][TargetY] != 0) {
          if (min_c2 <= 100) {
            TargetX = random(0, 9);
            TargetY = random(0, 9);
            min_c2++;
          } else {
            Array[TargetX][TargetY] = 5;
            y = TargetY;
            x = TargetX;
            AllDone();
          }
        }
        while ((y != TargetY) || (x != TargetX)) {
          if (minimum == 999) {
            min_c = min_c + 1;
          } else {
            min_c = 0;
          }
          if (min_c >= 5) {
            start = 0;
            x = TargetX;
            y = TargetY;
          } else {
            xPrev = x;
            yPrev = y;
            FindMinA(); //Find minimum value -- Dijsktra
            MovingCicle(x, y); //Check around selected point
          }
        } //End of loop while final point doesn't reach
        //Serial.println(Score);
        MainScore = MainScore + Score;
        Score = 0;
        Serial.println(MainScore);
      }
      Serial.println(MainScore);
      
      ClearInfo();
      ClearInfo2();
      //Score = 0;
      x1 = 0;
      y1 = 0;
      x2 = 0;
      y2 = 0;
      x3 = 0;
      y3 = 0;
      x = 0; //Array X value
      y = 0; //Array Y value
      minimum = 0; //Minimum variable which we will return
      value = 0; //Current point value which we will use to add to near points
      xPrev = 0;
      yPrev = 0;
      //Serial.println(MainScore);
      AllMap = 1;
      counter--;
    } //End of loop check
    counter = 0;
    MainScore = 0;
    obstaclesz--;
  
  start = 0;
} //End of main loop
