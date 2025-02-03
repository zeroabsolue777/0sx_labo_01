int led = LED_BUILTIN; // LED connectée à la broche 13

void setup() {
  pinMode(led, OUTPUT); // Définit la broche 13 en mode sortie
  Serial.begin(9600); // Initialise la communication série
}

void allume() {
  Serial.println("Allume - 2411160"); 
  digitalWrite(led, HIGH); 
  delay(2000);
  
}

void clignotement() {
  int nombreClignotements = (6 / 2) +1;
Serial.println("Clignotement - 2411160"); 
  for (int i = 0; i < nombreClignotements; i++) {
    digitalWrite(led, LOW); 
    delay(250); 
    digitalWrite(led, HIGH); 
    delay(250); 
  }
    
}

void variationIntensite() {
  int dernierChiffre = 0;
  Serial.println("Variation - 2411160");  
  if (dernierChiffre % 2 == 0) { 
    for (int i = 0; i <= 256; i++) {
      analogWrite(led, i); 
      delay(8);
    }
  } else { 
    for (int i = 256; i >= 0; i--) {
      analogWrite(led, i);
      delay(8); 
    }
  }
  
}

void eteint() {
  Serial.println("Éteint - 2411160"); 
  digitalWrite(led, LOW); 
  delay(2000); 
}

void loop() {
  allume();
  clignotement();
  variationIntensite();
  eteint();
}

