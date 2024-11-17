int botonPin = 8;
int ledPins[] = {2,4,7}; //array para LEDS: azul, roja y amarilla respectivamente
int estadoBoton;
int contadorLed = 0;
int ueBoton = HIGH; // último estado de boton

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP); // pullup: resistencia que está integrada dentro del arduino para asegurar que el estado del pin sea HIGH cuando el botón no está presionado.
}

void loop() {
  
  estadoBoton = digitalRead(botonPin);
  
  if (estadoBoton == LOW && ueBoton == HIGH){

    contadorLed = (contadorLed+1)%3;
    digitalWrite(ledPins[i], LOW);

    switch (contadorLed){

      case 0:
        digitalWrite(ledPins[0], HIGH);
      case 1:
        digitalWrite(ledPins[1], HIGH);
      case 2:
        digitalWrite(ledPins[2], HIGH);


    }

  }

  delay(200);

}