/* Projektnamen:           Reaktionsspiel
 * Dateinamen:             Veraenderung.ino
 * Entwickler:             Thomas Ammann, Ioannis Christodulakis
 * Datum:                  29.05.2017
 * Ort:                    6301 Zug, CH
 * Entwicklungsschritt:    Zusammenführung, 29.05.2017
 *                         Formatierung, 29.05.2017
 *                         Erweitung um Unterprogramm "Start_Taster" & "Blinken"
 * Letze Aenderungsdatum:  29.05.2017
*/

/* Variablen ------------------------------------------------------------------- */
bool          St_Si;             // Start-Signal

              
char          EingangSpieler[2],
              Spieler[2],
              Zms[2],
              Spielersignal;


char          Pu_Za1 = 0,        // Punktzahl1
              Pu_Za2 = 0;        // Punktzahl2
     
     
char          a,                 // für for-Schleife
              b,                 // für for-Schleife
              c,                 // für for-Schleife
              x;                 // für for-Schleife



unsigned long Anfangszeit,      // Anfangszeit der Zeitmessung
              Endzeit,          // Endzeit der Zeitmessung
              Zeit,
              Zufallszahl,      // zufaellig generierte Zahl
              Re_Ze1,           // Reaktionszeit1
              Re_Ze2,           // Reaktionszeit2
              Reaktionszeit,
              Zufallszeit;
/* ------------------------------------------------------------------------------ */




/* Konstanten ------------------------------------------------------------------- */
const char    S_S  = 3,         // Eingeange {
              Q_S1 = 4,
              Q_S2 = 5,         // }

              
              P_S1 = 6,         // Ausgaenge {
              P_S2 = 7,
              O_M1 = 8,
              O_M2 = 9,
              R_S  = 10;         // }
/* ------------------------------------------------------------------------------ */




/* Setup ------------------------------------------------------------------------ */
void setup() {
  
  /* Eingaenge ------------------------------------------------------------------ */
  pinMode(S_S,  INPUT);
  pinMode(Q_S1, INPUT);
  pinMode(Q_S2, INPUT);
  

  /* Ausgaenge ------------------------------------------------------------------ */
  pinMode(P_S1, OUTPUT);
  pinMode(P_S2, OUTPUT);
  pinMode(O_M1, OUTPUT);
  pinMode(O_M2, OUTPUT);
  pinMode(R_S, OUTPUT);
  

  /* Pin für Zufallszahl -------------------------------------------------------- */
  randomSeed(analogRead(0)); // analogPin0 darf nicht angeschlossen sein!


  /* Ausgabe der Werte ---------------------------------------------------------- */
  // Serial.begin();

}
/* ------------------------------------------------------------------------------ */




/* Unterprogramme --------------------------------------------------------------- */
// Start-Signal einlesen
void Start_Taster(char Start_Pin){
  do{                                   // Start-Signal einlesen
    St_Si = digitalRead(Start_Pin);
    // Serial.print("Start-Taster: ");
    // Serial.println(St_Si);
    delay(50);
  }while(St_Si == 0);
}


// Optische Meldungen ein- & ausschalten
void Blinken(){
  for(b = 1; b > -1; b--){ 
    // Serial.print("Blinkzustand: ");
    // Serial.println(B);
    delay(500);
    digitalWrite(O_M1, b);
    digitalWrite(O_M2, b);
  }
}



/* Hauptprogramm ---------------------------------------------------------------- */
void loop() {
  digitalWrite(R_S, HIGH);
  /* AP7. ----------------------------------------------------------------------- */
  /* AP3. --------------------------------------------------------------------- */
  Start_Taster(S_S);
  
  for(a = 0; a < 3; a++){             // Optische Meldung ausgeben
    Blinken(); 
  }
    /* -------------------------------------------------------------------------- */
  do{
    /* AP4. --------------------------------------------------------------------- */
    Zufallszahl = random(100);
 // Serial.print
    if(Zufallszahl % 2 == 0){
      EingangSpieler[0] = Q_S1;
      EingangSpieler[1] = Q_S2;
      Zms[0]            = O_M1;
      Zms[1]            = O_M2;
      Spieler[0]        = 1;
      Spieler[1]        = 2;
    }
    else{
      EingangSpieler[0] = Q_S2;
      EingangSpieler[1] = Q_S1;
      Zms[0]            = O_M2;
      Zms[1]            = O_M1;
      Spieler[0]        = 2;
      Spieler[1]        = 1;
    }
    /* -------------------------------------------------------------------------- */
    /* AP5. --------------------------------------------------------------------- */
    for(x = 0; x < 2; x++){
      Zufallszeit = random(4001);
      Anfangszeit = millis();
      do{
        Spielersignal = digitalRead(EingangSpieler[x]);
        Zeit = millis();
        if(Zeit >= Anfangszeit + Zufallszeit + 1000){
          digitalWrite(Zms[x], HIGH);
        }
      }while(Spielersignal == 0);
      Endzeit = millis();
      if(Endzeit >= Anfangszeit + Zufallszeit + 1000){
        Reaktionszeit = Endzeit - Anfangszeit - Zufallszeit - 1000;
      }
      else{
        Reaktionszeit = 10000;

        for(c = 0; c < 2; c++){
          Blinken();
        } 
      }
      if(Spieler[x] == 1){
        Re_Ze1 = Reaktionszeit;
      }
      else{
        Re_Ze2 = Reaktionszeit;
      }
      digitalWrite(Zms[x], LOW);
    }
    /* -------------------------------------------------------------------------- */
    /* AP6. --------------------------------------------------------------------- */
    if(Re_Ze1 > Re_Ze2){
      digitalWrite(P_S2, HIGH);
      delay(100);
      digitalWrite(P_S2, LOW);
      Pu_Za2++;
    }
    else if(Re_Ze1 < Re_Ze2){
      digitalWrite(P_S1, HIGH);
      delay(100);
      digitalWrite(P_S1, LOW);
      Pu_Za1++;
    }
    /* -------------------------------------------------------------------------- */

  }while(Pu_Za1 < 9 && Pu_Za2 < 9); // führt Reaktionstest aus, bis
                                      // Pu_Za1 oder Pu_Za2 9 enspricht
  if(Pu_Za1 == 9){                    
    digitalWrite(O_M1, HIGH);
  }
  else{
    digitalWrite(O_M2, HIGH);
  }
  /* ---------------------------------------------------------------------------- */
  /* AP8. ----------------------------------------------------------------------- */
  Start_Taster(S_S);
  
  digitalWrite(O_M1, LOW);            // Optische Meldung ausschalten
  digitalWrite(O_M2, LOW);
  Pu_Za1 = 0;                         // Punktzahl1 zurücksetzten
  Pu_Za2 = 0;                         // Punktzahl2 zurücksetzten
  digitalWrite(R_S, LOW);             // Anzeigen zurücksetzten {
  delay(50);
  digitalWrite(P_S1, HIGH);
  digitalWrite(P_S2, HIGH);
  delay(100);
  digitalWrite(P_S1, LOW);
  digitalWrite(P_S2, LOW);
  delay(10);
  digitalWrite(R_S, HIGH);            // }
  }
  /* ---------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------------ */
