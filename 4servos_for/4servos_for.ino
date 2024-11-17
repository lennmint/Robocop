#include <Servo.h>

#define SERVOS 4 //cantidad de servos
int servoPins[SERVOS] = {3,5,6,11}; //conexion de los servos y ardu
int angle = 0;

Servo myservo[SERVOS];

void setup(){
  Serial.begin(9600);
  for(int i=0; i < SERVOS; i++)
    myservo[i].attach(servoPins[i]);
}

void loop(){

  //bluce for para mover los 4 servos de 0 a 180 grados
  for(angle = 0; angle < 180; angle ++){
    for (int i = 0; i < SERVOS; i++) {
      myservo[i].write(angle);
    }
    delay(20);
  }
  //bucle for para mover los 4 servos de 180 a 0 grados
  for (int angle = 180; angle >= 0; angle--) {
    for (int i = 0; i < SERVOS; i++) {
      myservo[i].write(angle);
    }
    delay(20);
  }
  
  //movimiento individual del servo 3, OJO!!!!! QUE DIGA MYSERVO[3] NO SE REFIERE AL PIN 3 EN FÍSICO, SINO A LA POSICIÓN DEL SERVO EN EL ARRAY
  //EL ARRAY CUENTA DESDE 0 HASTA 3
  for (int angle = 0; angle < 180; angle++){
    myservo[3].write(angle);
    Serial.print("Servo 1: ");
    Serial.println(angle);
    delay(20);
  }

  //movimiento individual del servo 5
  for (int angle = 0; angle < 180; angle++){
    myservo[2].write(angle);
    Serial.print("Servo 2: ");
    Serial.println(angle);
    delay(15);
  }

  //movimiento individual del servo 6
  for (int angle = 0; angle < 180; angle++){
    myservo[1].write(angle);
    Serial.print("Servo 3: ");
    Serial.println(angle);
    delay(15);
  }

  //movimiento individual del servo 11
  for (int angle = 0; angle < 180; angle++){
    myservo[0].write(angle);
    Serial.print("Servo 4: ");
    Serial.println(angle);
    delay(15);
  }

  //movimiento de a dos, de los servos 3 y 5
  for(angle = 0; angle < 180; angle ++){
    for (int i = 0; i < SERVOS; i++) {
      myservo[0].write(angle);
      myservo[1].write(angle);
    }
    delay(20);
  }

  //movimiento de a dos, de los servos 6 y 11
  for(angle = 0; angle < 180; angle ++){
    for (int i = 0; i < SERVOS; i++) {
      myservo[2].write(angle);
      myservo[3].write(angle);
    }
    delay(20);
  }

  //movimiento de a dos, con diferentes ángulos
  for (int angle1 = 0; int angle2 = 180; angle1 < 180 && angle2 >= 0; angle1++; angle2--){
    for (int i = 0; i < SERVOS; i++) {
      myservo[0].write(angle1);
      myservo[1].write(angle2);
      Serial.println(angle1);
      Serial.println(angle2);
    }
    delay(20);
  }
  
}