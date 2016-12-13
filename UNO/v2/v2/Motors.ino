void turn_left(int turn_time) { //Turn robot left
  analogWrite(11, 255);
  analogWrite(3, 255);
  delay(50);
  left.write(0);  // set servo to mid-point
  right.write(0);  // set servo to mid-point
  delay(turn_time);
  left.write(90);  // set servo to mid-point
  right.write(90);  // set servo to mid-point
  analogWrite(11, 0);
  analogWrite(3, 0);
}

void turn_right(int turn_time) {//Turn robot right
  analogWrite(11, 255);
  analogWrite(3, 255);
  delay(50);
  left.write(180);  // set servo to mid-point
  right.write(180);  // set servo to mid-point
  delay(turn_time);
  left.write(90);  // set servo to mid-point
  right.write(90);  // set servo to mid-point
  analogWrite(11, 0);
  analogWrite(3, 0);
}

void go_straight(int turn_time) {//Go straight
  analogWrite(11, 255);
  analogWrite(3, 255);
  delay(50);
  left.write(180);  // set servo to mid-point
  right.write(0);  // set servo to mid-point
  delay(turn_time);
  left.write(90);  // set servo to mid-point
  right.write(90);  // set servo to mid-point
  analogWrite(11, 0);
  analogWrite(3, 0);

}
