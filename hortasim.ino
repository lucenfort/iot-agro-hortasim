/*

Projeto de Circuitos Eletrônicos - IoT


(a) Fazer a leitura da temperatura;

(b) Fazer o acionamento de um motor de ventilador caso a temperatura seja igual ou maior a 30 °C;

(c) Caso a temperatura ultrapasse os 50 °C, um LED vermelho e uma buzina devem acionar avisando uma situação de emergência.
*/

// Definindo as constantes para a temperatura de acionamento do motor e para a temperatura de emergência
#define TEMP_LIMITE 30
#define TEMP_EMERGENCIA 50

// Definindo as portas digitais dos componentes utilizados
#define SENSOR_TEMP A0
#define MOTOR 2
#define LED_VERMELHO 3
#define BUZINA 4

void setup() {
  // Inicializando as portas digitais
  pinMode(MOTOR, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZINA, OUTPUT);
  Serial.begin(9600); // Inicializando a comunicação serial
}

void loop() {
  // Lendo a temperatura atual
  float temperatura = (analogRead(SENSOR_TEMP) * 5.0 / 1023.0 - 0.5) * 100.0;

  // Acionando o motor caso a temperatura seja igual ou maior que o limite definido
  if (temperatura >= TEMP_LIMITE) {
    digitalWrite(MOTOR, HIGH);
  } else {
    digitalWrite(MOTOR, LOW);
  }

  // Acionando o LED e a buzina caso a temperatura ultrapasse a temperatura de emergência
  if (temperatura > TEMP_EMERGENCIA) {
    digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZINA, 1000); // Acionando a buzina com um tom de 1000 Hz
  } else {
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZINA); // Desligando a buzina
  }

  // Imprimindo a temperatura atual no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // Aguardando 1 segundo antes de ler a temperatura novamente
  delay(1000);
}
