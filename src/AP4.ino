/* Ioannis Christodoulakis, Thomas Ammann, 22.05.2017, 6301 Zug CH 
   Reakionsspiel AP4. Spielerauswahl */

// Variablen
char  EingangSpieler[2],
      Zms[2],              // Zeitmessungstart
      Spieler[2],
      Zufallszahl;

// Konstanten
const char Q_S1 = 4,
           Q_S2 = 5,
           O_M1 = 8,
           O_M2 = 9;

// I/O
void setup() {
  randomSeed(analogRead(0));

}

// Hauptprogramm
void loop() {
  Zufallszahl = random(100);
  // Auswertung
  if(Zufallszahl % 2 == 0){
   EingangSpieler[0] = Q_S1;
   EingangSpieler[1] = Q_S2;
   Zms[0] = O_M1;
   Zms[1] = O_M2;
   Spieler[0] = 1;
   Spieler[1] = 2;
  }
  else{
   EingangSpieler[0] = Q_S2;
   EingangSpieler[1] = Q_S1;
   Zms[0] = O_M2;
   Zms[1] = O_M1;
   Spieler[0] = 2;
   Spieler[1] = 1;
  }
 
}
