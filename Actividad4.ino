// Código para el transmisor TX
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); // Configura el pin de transmisión como salida
  digitalWrite(13,HIGH);
  delay(4000);
}

void loop() {
  
  byte data = 0b00100011; // Datos a enviar (ejemplo: 'H')

  digitalWrite(13, LOW);
  delay(51);	// 50 originalmente

  for(int i=7; i>=0; i--) {
    digitalWrite(13,(data>>i)&1);
    Serial.println((data>>i)&1);
    delay(10);
  }

  digitalWrite(13, HIGH);
  delay(1000);
}