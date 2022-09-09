
#define pin_lm35 A0 //Pino o qual o sensor está conectado

void setup() {
Serial.begin(9600); // Inicia a comunicação com
pinMode(pin_lm35, INPUT); // Define o sensor como uma entrada de sinal
pinMode(12, OUTPUT); //buzzer
}

void loop() {
float valor_analog_lm35 = float(analogRead(pin_lm35)); // Obtém o valor analógico que varia de 0 a 1023
float tensao = (valor_analog_lm35 * 5) / 1023; // Vamos converter esse valor para tensão elétrica
float temperatura = tensao / 0.010; // dividimos a tensão por 0.010 que representa os 10 mV

Serial.println(temperatura); // Mostra na serial a temperatura do sensor
if(temperatura > 28) // se a temperatura for maior que 25
{
  delayMicroseconds(150);
  digitalWrite(12, HIGH); // buzer faz barulho
}
else // se não 
{
  digitalWrite(12,LOW); // buzer desliga 
}
delay(1000); // aguarda 1 segundo
}
