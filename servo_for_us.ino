#include <Servo.h>

Servo myServo1;
int angle = 0;

void setup()
{
  Serial.begin(9600); //vel. de comunicación entre pc y ardu
  myServo1.attach(11,800,2200); //800 y 2200 son el mín. y máx. de pulsaciones que corresponden a 0 y 180 grados respectivamente
}

void loop()
{
  for(angle = 0; angle <=180; angle++){ //rango de 0 a 180 grados
    myServo1.write(angle); 
    Serial.println(angle); //para corroborar que recorra los grados correctamente
    delay(20);
  }
  for(angle = 180; angle >= 1; angle--){ //rango de 180 a 0 grados
    myServo1.write(angle); 
    Serial.println(angle); //para corroborar que recorra los grados correctamente
    delay(20);
  }
}