#define FIRST_PIN 8
#define LAST_PIN 11
#define MIN_EXP_VOL 366
#define MAX_EXP_VOL 1018
#define REFRESH_RATE 50

const int PIN_COUNT = LAST_PIN - FIRST_PIN + 1;

void setup() {
  // Serial.begin(9600);
  for (int i = FIRST_PIN; i <= LAST_PIN; i++) pinMode(i, OUTPUT);
}
 
void loop() {
  int voltage = analogRead(A5);
  int offCount = map(
    voltage, MIN_EXP_VOL, MAX_EXP_VOL, 0, PIN_COUNT);
  
  // Serial.println(voltage);
  // Serial.println(offCount);
  
  int i = 0;
  for (; i < offCount; i++) digitalWrite(FIRST_PIN + i, LOW);
  for (; i < PIN_COUNT; i++) digitalWrite(FIRST_PIN + i, HIGH);
  delay(REFRESH_RATE);
}