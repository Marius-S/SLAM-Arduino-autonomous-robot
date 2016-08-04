void turn_left() {
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  analogWrite(11, 155);
  analogWrite(3, 155);
  delay(500);
  analogWrite(11, 0);
  analogWrite(3, 0);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void turn_right() {
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  analogWrite(11, 155);
  analogWrite(3, 155);
  delay(500);
  analogWrite(11, 0);
  analogWrite(3, 0);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void go_straight() {
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  analogWrite(11, 155);
  analogWrite(3, 155);
}

void stop_motors() {
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  analogWrite(11, 0);
  analogWrite(3, 0);
}
