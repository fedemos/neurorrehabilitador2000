/*
  Autor: fedemos
  licencia: gpl3
  fecha: 7/11/2021
  versión: 0.0.25
*/

int cuenta, estadoTouch, estadoTouchAnterior;
int cuenta0, estadoTouch0, estadoTouchAnterior0;
int cuenta1, estadoTouch1, estadoTouchAnterior1;
int cuenta2, estadoTouch2, estadoTouchAnterior2;
int cuenta3, estadoTouch3, estadoTouchAnterior3;
int cuenta4, estadoTouch4, estadoTouchAnterior4;
int cuenta5, estadoTouch5, estadoTouchAnterior5;
int cuenta6, estadoTouch6, estadoTouchAnterior6;
int cuenta7, estadoTouch7, estadoTouchAnterior7;
int cuenta8, estadoTouch8, estadoTouchAnterior8;


int contador = 0;

//Sensibilidad del touch
const int sensitivity  = 600;

// pines para el 74ch595
int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;

// arrays con los pines en binario del 74ch595
int milistaLed[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000 };

// para cacelar el ciclo
void cancelar();

// ciclo
void ciclo();

// tiempo que dura el ciclo
void tiempo();

bool a = false;
// guarda el random
long randomNumber;

// la primera ves no van a ser iguales
long randomNumberold =  randomNumber + 1;
//
unsigned long tiempos = millis();
unsigned long intervalo = 60000; // un minuto
unsigned long ahora = millis();

/* ------------------------------------------
  agrega CapacitiveSensor y declara los pines
  ------------------------------------------
*/
#include <CapacitiveSensor.h>
CapacitiveSensor   sensor1 = CapacitiveSensor(7, 8); //inicio 12-8
CapacitiveSensor   sensor2 = CapacitiveSensor(7, 9); //programa0 11-9
CapacitiveSensor   sensor3 = CapacitiveSensor(7, 12); //programa1 10-12
CapacitiveSensor   sensor4 = CapacitiveSensor(7, 11); //programa2 A1-11
CapacitiveSensor   sensor5 = CapacitiveSensor(7, 10); //programa3 A2 -10
CapacitiveSensor   sensor6 = CapacitiveSensor(7, A1); //programa4 A3 -A1
CapacitiveSensor   sensor7 = CapacitiveSensor(7, A2); //programa5 A4 -A2
CapacitiveSensor   sensor8 = CapacitiveSensor(7, A3); //programa6 A5 -A3
CapacitiveSensor   sensor9 = CapacitiveSensor(7, A4); //programa7 A6 -A4
CapacitiveSensor   sensor10 = CapacitiveSensor(7, A5); //programa8 A7-A5

// set to 1 if we're debugging
#define DEBUG 1
/*
    --------------------------------------
    prender el Led
   --------------------------------------
*/

void ledWrite(int Led) {
  if (randomNumber == 8) {
    // digitalWrite(pinLatch, LOW);
    // shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    // digitalWrite(pinLatch, HIGH);
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, Led);
    digitalWrite(pinLatch, HIGH);
  }
}
/*
   ------
   setup
   ------
*/

void setup() {

  Serial.begin(9600);
  Serial.println("Autor: fedemos");
  Serial.println("licencia: gpl3 ");
  Serial.println("fecha: 7/11/2021");
  Serial.println("versión: 0.0.25");

  // los pines para como salidas el 74hc595
  pinMode(pinData, OUTPUT); // 2
  pinMode(pinLatch, OUTPUT);// 3
  pinMode(pinClock, OUTPUT);// 4

  //declara el pin 6 como salida
  pinMode(6, OUTPUT);

  //declara el pin 5 como salida
  pinMode(5, OUTPUT);

  //declara el pin 13 como salida
  pinMode(13, OUTPUT);

  // apaga todos los led
  digitalWrite(pinLatch, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(pinLatch, LOW);
  shiftOut(pinData, pinClock, LSBFIRST, B00000000);
  digitalWrite(pinLatch, HIGH);

  //para hacer que el random sea seudo aleatorio
  randomSeed(analogRead(A0));

  //enciende el pin 13
  digitalWrite(13, HIGH);
}

/*
  ---------------------------
  función aleatorio y evita
  que random se repita en
  forma consecutiva
  ---------------------------
*/

int aleatorio() {
  int x;
  // da un número del 0 al 8
  randomNumber = random(0, 9);
#ifdef DEBUG
  #Serial.print(randomNumber);
  #Serial.println(" - randomNumber  ");
#endif

  if (randomNumber == randomNumberold) {

    // vuelve a hacer un random
#ifdef DEBUG
    #Serial.println("- repite - ");
#endif


    randomNumber = random(0, 9);
#ifdef DEBUG
    #Serial.print(randomNumber);
    #Serial.println(" - randomNumber  ");
#endif
  }


  // los iguala
  randomNumberold = randomNumber;

  // prende el led
  x = randomNumber;

  return x;

}
/*
   ------------
   función loop
   ------------
*/

void loop() {
  unsigned long tiempos = millis();
  long inicio =  sensor1.capacitiveSensor(sensitivity);//7,8


  // si se toca el sensor
  estadoTouch = inicio > 180;

  if (estadoTouch != estadoTouchAnterior) {
    estadoTouch = estadoTouchAnterior;

    // prende el LED del pin 6
    digitalWrite(6, HIGH);

    // espera
    delay(1500);

    // imprime inicio en el puerto de serie
#ifdef DEBUG
    #Serial.print(inicio);
    #Serial.println(" - touch inicio - ");
#endif
    contador++;
    //  Serial.print(contador);
    //  Serial.println(" - contador");
    ledWrite(milistaLed[aleatorio()]);
    //  Serial.print(aleatorio());
    //  Serial.println(" - aleatorio ");

  }
  switch (contador) {
    case 1:
      // hace el primer random

      ciclo();
      break;
    case 2:
#ifdef DEBUG
      #Serial.println(" - camcelar ");
#endif
      //do something when var equals 2
      digitalWrite(pinLatch, LOW);
      shiftOut(pinData, pinClock, LSBFIRST, B11111111);//B10000000
      digitalWrite(pinLatch, HIGH);
      digitalWrite(5, HIGH);
      delay(1500);
      digitalWrite(pinLatch, LOW);
      shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B10000000
      digitalWrite(pinLatch, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);

      contador = 0;


      break;
    default:
      // if nothing else matches, do the default
      contador = 0;
      // default is optional
      break;




  }


}


void tiempo() {
  //  unsigned long tiempos = millis();
  unsigned long intervalo = 60000; // un minuto
  unsigned long ahora = millis();

  if (ahora - tiempos >= intervalo) { //si se cumple 1 minuto
    tiempos = ahora;

    cancelar();
#ifdef DEBUG
    // imprime fin de ciclo en el puerto de serie
    #Serial.println("tiempo cumplido ");
#endif

    //espera 150ms
    delay(150);

    contador = 0;
    //loop;
  }
}
void cancelar() {
  digitalWrite(pinLatch, LOW);
  shiftOut(pinData, pinClock, LSBFIRST, B11111111);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(5, HIGH);
  delay(1500);
  digitalWrite(pinLatch, LOW);
  shiftOut(pinData, pinClock, LSBFIRST, B00000000);
  digitalWrite(pinLatch, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

}

void ciclo() {
  int x = 180;
  tiempo();

  //
  long programa0 =  sensor2.capacitiveSensor(sensitivity);//7,9
  long programa1 =  sensor3.capacitiveSensor(sensitivity);//7,12
  long programa2 =  sensor4.capacitiveSensor(sensitivity);//7,11
  long programa3 =  sensor5.capacitiveSensor(sensitivity);//7,10
  long programa4 =  sensor6.capacitiveSensor(sensitivity);//7,A1
  long programa5 =  sensor7.capacitiveSensor(sensitivity);//7,A2
  long programa6 =  sensor8.capacitiveSensor(sensitivity);//7,A3
  long programa7 =  sensor9.capacitiveSensor(sensitivity);//7,A4
  long programa8 =  sensor10.capacitiveSensor(sensitivity);//7,A5

  estadoTouch0 = programa0 > x;
  if ((estadoTouch0 != estadoTouchAnterior0) && (aleatorio() == 8)) { //5-R8-9
    estadoTouch0 = estadoTouchAnterior0;
    cuenta++;
#ifdef DEBUG
    #Serial.println("Touch - programa 0 (5-R8-9)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B10000000
    digitalWrite(pinLatch, HIGH);
    digitalWrite(5, LOW);
    ledWrite(milistaLed[aleatorio()]);

    delay(500);
  }

  estadoTouch1 = programa1 > x;
  if ((estadoTouch1 != estadoTouchAnterior1)  && (aleatorio() == 7)) {// Q0-R7-12{
    estadoTouch1 = estadoTouchAnterior1;
#ifdef DEBUG
    #Serial.println("Touch - programa 1 (Q0-R7-12)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B10000000
    digitalWrite(pinLatch, HIGH);
    ledWrite(milistaLed[aleatorio()]);
    delay(500);

  }

  estadoTouch2 = programa2 > x;
  if ((estadoTouch2 != estadoTouchAnterior2) && (aleatorio() == 6)) {//Q1-R6-11
    estadoTouch2 = estadoTouchAnterior2;
#ifdef DEBUG
    #Serial.println("Touch - programa 2 (Q1-R6-11)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B010000000
    digitalWrite(pinLatch, HIGH);
    ledWrite(milistaLed[aleatorio()]);
    delay(500);

  }
  estadoTouch3 = programa3 > x;
  if ((estadoTouch3 != estadoTouchAnterior3) && (aleatorio() == 5)) {//Q2-R5-10
    estadoTouch3 = estadoTouchAnterior3;
#ifdef DEBUG
    #Serial.println("Touch - programa 3 (Q2-R5-10)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00100000
    digitalWrite(pinLatch, HIGH);
    ledWrite(milistaLed[aleatorio()]);
    delay(500);

  }
  estadoTouch4 = programa4 > x;
  if ((estadoTouch4 != estadoTouchAnterior4) && (aleatorio() == 4)) {//Q3-R4-A1
    estadoTouch4 = estadoTouchAnterior4;
#ifdef DEBUG
    #Serial.println("Touch - programa 4 (Q3-R4-A1)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00010000
    digitalWrite(pinLatch, HIGH);
    ledWrite(milistaLed[aleatorio()]);
    delay(500);

  }
  estadoTouch5 = programa5 > x;
  if ((estadoTouch5 != estadoTouchAnterior5) && (aleatorio() == 3 )) {//Q4-R3-A2
    estadoTouch5 = estadoTouchAnterior5;
#ifdef DEBUG
    #Serial.println("Touch - programa 5 (Q3-R4-A1)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00001000
    digitalWrite(pinLatch, HIGH);
    ledWrite(milistaLed[aleatorio()]);
    delay(500);

  }
  estadoTouch6 = programa6 > x;
  if ((estadoTouch6 != estadoTouchAnterior6) && (aleatorio() == 2)) {//Q5-R2-A3
    estadoTouch6 = estadoTouchAnterior6;
#ifdef DEBUG
    #Serial.println("Touch - programa 6 (Q5-R2-A3)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000100
    digitalWrite(pinLatch, HIGH);
    ledWrite(milistaLed[aleatorio()]);
    delay(500);

  }
  estadoTouch7 = programa7 > x;
  if ((estadoTouch7 != estadoTouchAnterior7) && (aleatorio() == 1)) {//Q6-R1-A4
    estadoTouch7 = estadoTouchAnterior7;
#ifdef DEBUG
    #Serial.println("Touch - programa 7 (Q6-R1-A4)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000010
    digitalWrite(pinLatch, HIGH);
    ledWrite(milistaLed[aleatorio()]);
    delay(500);

  }
  estadoTouch8 = programa8 > x;
  if ((estadoTouch8 != estadoTouchAnterior8) && (aleatorio() == 0)) {//Q7-R0-A5
    estadoTouch8 = estadoTouchAnterior8;
#ifdef DEBUG
    #Serial.println("Touch - programa 8 (Q7-R0-A5)");
#endif
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000001
    digitalWrite(pinLatch, HIGH);
    ledWrite(milistaLed[aleatorio()]);
    delay(500);

  }
}



