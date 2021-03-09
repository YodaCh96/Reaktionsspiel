/* Thomas Ammann, 16.05.2017, 6301 Zug CH 
   Reakionsspiel AP3. Start */

// Variablen
char St_Si,
     A,
     B;
     

// Konstanten
const char S_S  = 3,
           O_M1 = 8,
           O_M2 = 9;

// I/O
void setup() {
  // Eingaenge
  pinMode(S_S,  INPUT);

  // Ausgaenge
  pinMode(O_M1, OUTPUT);
  pinMode(O_M2, OUTPUT);

}

// Hauptprogramm
void loop() {
  // Start-Signal einlesen
  do{
    St_Si = digitalRead(S_S);
    delay(50);
  }while(St_Si == 0);

  // Optische Meldung
  for(A = 0; A < 3; A++){
    for(B = 1; B > -1; B--){ 
      delay(500);
      digitalWrite(O_M1, B);
      digitalWrite(O_M2, B);
    }  
  }  

}
