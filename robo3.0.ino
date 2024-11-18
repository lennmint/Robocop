#include <Servo.h>

#define botonPin 8
//Cantidad de servos a usar
#define SERVOS 4
//Arrays para servos y leds
int servoPins[SERVOS] = {3,5,6,11};
int ledPins[] = {7,2,4};
//Con esto controlo los servos
Servo myservo[SERVOS];

//flancos
int botonEstado = HIGH;
int botonEstadoAnt = HIGH;

//Contador de presiones
int botonContador = 0;

void setup() {
  Serial.begin(9600);
  
  //for para conf. los leds como salidas
  for (int i=0; i < 3 ; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  //for para conectar los servos a los pines.
  for(int i=0; i < SERVOS; i++){
    myservo[i].attach(servoPins[i]);
  }
  
  //PULLUP para que el boton se mantenga en HIGH cuando no lo presionen
  pinMode(botonPin, INPUT_PULLUP);
}

void loop() {

  //bucle for para apagar todas las luces
  for(int i=0; i < 3 ; i++){
    digitalWrite(ledPins[i], LOW);
  }
  //uso de static int en vez de int para que "modo" no se reinicie a 0 cada vez que la llamen
  //así se manejará entre los valores 0, 1 y 2, y que el switch funcione como corresponde
  static int modo = 0;
  botonEstado = digitalRead(botonPin);

  //inicio de flanco de bajada
  if (botonEstado == LOW && botonEstadoAnt == HIGH) {
    botonContador++;
    //esto de acá es para que después de haber apretado 3 veces el botón, se repita el ciclo
    modo = botonContador % 3;
    delay(50);
  }
  //esto es para el if del flanco
  botonEstadoAnt = botonEstado;
  
  switch(modo){
    case 0:
      Serial.println("Modo: Preset 1");
      digitalWrite(ledPins[0], HIGH);
      Serial.println(modo);
      digitalWrite(ledPins[0],HIGH);

     //3(0) = base, 5(1) = codo1, 6(2)= codo2, 11(3)= pinza
     //movimiento de servo base
      for (int angle = 45; angle < 180; angle++){
        myservo[0].write(angle);
        delay(1000);
      }

      //movimiento servo codo 1
      for (int angle = 180; angle < 45; angle--){
        myservo[1].write(angle);
        delay(1000);
      }

      //mov. de servo codo2
      for (int angle = 85; angle < 45; angle--){
        myservo[2].write(angle);
        delay(1000);
      }
      //mov. servo pinza
      for (int angle = 45; angle < -50; angle--){ 
        myservo[3].write(map(angle, -50, 45, 0, 180));
        delay(1000);
      }
      break;
    case 1:
      Serial.println("Modo: Preset 2");
      digitalWrite(ledPins[0], LOW);
      digitalWrite(ledPins[1],HIGH);
      Serial.println(modo);

      //3(0) = base, 5(1) = codo1, 6(2)= codo2, 11(3)= pinza
      //mov. servo base
      for (int angle = 45; angle < 180; angle++){
        myservo[0].write(angle);
        Serial.print("Servo 1: ");
        Serial.println(angle);
        delay(3000);
      }

      //mov. servo codo1
      for (int angle = 20; angle < 100; angle++){
        myservo[1].write(angle);
        Serial.print("Servo 2: ");
        Serial.println(angle);
        delay(3000);
      }

      //mov. servo codo2
      for (int angle = 180; angle < 90; angle--){
        myservo[2].write(angle);
        Serial.print("Servo 1: ");
        Serial.println(angle);
        delay(1000);
      }

      //mov. servo pinza
      for (int angle = 90; angle < 180; angle++){
        myservo[3].write(angle);
        Serial.print("Servo 1: ");
        Serial.println(angle);
        delay(1000);
      }
      break;
    case 2:
      Serial.println("Modo: Manmode activo");
      digitalWrite(ledPins[1], LOW);
      digitalWrite(ledPins[2],HIGH);
      Serial.println(modo);

      //3(0) = base, 5(1) = codo1, 6(2)= codo2, 11(3)= pinza
      digitalWrite(ledPins[1],LOW);
      digitalWrite(ledPins[2],HIGH);
      
      int x, y, z;
      int azimuth;
      int servox;
      int servoy;
      int servoz; 
      int servoazi;
      compas.read(&x, &y, &z,&azimuth);
      servox = map(x, 0, 1023, 0, 180);
      servoy = map(y, 0, 1023, 0, 180);
      servoz = map(z, 0, 1023, 0, 180);
      servoazi = map(azimuth, 0, 1023, 0, 180);

      myservo[0].write(servox);
      myservo[1].write(servoy);
      myservo[2].write(servoz;
      myservo[3].write(servoazi);

      Serial.print("Grados X: ");
      Serial.println(x);
      Serial.print("Grados Y: ");
      Serial.println(y); 
      Serial.print("Grados Z: ");
      Serial.println(z);
      Serial.print("Grados Azimuth: "); 
      Serial.println(azimuth);

     break;
  
  }
}