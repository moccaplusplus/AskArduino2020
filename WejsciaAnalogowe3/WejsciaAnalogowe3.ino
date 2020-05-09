#define REFRESH_RATE 200

const float RATIO = 5.0/1024.0;
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int input = analogRead(A5);
  float voltage = input * RATIO;
  Serial.println(voltage);
  delay(REFRESH_RATE);
}