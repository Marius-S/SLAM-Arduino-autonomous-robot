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

//Variables for engine movements
int x1 = 0;
int y1 = 0;
int x2 = 0;
int y2 = 0;
int x3 = 0;
int y3 = 0;
int Score = 0;

void setup() {
  Serial.begin(9600); //Begin serial port 9600
  Serial.println("Starting Dijkstra algorithm"); //Message to Serial that Arduino started
}

void loop() {
  Obstacles(7);
  if (start == 1) { //If loop is available to start
    Array[0][0] = 1; //Primary point value
    //while ((y != 9) || (x != 0)) {
    while ((y != 3) || (x != 5)) {
      xPrev = x;
      yPrev = y;
      FindMin(); //Find minimum value
      MovingCicle(x, y); //Check around selected point
    } //End of loop while final point doesn't reach
    //Serial.println("---Printing values---");
    //PrintAllValues(); //Print squares values
    //Serial.println("---Printing map---");
    //PrintMap(); //Print Map with map values
    start = 0; //At the end stop loop cicle
  } //End of loop check
} //End of main loop
