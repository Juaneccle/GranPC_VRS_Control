 #include <Keyboard.h>
 long valor;         // Valor potenciometro
 
 const int pulsadorPin = 2;
 const int pulsadorPin2 = 3;
 const int Trigger = 6;          //Pin digital 2 para el Trigger del sensor
 const int Echo = 4;             //Pin digital 3 para el echo del sensor
 const int inX = A0;             // analog input for x-axis
 const int inY = A1;             // analog input for y-axis
 const int presionJ = 8;
 
 int volumen;               // volumen de audio
 int intensidad;            // intensidad luminica
 int distancia;             // Valor distancia 
 int potencia;              // Valor potencia
 int valorTacto;            // Valor de tacto
 int valorPulsador  = 0;    // Estado del Boton
 int valorPulsador2 = 0;    // Estado del Boton 2
 int xValue = 0;            // Valor X
 int yValue = 0;            // Valor Y
 int Presion = 0;           // Precion Joystic
 
 // SALIDA DE PINES
 int LED_A = 2;      
 int LED_B = 3;
 int LED_C = 4;
 int LED_D = 5;
 int LED_E = 6; 
 int tacto = 8;        // Pin sensor Tacto

void setup() {
  
  pinMode(pulsadorPin,  INPUT);
  pinMode(pulsadorPin2, INPUT);
  pinMode(Trigger, OUTPUT);        //pin como salida
  pinMode(Echo, INPUT);            //pin como entrada
  pinMode(tacto, INPUT);
  pinMode(inX, INPUT); 
  pinMode(inY, INPUT); 
  pinMode(presionJ, INPUT_PULLUP);
  
  Serial.begin(9600);
  Keyboard.begin();

  digitalWrite(Trigger, LOW);      //Inicializamos el pin con 0
}

void loop() {
  
//// DECLARACIONES //// 
volumen       = analogRead(A0); 
intensidad    = analogRead(A1);
potencia      = analogRead(A2);
valorPulsador = digitalRead(pulsadorPin);
valorTacto    = digitalRead(tacto);
xValue        = analogRead(inX); 
yValue        = analogRead(inY); 
Presion       = digitalRead(presionJ);

long t;      //timepo que demora en llegar el eco
long d;      //distancia en centimetros

delay(30);   // Delay Global

////////////////////// SONIDO ////////////////////////////
/////////////////////////////////////////////////////////// 

//Serial.println(volumen); 
if (volumen > 50){
digitalWrite(LED_A, HIGH);
//Serial.println("Sonido prendido");  
}else if(volumen < 50) {
digitalWrite(LED_A, LOW);
  
}
///////////////////////////////////////////////////////////
/////////////////////// FOTORESISTENCIA /////////////////

//Serial.println(intensidad);
if(intensidad > 1010){
digitalWrite(LED_B, HIGH);
  
}else {
  digitalWrite(LED_B,LOW);
}

//////////////////////////////////////////////////////////
///////////////////////// DISTANCIA //////////////////////

  
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH);      //obtenemos el ancho del pulso
  d = t/59;                     //escalamos el tiempo a una distancia en cm

// COMPROBACION //

  //Todo esto es para la impresion serial
  //Serial.print("Distancia: ");
  //Serial.print(d);               
  //Serial.print("cm");
  //Serial.println();

  if(d < 12){
     
   //delay(150);
     Serial.println("tecla azul");
     Keyboard.press('a');  
  } else {
     Keyboard.releaseAll(); 
  }

//////////////////////////////////////////////////////////
/////////////////////// POTENCIOMETRO ////////////////////

// COMBROBACION // 

  //Serial.print("El valor es = ");
  //Serial.println(potencia);

 if(potencia < 100){
    //delay(150);
      Serial.println("tecla roja");
      Keyboard.press('s');
  } else {
      Keyboard.releaseAll();
 }

/////////////////////////////////////////////////////////
/////////////////////////// BOTON 1 ///////////////////////

// COMPROBACION //

  //Serial.println("Hola ql");

 if (valorPulsador == HIGH) {
   //delay(150);
     Serial.println("tecla verde");
     Keyboard.press('k');     
  } else {
     Keyboard.releaseAll();
  }


/////////////////////////////////////////////////////////
/////////////////////////// BOTON 2 ///////////////////////
/*
 if (valorPulsador2 == HIGH) {
     delay(150);
     Serial.println("tecla amarilla");
     Keyboard.press('k');     
  } else {
     Keyboard.releaseAll();
  }
*/

/////////////////////////////////////////////////////////
/////////////////////////// TACTO ///////////////////////

if (valorTacto == HIGH){      
    //delay(150);
    Keyboard.press('j');
    Serial.println("tecla azul");
    //Serial.println("ACTIVADO");
  } else {                      
    Serial.println("NO ACTIVADO");
    Keyboard.releaseAll();
  }

/////////////////////////////////////////////////////////
///////////////////////// JOYSTICK ///////////////////////

  Serial.print("X: ");
  Serial.println(xValue);
  Serial.print("Y: ");
  Serial.println(yValue);
  Serial.print("Not pressed: ");
  Serial.println(Presion);

}
