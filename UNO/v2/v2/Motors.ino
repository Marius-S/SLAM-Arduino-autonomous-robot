void turn_left(int m_speed) { //Turn robot left
  if (motors == 1) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    analogWrite(11, m_speed);
    analogWrite(3, m_speed);
    delay(500);
    analogWrite(11, 0);
    analogWrite(3, 0);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
}

void turn_right(int m_speed) {//Turn robot right
  if (motors == 1) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    analogWrite(11, m_speed);
    analogWrite(3, m_speed);
    delay(700);
    analogWrite(11, 0);
    analogWrite(3, 0);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
}

void go_straight(int m_speed) {//Go straight
  if (motors == 1) {
    digitalWrite(13, LOW);
    digitalWrite(8, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(9, LOW);
    analogWrite(11, m_speed + 10);
    analogWrite(3, m_speed);
    delay(500);
    analogWrite(11, 0);
    analogWrite(3, 0);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
}

void stop_motors() {//Full stop
  if (motors == 1) {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    analogWrite(11, 0);
    analogWrite(3, 0);
  }
}
