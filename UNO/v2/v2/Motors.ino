void turn_left(int turn_time) { //Turn robot left
  engine_start();
  delay(50);
  left.write(0);
  right.write(0);
  delay(turn_time);
  servo_stop();
  engine_stop();
}

void turn_right(int turn_time) {//Turn robot right
  engine_start();
  delay(50);
  left.write(180);
  right.write(180);
  delay(turn_time);
  servo_stop();
  engine_stop();
}

void go_straight(int turn_time) {//Go straight
  engine_start();
  delay(50);
  left.write(180);
  right.write(0);
  delay(turn_time);
  servo_stop();
  engine_stop();
}

void engine_stop() {
  analogWrite(11, 0);
  analogWrite(3, 0);
}

void engine_start() {
  analogWrite(11, 255);
  analogWrite(3, 255);
}

void servo_stop() {
  left.write(90);  // stop left servo
  right.write(90);  // stop right servo
}

