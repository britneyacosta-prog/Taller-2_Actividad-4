// Cambio de Britney En archivo actualizado por Sebastian 
// C++ code
// Código para el receptor RX
void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial
  pinMode(3, INPUT);  // Configura el pin de bits como entrada
  pinMode(2, INPUT); // Pin de bits como entrada 
}

void loop() {
 //Cambio del valor asignado en decimal 204, corresponde a Ì en ASCII
  byte receivedData = 0b11001100;  // Variable para almacenar el byte recibido
  byte bitCount = 0;    // Contador de bits

  while (digitalRead(2) == HIGH); // Espera hasta que el pin sea LOW
  delay(3000);

//Cambio de Sebastian desde rama
  while (bitCount < 8) {
    // Espera a que el bit cambie (transición de LOW a HIGH o HIGH a LOW)
    // Breve espera para estabilización
    int bit = digitalRead(3); // cambie el numero del pin de emtrada
    receivedData = (receivedData << 1) | bit;
    bitCount++;
    delay(10);
  }

//Visualizar los datos 
  Serial.println("======================"); // Agrego para mejor visualización
  Serial.println("PROTOCOLO DE RECEPCIÓN");
  Serial.println("======================");

  Serial.print("Secuencia recibida en binario");
  printBinary(receivedData);
  
  Serial.print(" El ASCII es: ");//cambie el textooooo
  Serial.print((char)receivedData); // Imprime el carácter ASCII
  Serial.println(" Perfect!");
  receivedData = 0;
  
  delay(1000);  // Espera antes de la siguiente lectura
}

// Función para imprimir un byte en formato binario
void printBinary(byte data) {
  Serial.print("[ ");
  for (int i = 7; i >= 0; i--) {
    int bit = (data >> i) & 1;
    Serial.print((data >> i) & 1);  // Imprime cada bit
    Serial.print(bit);
    Serial.print(" ");
  }
    Serial.println("]");
}
