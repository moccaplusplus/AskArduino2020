#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
}
 
void loop() {
  int refreshRate = analogRead(A5);
  digitalWrite(LED_PIN, HIGH);
  delay(refreshRate);
  digitalWrite(LED_PIN, LOW);
  delay(refreshRate);
}
