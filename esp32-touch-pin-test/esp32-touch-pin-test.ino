/*
 * Project: Capacitive Touch Sensor Control
 * Description: Reads a capacitive touch value from GPIO 27 and toggles 
 * an output on GPIO 2 based on a specific threshold.
 */

// Variable to store the raw touch sensor reading
int touchValue;

void setup() {
  Serial.begin(115200);
  
  // Set GPIO 2 as output (likely for an LED or relay)
  pinMode(2, OUTPUT);
}

void loop() {
  // Read the capacitive touch value from pin 27
  touchValue = touchRead(27);
  
  // Serial output for debugging:
  // Prints the raw touch value, a fixed threshold (1416), 
  // and the current state of pin 2 effectively scaled for a graph
  Serial.printf("%d 1416 %d \n", touchValue, 1200 + (digitalRead(2) * 500));
  
  delay(100);
  
  // Threshold logic: If touch value is below 1416 (meaning a touch is detected), 
  // turn the output HIGH, otherwise turn it LOW.
  if (touchValue <= 1416) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}
