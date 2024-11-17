#include <Wire.h> //buscar para que es
#include <MechaQMC5883.h> //biblio para gy 
#include <Servo.h> //biblio para servo

//creación de objetos para controlarlos: servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

//creación de objeto: compas gy-273
MechaQMC5883 compas;

void setup() {

  //conexion de servo  
  servo1.attach(3,1000,2000);
  servo2.attach(5,1000,2000); 
  servo3.attach(7,1000,2000);
  servo4.attach(9,1000,2000);

  //gy-273 conexion  
  Wire.begin(); //buscar  
  Serial.begin(9600); 
  compas.init();
}
void loop() {
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

  servo1.write(servox);
  servo2.write(servoy);
  servo3.write(servoz); 
  servo4.write(servoazi);
  Serial.println(x);
  Serial.println(y); 
  Serial.println(z); 
  Serial.println(azimuth);
  
  }