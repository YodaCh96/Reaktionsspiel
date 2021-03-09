/* Projektnamen:            Reaktionsspiel
 * Dateinamen:              Reaktionsspiel.io
 * Entwickler:              Thomas Ammann, Ioannis Christodulakis
 * Datum:                   29.05.2017
 * Ort:                     6301 Zug, CH
 * Entwicklungsschritt:     Zusammenführung, 29.05.2017
 *                          Formatierung, 29.05.2017
 * Letzes Aenderungsdatum:  29.05.2017
*/

/* Variablen --------------------------------------------------------- */
char St_Si,                 // Start-Signal
     EingangSpieler[2],
     Spieler[2],
     Zms[2],
     Spielersignal,
     Pu_Za1 = 0,            // Punktzahl1
     Pu_Za2 = 0;            // Punktzahl2
     
     
char A,                     // für for-Schleife
     B,                     // für for-Schleife
     X;                     // für for-Schleife

  

unsigned long Anfangszeit,  // Anfangszeit der Zeitmessung
              Endzeit,      // Endzeit der Zeitmessung
              Zeit,
              Zufallszahl,  // zufaellig generierte Zahl
              Re_Ze1,       // Reaktionszeit1
              Re_Ze2,       // Reaktionszeit2
              Reaktionszeit,
              Zufallszeit;


     

/* Konstanten --------------------------------------------------------- */
const char    S_S  = 3,     // Eingeange {
              Q_S1 = 4,
              Q_S2 = 5,     // }
              
              P_S1 = 6,     // Ausgaenge {
              P_S2 = 7,
              O_M1 = 8,
              O_M2 = 9,
              R_S = 10;     // }
    
     


/* Setup -------------------------------------------------------------- */
void setup() {
  
  /* Eingaenge -------------------------------------------------------- */
  pinMode(S_S,  INPUT);
  pinMode(Q_S1, INPUT);
  pinMode(Q_S2, INPUT);

  /* Ausgaenge -------------------------------------------------------- */
  pinMode(P_S1, OUTPUT);
  pinMode(P_S2, OUTPUT);
  pinMode(O_M1, OUTPUT);
  pinMode(O_M2, OUTPUT);
  pinMode(R_S, OUTPUT);

  /* Pin für Zufallszahl ---------------------------------------------- */
  randomSeed(analogRead(0)); // analogPin0 darf nicht angeschlossen sein!

}




/* Hauptprogramm ------------------------------------------------------ */
void loop() {
  /* AP7. ------------------------------------------------------------- */
  do{
    /* AP3. ----------------------------------------------------------- */
    do{                           // Start-Signal einlesen
      St_Si = digitalRead(S_S);
      delay(50);
    }while(St_Si == 0);
  
    for(A = 0; A < 3; A++){       // Optische Meldung ausgeben
      for(B = 1; B > -1; B--){ 
        delay(500);
        digitalWrite(O_M1, B);
        digitalWrite(O_M2, B);
      }  
    }
    /* ---------------------------------------------------------------- */
    /* AP4. ----------------------------------------------------------- */
    Zufallszahl = random(100);
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
    /* ---------------------------------------------------------------- */
    /* AP5. ----------------------------------------------------------- */
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
    /* ---------------------------------------------------------------- */
    /* AP6. ----------------------------------------------------------- */
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
    /* ---------------------------------------------------------------- */

  }while(Pu_Za1 == 9 || Pu_Za2 == 9); // führt Reaktionstest aus, bis
  if(Pu_Za1 == 9){                    // Pu_Za1 oder Pu_Za2 9 enspricht
    digitalWrite(O_M1, HIGH);
  }
  else{
    digitalWrite(O_M2, HIGH);
  }
  /* ------------------------------------------------------------------ */
  /* AP8. ------------------------------------------------------------- */
  do{
    St_Si = digitalRead(S_S);
  }while(St_Si == 0);
  digitalWrite(O_M1, LOW);    // Optische Meldung ausschalten
  digitalWrite(O_M2, LOW);
  Pu_Za1 = 0;                 // Punktzahl1 zurücksetzten
  Pu_Za2 = 0;                 // Punktzahl2 zurücksetzten
  digitalWrite(R_S, LOW);     // Anzeigen zurücksetzten {
  delay(5);
  digitalWrite(P_S1, HIGH);
  digitalWrite(P_S2, HIGH);
  delay(50);
  digitalWrite(P_S1, LOW);
  digitalWrite(P_S2, LOW);
  digitalWrite(R_S, HIGH);    // }
  }
  /* ------------------------------------------------------------------ */
