/*
  Autor: fedemos
  licencia: gpl3
  fecha: 7/11/2021
  versión: 0.0.2
*/

int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
int contador = 1;
int milistaLed[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B1000000, 12 };
long randomNumber;

// libreria para sensor capasitivo
#include <CapacitiveSensor.h>
CapacitiveSensor   sensor1 = CapacitiveSensor(5, 6);
CapacitiveSensor   sensor2 = CapacitiveSensor(5, 7);
CapacitiveSensor   sensor3 = CapacitiveSensor(5, A1);
CapacitiveSensor   sensor4 = CapacitiveSensor(5, A2);
CapacitiveSensor   sensor5 = CapacitiveSensor(5, A3);
CapacitiveSensor   sensor6 = CapacitiveSensor(5, A4);
CapacitiveSensor   sensor7 = CapacitiveSensor(5, A5);
CapacitiveSensor   sensor8 = CapacitiveSensor(5, A6);
CapacitiveSensor   sensor9 = CapacitiveSensor(5, A7);
CapacitiveSensor   sensor10 = CapacitiveSensor(5, 8);

/*
    --------------------------------------
    prende el Led aleatoreo
   --------------------------------------
*/

void ledWrite(int Led) {
  if (milistaLed[randomNumber] == 8) {
    digitalWrite(12, HIGH);
  }
  else {
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, Led);
    digitalWrite(pinLatch, HIGH);
  }

}

/*
    -----------------------------------------
    tiempo de tiempo entre que se presiona el
    sensor capasitivo y se prende el póxmo LED
    ------------------------------------------
*/

int espera(int x) {
  // si el x es menor a 8 el tiempo es de 1000ms
  if (x < 8) {
    return 1000;
  }
  // si el x es igual a 8 o menor a 16 el tiempo es de 500ms
  else if (x = 8 or x < 16) {
    return 500;
  }
  // si el x es igual a 16 o menor a 24 el tiempo es de 250ms
  else if (x = 16 or x < 24) {
    return 250;
  }
  // si el x es igual a 24 o menor a 32 el tiempo es de 100ms
  else if (x = 24 or x < 32) {
    return 100;
  }
  // si no se dan las otras hipótesis el tiempo es de 50ms
  else  {
    return 50;
  }
}

// ----------------------------------

void setup() {
  Serial.begin(9600);
  Serial.println("Autor: fedemos");
  Serial.println("licencia: gpl3 ");
  Serial.println("fecha: 7/11/2021");
  Serial.println("versión: 0.0.2");

  // los pines para controlar el 74hc595
  pinMode(pinData, OUTPUT);
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);

  //declara el pin 12 como salida
  pinMode(12, OUTPUT);

  //declara el pin 13 como salida
  pinMode(13, OUTPUT);

  // apaga todos los led
  shiftOut(pinData, pinClock, LSBFIRST, B00000000);

  //para hacer que el random sea seudo aleatorio
  randomSeed(analogRead(A0));

  //enciende el pin 13
  digitalWrite(13, HIGH);

}

/*
  ---------------------------
  función random
  ---------------------------
*/

void aleatorio(int x) {

  // da un número del 0 al 8
  randomNumber = random(0, 8);

  //tiempo de espera antes de hacer el random
  delay(x);

  // prende el led
  ledWrite(milistaLed[randomNumber]);

  //luego de hacer el random le suma 1 al contador
  contador++;
}

/*
   ---------------
   inicio del cilo
   ---------------
*/

void ciclo() {
  // cuando se cumple el tiempo termina el ciclo
  tiempo();
  long programa1 =  sensor2.capacitiveSensor(30);//5,7
  long programa2 =  sensor3.capacitiveSensor(30);//5,A1
  long programa3 =  sensor4.capacitiveSensor(30);//5,A2
  long programa4 =  sensor5.capacitiveSensor(30);//5,A3
  long programa5 =  sensor6.capacitiveSensor(30);//5,A4
  long programa6 =  sensor7.capacitiveSensor(30);//5,A5
  long programa7 =  sensor8.capacitiveSensor(30);//5,A6
  long programa8 =  sensor9.capacitiveSensor(30);//5,A7
  long programa9 =  sensor10.capacitiveSensor(30);//5,8


  if ((programa1 > 50 ) && (randomNumber == 0)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    aleatorio(espera(contador));
  }
  if ((programa2 > 50 ) && (randomNumber == 1)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    aleatorio(espera(contador));
  }
  if ((programa3 > 50 ) && (randomNumber == 2)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    aleatorio(espera(contador));
  }
  if ((programa4 > 50 ) && (randomNumber == 3)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    aleatorio(espera(contador));
  }
  if ((programa5 > 50 ) && (randomNumber == 4)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    aleatorio(espera(contador));
  }
  if ((programa6 > 50 ) && (randomNumber == 5)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    aleatorio(espera(contador));
  }
  if ((programa7 > 50 ) && (randomNumber == 6)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    aleatorio(espera(contador));
  }
  if ((programa8 > 50 ) && (randomNumber == 7)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    aleatorio(espera(contador));
  }
  if ((programa9 > 50 ) && (randomNumber == 8)) {
    digitalWrite(12, LOW);
    aleatorio(espera(contador));
  }


}

/*
   -----------------
   inicio de ciclo
   -----------------
*/

void iniciarCiclo() {
  long inicio =  sensor1.capacitiveSensor(30);
  //si se toca el sensor
  if (inicio > 50) {
    //prende el LED del pin 12
    //digitalWrite(12, HIGH);
    // imprime inicio en el puerto de serie
    Serial.println("inicio ");
    //espera 1000ms
    delay(1000);
    // hace el primer random
    ledWrite(milistaLed[randomNumber]);
    //inicia la fuciión ciclo
    ciclo;
  }
}

/*
   ---------------------------------
   tiempo en que se ejecuta el ciclo
   ---------------------------------
*/

void tiempo() {
  unsigned long tiempos = millis();
  unsigned long intervalo = 60000; // 1 minuto
  unsigned long ahora = millis();
  if (ahora - tiempos >= intervalo) { //si se cumple 1 minuto
    tiempos = ahora;
    for (int i = 0; i <= 3; i++) {
      // prende todos los led
      shiftOut(pinData, pinClock, LSBFIRST, B11111111);
    }
    delay(1000); //espera 1000ms
    for (int i = 0; i <= 3; i++) {
      // apaga todos los led
      shiftOut(pinData, pinClock, LSBFIRST, B00000000);
      //apaga el LED de inicio
      digitalWrite(12, LOW);
      // imprime fin de ciclo en el puerto de serie
      Serial.println("fin de ciclo");
    }
    //espera 1500ms
    delay(1500);
    // pone el contador en 1
    contador = 1;
    // vuelve a loop()
    loop;
  }
}
void loop() {
  iniciarCiclo();

}