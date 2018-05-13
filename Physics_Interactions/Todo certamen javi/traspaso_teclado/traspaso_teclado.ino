#include <Keyboard.h>

const int pulsadorPin = 5;
const int pulsadorPin4 = 4;
const int pulsadorPin3 = 3;
const int pulsadorPin2 = 2;
 
int valorPulsador  = 0;
int valorPulsador2 = 0;
int valorPulsador3 = 0;
int valorPulsador4 = 0;


void setup() {
    // Activamos los pines de entrada y salida
    pinMode(pulsadorPin, INPUT);
    Serial.begin(9600);
    Keyboard.begin();
}
 
void loop() {
    // Leemos el valor del pin
    valorPulsador = digitalRead(pulsadorPin);
    valorPulsador2 = digitalRead(pulsadorPin2);
    valorPulsador3 = digitalRead(pulsadorPin3);
    valorPulsador4 = digitalRead(pulsadorPin4);
    
    Serial.print("b1: ");
    Serial.print(valorPulsador2);
    Serial.print("\t");
    Serial.print("b2: ");
    Serial.print(valorPulsador3);
    Serial.print("\t");
    Serial.print("b3: ");
    Serial.print(valorPulsador4);
    Serial.print("\t");
    Serial.print("b4: ");
    Serial.println(valorPulsador);
  

  
  ///////////// BOTONES TECLADO /////////////////
    
  if (valorPulsador2 == HIGH) {
      delay(150);
      Keyboard.press('a');    
  } else {
      Keyboard.releaseAll();    
  }

 
  if (valorPulsador3 == HIGH) {
      delay(150);
      Keyboard.press('s');
  } else {
      Keyboard.releaseAll();
  }

  
  if (valorPulsador4 == HIGH) {
      delay(150);
      Keyboard.press('j');
  } else {
      Keyboard.releaseAll();     
  }


    if (valorPulsador == HIGH) {
     delay(150);
     Keyboard.press('k');     
  } else {
     Keyboard.releaseAll();
  }

}
