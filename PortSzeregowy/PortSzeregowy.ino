#define zielona 8
#define czerwona 9
 
void setup() {
  Serial.begin(9600); //Uruchomienie komunikacji
  
  pinMode(zielona, OUTPUT); //Konfiguracja wyjść
  pinMode(czerwona, OUTPUT);
  
  digitalWrite(zielona, LOW); //Wyłączamy diody
  digitalWrite(czerwona, LOW);
}
 
void loop() {
  if(Serial.available() > 0) { //Czy Arduino odebrało dane
    
    //Jeśli tak, to odczytujemy je do znaku końca linii i zapisz w zmiennej odebraneDane
    String odebraneDane = Serial.readStringUntil('\n');
    int wybranaDioda = odebraneDane == "zielona" ? zielona : odebraneDane == "czerwona" ? czerwona : NULL;

    if (wybranaDioda == NULL) {
      Serial.println("Wpisz \"zielona\" lub \"czerwona\", Misiu Pysiu!");
      return;
    }

    digitalWrite(wybranaDioda, HIGH);
    delay(1000);
    digitalWrite(wybranaDioda, LOW);
  }
}