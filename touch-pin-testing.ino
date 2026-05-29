int touchValue;
 
void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
}

void loop() {
  
  touchValue = touchRead(27);
  Serial.printf("%d 1416 %d \n", touchValue, 1200+(digitalRead(2)*500));
  delay(100);
  if (touchValue <= 1416) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}

