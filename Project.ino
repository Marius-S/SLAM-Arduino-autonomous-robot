const int pingPin = 6; 

int x = 1;
int ultra_control = 1;
int turn_left_int = 0;
int go = 1;
int stop_motors_int = 0;
int circle=1;


unsigned long previousTime = 0;
byte seconds;
byte minutes;
byte hours;

long duration, cm;

void setup() {
  Serial.begin(9600);
  Serial.println();

  pinMode(12, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(13, OUTPUT); 
  pinMode(8, OUTPUT); 
}

void loop(){
  time_c();
  title();
  while (circle <= 3)
  {
  time_c();
  ultrasonic();
   if(cm<10){
    turn_left_int=1;
    stop_motors_int=1;
    stop_motors();
    delay(500);  
    turn_left();
    circle++;
  }
  else{
    go_straight();
    circle=1;
  }
  }
  check_circle();
  
  delay(600);
   digitalWrite(8, HIGH);   
   digitalWrite(9, HIGH);   
}

void title(){
  if (x != 1)
  {
  }
  else
  {
  Serial.println("Author: Marius Smigelskas");
  Serial.println("VDU 2016");
  x++;
  }
}

void time_c(){
  if (millis() >= (previousTime)  ) 
  {
    previousTime = previousTime + 1000;
    seconds = seconds +1;
      if (seconds == 60)
      {
        seconds = 0;
        minutes = minutes +1;
      }
      if (minutes == 60)
      {
        minutes = 0;
        hours = hours +1;
      }
      if (hours == 13)
      {
        hours = 1;
      }
  } 
}

void ultrasonic(){
  if (ultra_control==1){
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  delay(100);  
  }
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}

void turn_left(){
  if(turn_left_int==1){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH); 
    digitalWrite(8, LOW);   
    digitalWrite(9, LOW);   
    delay(500);
    digitalWrite(8, HIGH);   
    digitalWrite(9, HIGH); 
    time_print();
    Serial.println ("Turning left");
    turn_left_int=0;
    delay(5000);
    //go = 1;
    //go_straight();
  }
}

void go_straight(){
    
      digitalWrite(13, LOW); 
      digitalWrite(8, LOW);   
      analogWrite(11, 255);   
      digitalWrite(12, HIGH); 
      digitalWrite(9, LOW);   
      analogWrite(3, 255);   
      go = 0;
      time_print();
      Serial.println ("Going straight");
      ultra_control=1;
      
  
}

void stop_motors(){ 
  if (stop_motors_int==1){
    digitalWrite(8, HIGH);   
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);   
    digitalWrite(9, HIGH); 
    time_print();
    delay(500);
    Serial.println ("Full stop");
    stop_motors_int=0;
  }   
}

void check_circle(){
  
    digitalWrite(8, HIGH);   
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);   
    digitalWrite(9, HIGH); 
    time_print();
    Serial.println ("I'm stuck");
    delay(999999999999999999999);
  
}

void time_print(){
  Serial.print (hours, DEC);
  Serial.print (":");
  Serial.print (minutes,DEC);
  Serial.print (":");
  Serial.print(seconds,DEC);
  Serial.print (" ");
}





  

  


