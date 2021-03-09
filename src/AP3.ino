/* Ioannis Christodoulakis, Thomas Ammann, 16.05.2017, 6301 Zug CH 
   Reakionsspiel AP3. Start */

// Variablen
bool St_Si=0;
char A;
char B;
     

// Konstanten
const char  S_S  = 3,
           O_M1 = 8,
           O_M2 = 9;

// I/O
void setup() {
  // Eingaenge
  pinMode(S_S,  INPUT);

  // Ausgaenge
  pinMode(O_M1, OUTPUT);
  pinMode(O_M2, OUTPUT);

Serial.begin(9600);
}

char Start_Taster(char Start_Pin){
  do{
    St_Si = digitalRead(Start_Pin);
    Serial.print(St_Si);
    delay(50);
  }while(St_Si == 0);
}

// Hauptprogramm
void loop() {
  
  // Start-Signal einlesen
  Start_Taster(S_S);

  // Optische Meldung
  for(A = 0; A < 3; A++){
    for(B = 1; B > -1; B--){ 
      delay(500);
      digitalWrite(O_M1, B);
      digitalWrite(O_M2, B);
    }  
  }  
  St_Si = 0;

}
