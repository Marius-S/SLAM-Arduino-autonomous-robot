void ultrasonic() {
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
  delayMicroseconds(2);
  digitalWrite(A3, HIGH);
  delayMicroseconds(5);
  digitalWrite(A3, LOW);
  pinMode(A2, INPUT);
  duration = pulseIn(A2, HIGH);
  cm = microsecondsToCentimeters(duration);
  delay(100);
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
