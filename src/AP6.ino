/* Ioannis Christodoulakis, Thomas Ammann, 22.05.2017, 6301 Zug CH 
   Reakionsspiel AP4. Spielerauswahl */

// Variablen
int Re_Ze1,
    Re_Ze2;

char Pu_Za1 = 0,
     Pu_Za2 = 0;
     
// Konstanten
const char P_S1 = 6,
           P_S2 = 7;

// I/O
void setup() {
  // Ausgaenge
  pinMode(P_S1, OUTPUT);
  pinMode(P_S2, OUTPUT);

}

// Hauptprogramm
void loop() {
  // Auswertung
 if(Re_Ze1 > Re_Ze2){
  digitalWrite(P_S1, HIGH);
  delay(10);
  digitalWrite(P_S1, LOW);
  Pu_Za1++;
 }
 else if(Re_Ze1 < Re_Ze2){
  digitalWrite(P_S2, HIGH);
  delay(10);
  digitalWrite(P_S2, LOW);
  Pu_Za2++;
 }
 
}
