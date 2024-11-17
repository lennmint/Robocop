#include <Wire.h> 
#include <MechaQMC5883.h>
#include <Servo.h>

int estadoLed = 0;
int botonPin = 2;
//array de LEDs, amarillo, rojo y azul, respectivamente}
int ledPins[] = {12, 13, 11} 
//cantidad de servos
#define SERVOS 4 
//conexion entre servos y ardu
int servoPins[SERVOS] = {3,5,6,11}; //3(0) = base, 5(1) = codo1, 6(2)= codo2, 11(3)= pinza
Servo myservo[SERVOS];

MechaQMC5883 compas;


void setup(){
  Serial.begin(9600);

  Wire.begin();
  compas.init();

  //bucle for para leds
  for(int i = 0; i < 3; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  //bucle for para servos
  for(int = 0; i < SERVOS; i++){
    myservo[i].attach(servoPins[i]);
  }
  pinMode(botonPin,INPUT);
 
}


void loop(){

  //bucle for para apagar todas las luces
  for(int i=0;i<3;i++){
    digitalWrite(ledPins[i], LOW);
  }

  if (digitalRead(botonPin) == 1){
    estadoLed ++;
    if (estadoLed == 4){
      estadoLed = 1;
    }
    switch (estadoLed){
      case 1:
        digitalWrite(ledPins[0],HIGH);

        //3(0) = base, 5(1) = codo1, 6(2)= codo2, 11(3)= pinza
        //movimiento de servo base
        for (int angle = 45; angle < 180; angle++){
          myservo[0].write(angle);
          Serial.print("Servo 1: ");
          Serial.println(angle);
          delay(1000);
        }

        //movimiento servo codo 1
        for (int angle = 180; angle < 45; angle--){
          myservo[1].write(angle);
          Serial.print("Servo 2: ");
          Serial.println(angle);
          delay(1000);
        }

        //mov. de servo codo2
        for (int angle = 85; angle < 45; angle--){
          myservo[2].write(angle);
          Serial.print("Servo 3: ");
          Serial.println(angle);
          delay(1000);
        }

        //mov. de servo pinza, revisar que no haya error al utilizar angle-- siendo que hay un ángulo en negativo
        for (int angle = 45; angle < -50; angle--){ 
          myservo[3].write(angle);
          Serial.print("Servo 2: ");
          Serial.println(angle);
          delay(1000);
        }
      
      
       break;
      
      case 2:
        //apago amarillo, prendo rojo
        digitalWrite(ledPins[0],LOW);
        digitalWrite(ledPins[1],HIGH);

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
      
      case 3:
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
    while (digitalRead(botonPin) == 1){
    }
  }