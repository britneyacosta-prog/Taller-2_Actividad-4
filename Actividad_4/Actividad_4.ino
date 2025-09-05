// C++ code
// Código para el receptor RX
void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial
  pinMode(2, INPUT);  // Configura el pin de bits como entrada
}

void loop() {
  byte receivedData = 0;  // Variable para almacenar el byte recibido
  byte bitCount = 0;    // Contador de bits
  while (digitalRead(2) == HIGH); // Espera hasta que el pin sea LOW
  delay(5000);
//Cambio de Sebastian
  while (bitCount < 8) {
    // Espera a que el bit cambie (transición de LOW a HIGH o HIGH a LOW)
    // Breve espera para estabilización
    int bit = digitalRead(2); // Lee el bit
    receivedData = (receivedData << 1) | bit;
    bitCount++;
    delay(10);
  }

  // Imprime la secuencia de bits
  Serial.print("Datos recibidos en binario: ");
  
  // "Solución"
  //receivedData = receivedData << 1;

  
  printBinary(receivedData);    // Imprime el byte en formato binario
  Serial.print(" (ASCII: ");
  Serial.print((char)receivedData); // Imprime el carácter ASCII
  Serial.println(")");
  receivedData = 0;
  
  delay(1000);  // Espera antes de la siguiente lectura
}

// Función para imprimir un byte en formato binario
void printBinary(byte data) {
  for (int i = 7; i >= 0; i--) {
    Serial.print((data >> i) & 1);  // Imprime cada bit
  }
}
