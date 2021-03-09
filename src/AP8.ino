/* Ioannis Christodoulakis, Thomas Ammann, 17.05.2017, 6301 Zug CH 
   Reakionsspiel AP7. Spielende */

// Variablen
char St_Si,
     Pu_Za1,
     Pu_Za2;

// Konstanten
const char S_S = 3,
           P_S1 = 6,
           P_S2 = 7,
           O_M1 = 8,
           O_M2 = 9,
           R_S = 10;
           

// I/O
void setup() {
  // Eingaenge
  pinMode(S_S, INPUT);
  
  // Ausgaenge
  pinMode(P_S1, OUTPUT);
  pinMode(P_S2, OUTPUT);
  pinMode(O_M1, OUTPUT);
  pinMode(O_M2, OUTPUT);
  pinMode(R_S, OUTPUT);

}

// Hauptprogramm
void loop() {
  // Auswertung
  do{
    St_Si = digitalRead(S_S);
  }while(St_Si == 0);
  St_Si = 0;
  digitalWrite(O_M1, LOW);    // Optische Meldung ausschalten
  digitalWrite(O_M2, LOW);
  Pu_Za1 = 0;                 // Punktzahl1 zurücksetzten
  Pu_Za2 = 0;                 // Punktzahl2 zurücksetzten
  digitalWrite(R_S, LOW);     // Anzeigen zurücksetzten
  delay(5);
  digitalWrite(P_S1, HIGH);
  digitalWrite(P_S2, HIGH);
  delay(50);
  digitalWrite(P_S1, LOW);
  digitalWrite(P_S2, LOW);
  digitalWrite(R_S, HIGH);

}
