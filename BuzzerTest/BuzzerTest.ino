#define BUZZER_PIN 25 // Replace with the GPIO pin you connected to the buzzer

void setup() {
  pinMode(BUZZER_PIN, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  digitalWrite(BUZZER_PIN, HIGH); // Turn the buzzer on
  delay(1000);                   // Wait for 1 second
  digitalWrite(BUZZER_PIN, LOW);  // Turn the buzzer off
  delay(1000);                   // Wait for 1 second
}
