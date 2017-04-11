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

int min_c = 0;

int AllMap = 1;

int counter = 2500;

//Variables for engine movements
int x1 = 0;
int y1 = 0;
int x2 = 0;
int y2 = 0;
int x3 = 0;
int y3 = 0;
int Score = 0;

long MainScore = 0;

int obstaclesz = 7;

void setup() {
  Serial.begin(9600); //Begin serial port 9600
  Serial.println("Starting Dijkstra algorithm"); //Message to Serial that Arduino started
}

void loop() {
  while (obstaclesz >= 0){
  Obstacles(obstaclesz);
  if (start == 1) {
  while (counter != 0){
   //If loop is available to start
    Array[0][0] = 1; //Primary point value
    //while ((y != 9) || (x != 0)) {
    while (AllMap == 1) {
      xPrev = x;
      yPrev = y;
      FindMin(); //Find minimum value -- Dijsktra
      MovingCicle(x, y); //Check around selected point
      AllDone();
    } //End of loop while final point doesn't reach
    
   
   // Serial.println("---Printing values---");
    //PrintAllValues(); //Print squares values
    //Serial.println("---Printing map---");
    //PrintMap(); //Print Map with map values
    //start = 0; //At the end stop loop cicle
    //Serial.print("Total value: ");
    //Serial.println(Score);
    MainScore = MainScore + Score;
   //End of loop check
ClearInfo();
ClearInfo2();
Score = 0;
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
AllMap = 1;
min_c = 0;
  counter--;
  }
  Serial.println(obstaclesz);
  Serial.println(MainScore);
  
  }
  counter = 2500;
  MainScore = 0;
  
  obstaclesz--;
  }
  start = 0;
} //End of main loop
