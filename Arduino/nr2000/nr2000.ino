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
int milistaLed[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B1000000, 7 };
long randomNumber;

// libreria para sensor capasitivo
#include <CapacitiveSensor.h>
CapacitiveSensor   sensor1 = CapacitiveSensor(9, 12); //inicio
CapacitiveSensor   sensor2 = CapacitiveSensor(9, 11); //programa0
CapacitiveSensor   sensor3 = CapacitiveSensor(9, 10); //programa1
CapacitiveSensor   sensor4 = CapacitiveSensor(9, A1); //programa2
CapacitiveSensor   sensor5 = CapacitiveSensor(9, A2); //programa3
CapacitiveSensor   sensor6 = CapacitiveSensor(9, A3); //programa4
CapacitiveSensor   sensor7 = CapacitiveSensor(9, A4); //programa5
CapacitiveSensor   sensor8 = CapacitiveSensor(9, A5); //programa6
CapacitiveSensor   sensor9 = CapacitiveSensor(9, A6); //programa7
CapacitiveSensor   sensor10 = CapacitiveSensor(9, A7); //programa8


/*
    --------------------------------------
    prende el Led aleatoreo
   --------------------------------------
*/

void ledWrite(int Led) {
  if (milistaLed[randomNumber] == 8) {
   // digitalWrite(pinLatch, LOW);
   // shiftOut(pinData, pinClock, LSBFIRST, B00000000);
   // digitalWrite(pinLatch, HIGH);
    digitalWrite(7, HIGH);
  }
  else {
    //digitalWrite(12, LOW);
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
  // si el x es menor o igual a 6 el tiempo es de 1000ms
  if (x <= 9) {
    return 1000;
  }
  // si el x es mayor a 9 o menoro igual a 18 el tiempo es de 500ms
  else if (x > 9 or x <= 18) {
    return 500;
  }
  // si el x es mayor a 18 o menor o igual a 27 el tiempo es de 250ms
  else if (x < 18 or x <= 27) {
    return 250;
  }
  // si el x es mayor a 27 o menor o igual a 36 el tiempo es de 100ms
  else if (x < 27 or x <= 36) {
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
  pinMode(pinData, OUTPUT); // 2
  pinMode(pinLatch, OUTPUT);// 3
  pinMode(pinClock, OUTPUT);// 4

  //declara el pin 7 como salida
  pinMode(7, OUTPUT);

  //declara el pin 13 como salida
  pinMode(13, OUTPUT);

  // apaga todos los led
 // shiftOut(pinData, pinClock, LSBFIRST, B00000000);

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
  long programa0 =  sensor2.capacitiveSensor(30);//9,11
  long programa1 =  sensor3.capacitiveSensor(30);//9,10
  long programa2 =  sensor4.capacitiveSensor(30);//9,A1
  long programa3 =  sensor5.capacitiveSensor(30);//9,A2
  long programa4 =  sensor6.capacitiveSensor(30);//9,A3
  long programa5 =  sensor7.capacitiveSensor(30);//9,A4
  long programa6 =  sensor8.capacitiveSensor(30);//9,A5
  long programa7 =  sensor9.capacitiveSensor(30);//9,A6
  long programa8 =  sensor10.capacitiveSensor(30);//9,A7


  if ((programa0 > 50 ) && (randomNumber == 9)) {//7
    digitalWrite(7, LOW);
    aleatorio(espera(contador));
  }
  if ((programa1 > 50 ) && (randomNumber == 8)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B10000000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa2 > 50 ) && (randomNumber == 7)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B010000000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa3 > 50 ) && (randomNumber == 6)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00100000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa4 > 50 ) && (randomNumber == 5)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00010000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa5 > 50 ) && (randomNumber == 4)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00001000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa6 > 50 ) && (randomNumber == 3)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000100
    aleatorio(espera(contador));
  }
  if ((programa7 > 50 ) && (randomNumber == 2)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000010
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa8 > 50 ) && (randomNumber == 1)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000001
    digitalWrite(pinLatch, LOW);
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
      //apaga el LED de inicio
      digitalWrite(7, HIGH);
    }
    delay(1000); //espera 1000ms
    for (int i = 0; i <= 3; i++) {
      // apaga todos los led
      shiftOut(pinData, pinClock, LSBFIRST, B00000000);
      //apaga el LED de inicio
      digitalWrite(7, LOW);
      // imprime fin de ciclo en el puerto de serie
      Serial.println("fin de ciclo");
    }
    //espera 1500ms
    delay(1503);
    // pone el contador en 1
    contador = 1;
    // vuelve a loop()
    loop;
  }
}
void loop() {
  iniciarCiclo();

}
