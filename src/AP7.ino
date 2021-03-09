/* Ioannis Christodoulakis, Thomas Ammann, 17.05.2017, 6301 Zug CH 
   Reakionsspiel AP7. Spielende */

// Variablen
char Pu_Za1,
     Pu_Za2;

// Konstanten
const char O_M1 = 8,
           O_M2 = 9;        

// I/O
void setup() {
  // Ausgaenge
  pinMode(O_M1, OUTPUT);
  pinMode(O_M2, OUTPUT);
  
}

// Hauptprogramm
void loop() {
  // Auswertung
  do{
                                   // Spilerauswahl, Zeitmessung, Zeitmessung-Auswertung
  }while(Pu_Za1 == 9 || Pu_Za2 == 9);
  if(Pu_Za1 == 9){
    digitalWrite(O_M1, HIGH);
  }
  else{
    digitalWrite(O_M2, HIGH);
  }
  
}
