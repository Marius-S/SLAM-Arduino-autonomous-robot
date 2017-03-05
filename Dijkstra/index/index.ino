int Array[10][10] = {{}}; //Our area array
int ArObs[10][10] = {{}}; //Our area array of obstacles
int start = 1; //This variable helps to use loop only one single time
int x = 0; //Array X value
int y = 0; //Array Y value
int MaxX = 9; //Maximum X value
int MaxY = 9; //Maximum Y value
int minimum = 0; //Minimum variable which we will return

void setup() {
  Serial.begin(9600); //Begin serial port 9600
  Serial.println("Starting Dijkstra algorithm"); //Message to Serial that Arduino started
}

void loop() {
  if(start == 1){ //If loop is available to start
  Array[5][5]=2;
  Array[2][2]=5;
  FindMin();
  Serial.println(minimum);
  start--;
  } //End of loop check
  
  if(start == 1) //If loop is available to start
  {
    if((x >= 0) && (x <= 9)) //Checking if X is in it range
    {
      if((x >= 0) && (x <= 9)) //Checking if Y is in it range
      {
        
        
      } //End of Y range check
    } //End of X range check
    start--; //Stoping main loop
  } //End of loop check
}

void MovingCicle(){
  if 
}

