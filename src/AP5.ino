/* Ioannis Christodoulakis, Thomas Ammann, 23.05.2017, 6301 Zug CH 
   Reakionsspiel AP5. Zeitmessung */

// Variablen
char          X,
              Spielersignal,
              Zms[2],               // Zeitmessungstart
              Spieler[2];
int           Zufallszeit,
              Re_Ze1,
              Re_Ze2;
unsigned long Anfangszeit,       // Anfangszeit der Zeitmessung
              Endzeit,           // Endzeit der Zeitmessung
              Zeit;

// Konstanten
const char Q_S1 = 4,
           Q_S2 = 5,
           O_M1 = 8,
           O_M2 = 9;

// I/O
void setup() {
  // Eingaenge
  pinMode(Q_S1, INPUT);
  pinMode(Q_S2, INPUT);
  // Ausgaenge
  pinMode(O_M1, OUTPUT);
  pinMode(O_M2, OUTPUT);
  
  randomSeed(analogRead(0));  // analogPin0 darf nicht angeschlossen sein!

}

// Hauptprogramm
void loop() {
   // Auswertung
   for(X = 0; X < 2; X++){
     Zufallszeit = random(4001);
     Anfangszeit = millis();
     do{
       Spielersignal = digitalRead(EingangSpieler[X]);
       Zeit = millis();
       if(Zeit >= Anfangszeit + Zufallszeit + 1000){
         digitalWrite(Zms[X], HIGH);
       }
     }while(Spielersignal == 0);
     Endzeit = millis();
     if(Endzeit >= Anfangszeit + Zufallszeit + 1000){
       Reaktionszeit = Endzeit - Anfangszeit - Zufallszeit - 1000;
     }
     else{
       Reaktionszeit = 10000;
       digitalWrite(O_M1, HIGH);
       digitalWrite(O_M2, HIGH);
       delay(300);
       digitalWrite(O_M1, LOW);
       digitalWrite(O_M2, LOW);
       delay(300);
       digitalWrite(O_M1, HIGH);
       digitalWrite(O_M2, HIGH);
       delay(300);
       digitalWrite(O_M1, LOW);
       digitalWrite(O_M2, LOW);
     }
     if(Spieler[X] = 1){
       Re_Ze1 = Reaktionszeit;
     }
     else{
       Re_Ze2 = Reaktionszeit;
     }
     digitalWrite(Zms[X], LOW);
   }

 
}
