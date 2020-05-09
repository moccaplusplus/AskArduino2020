#define FIRST_PIN 8
#define LAST_PIN 12
#define MIN_VOL 0
#define MAX_VOL 1023
#define REFRESH_RATE 50

void setup() {
  for (int i = FIRST_PIN; i <= LAST_PIN; i++) pinMode(i, OUTPUT);
}
 
void loop() {
  int which = map(analogRead(A5), MIN_VOL, MAX_VOL, FIRST_PIN, LAST_PIN);
  for (int i = FIRST_PIN; i <= LAST_PIN; i++) digitalWrite(i, i == which ? HIGH : LOW);
  delay(REFRESH_RATE);
}
