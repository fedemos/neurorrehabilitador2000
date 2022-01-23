/*
  Autor: fedemos
  licencia: gpl3
  fecha: 7/11/2021
  versión: 0.0.3
*/

//Parameters
bool autocal, autocal1, autocal2, autocal3, autocal4, autocal5, autocal6, autocal7, autocal8, autocal9  = 0;
const int numReadings  = 10;
long readings [numReadings], readings1 [numReadings], readings2 [numReadings], readings3 [numReadings], readings4 [numReadings], readings5 [numReadings], readings6 [numReadings], readings7 [numReadings], readings8 [numReadings], readings9 [numReadings];
int readIndex, readIndex1, readIndex2, readIndex3, readIndex4, readIndex5, readIndex6, readIndex7, readIndex8, readIndex9  = 0;
long total, total1, total2, total3, total4, total5, total6, total7, total8, total9  = 0;
const int sensitivity  = 1000;
//const int thresh  = 200;
//const int csStep  = 10000;
//
int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
int contador = 1;
int milistaLed[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B1000000, 7 };
long randomNumber;
long randomNumberold = randomNumber + 1;

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
  Serial.println("versión: 0.0.3");

  // los pines para controlar el 74hc595
  pinMode(pinData, OUTPUT); // 2
  pinMode(pinLatch, OUTPUT);// 3
  pinMode(pinClock, OUTPUT);// 4

  //declara el pin 6 como salida
  pinMode(6, OUTPUT);

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
  //
  if (randomNumber = randomNumberold) {

    // da un número del 0 al 8
    randomNumber = random(0, 8);
  }
  //tiempo de espera antes de hacer el random
  delay(x);

  // prende el led
  ledWrite(milistaLed[randomNumber]);

  //luego de hacer el random le suma 1 al contador
  contador++;
  //
  randomNumberold = randomNumber;
}

/*
   ---------
   programas
   ---------
*/

long inicio() { //pines 9,12
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total = total - readings[readIndex];
  // read the sensor:
  readings[readIndex] = sensor1.capacitiveSensor(sensitivity);
  // add value to total:
  total = total + readings[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total / numReadings;

  return average;
}

long programa0() { //pines 9,11
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total1 = total1 - readings1[readIndex];
  // read the sensor:
  readings1[readIndex] = sensor2.capacitiveSensor(sensitivity);
  // add value to total:
  total1 = total1 + readings1[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total1 / numReadings;

  return average;
}
long programa1() { //pines 9,10
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total2 = total2 - readings2[readIndex];
  // read the sensor:
  readings2[readIndex] = sensor3.capacitiveSensor(sensitivity);
  // add value to total:
  total2 = total2 + readings2[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total2 / numReadings;

  return average;
}

long programa2() { //pines 9,A1
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total3 = total3 - readings3[readIndex];
  // read the sensor:
  readings3[readIndex] = sensor4.capacitiveSensor(sensitivity);
  // add value to total:
  total3 = total3 + readings3[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total3 / numReadings;

  return average;
}
long programa3() { //pines 9,A2
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total4 = total4 - readings4[readIndex];
  // read the sensor:
  readings4[readIndex] = sensor5.capacitiveSensor(sensitivity);
  // add value to total:
  total4 = total4 + readings4[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total4 / numReadings;

  return average;
}
long programa4() { //pines 9,A3
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total5 = total5 - readings5[readIndex];
  // read the sensor:
  readings5[readIndex] = sensor6.capacitiveSensor(sensitivity);
  // add value to total:
  total5 = total5 + readings5[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total5 / numReadings;

  return average;
}
long programa5() { //pines 9,A4
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total6 = total6 - readings6[readIndex];
  // read the sensor:
  readings6[readIndex] = sensor7.capacitiveSensor(sensitivity);
  // add value to total:
  total6 = total6 + readings6[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total6 / numReadings;

  return average;
}
long programa6() { //pines 9,A5
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total7 = total7 - readings7[readIndex];
  // read the sensor:
  readings7[readIndex] = sensor8.capacitiveSensor(sensitivity);
  // add value to total:
  total7 = total7 + readings7[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total7 / numReadings;

  return average;
}
long programa7() { //pines 9,A6
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total8 = total8 - readings8[readIndex];
  // read the sensor:
  readings8[readIndex] = sensor9.capacitiveSensor(sensitivity);
  // add value to total:
  total8 = total8 + readings8[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total8 / numReadings;

  return average;
}
long programa8() { //pines 9,A7
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total9 = total9 - readings9[readIndex];
  // read the sensor:
  readings9[readIndex] = sensor10.capacitiveSensor(sensitivity);
  // add value to total:
  total9 = total9 + readings9[readIndex];
  // handle index
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  // calculate the average:
  average = total9 / numReadings;

  return average;
}
/*
   ---------------
   inicio del cilo
   ---------------
*/

void ciclo() {
  // cuando se cumple el tiempo termina el ciclo
  tiempo();
  // long programa0 =  sensor2.capacitiveSensor(30);//9,11
  // long programa1 =  sensor3.capacitiveSensor(30);//9,10
  // long programa2 =  sensor4.capacitiveSensor(30);//9,A1
  // long programa3 =  sensor5.capacitiveSensor(30);//9,A2
  // long programa4 =  sensor6.capacitiveSensor(30);//9,A3
  // long programa5 =  sensor7.capacitiveSensor(30);//9,A4
  // long programa6 =  sensor8.capacitiveSensor(30);//9,A5
  // long programa7 =  sensor9.capacitiveSensor(30);//9,A6
  // long programa8 =  sensor10.capacitiveSensor(30);//9,A7


  if ((programa0 > 600 ) && (randomNumber == 9)) {//7
    digitalWrite(7, LOW);
    aleatorio(espera(contador));
  }
  if ((programa1 > 600 ) && (randomNumber == 8)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B10000000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa2 > 600 ) && (randomNumber == 7)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B010000000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa3 > 600 ) && (randomNumber == 6)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00100000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa4 > 600 ) && (randomNumber == 5)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00010000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa5 > 600 ) && (randomNumber == 4)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00001000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa6 > 600 ) && (randomNumber == 3)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000100
    aleatorio(espera(contador));
  }
  if ((programa7 > 600 ) && (randomNumber == 2)) {
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000010
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa8 > 600 ) && (randomNumber == 1)) {
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
  // long inicio =  sensor1.capacitiveSensor(30);
  //si se toca el sensor
  if (inicio > 600) {
    //prende el LED del pin 6
    digitalWrite(6, HIGH);
    // imprime inicio en el puerto de serie
    Serial.println("inicio ");
    //espera 1000ms
    delay(1000);
    // hace el primer random
    ledWrite(milistaLed[randomNumber]);
    //inicia la fuciión ciclo
    ciclo();
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

    // prende todos los led
    shiftOut(pinData, pinClock, LSBFIRST, B11111111);
    digitalWrite(pinLatch, HIGH);
    digitalWrite(7, HIGH);

    //espera 1500ms
    delay(1500);

    // apaga todos los led
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    digitalWrite(pinLatch, LOW);
    digitalWrite(7, LOW);

    //apaga el LED de inicio
    digitalWrite(6, LOW);

    //espera 150ms
    delay(150);

    // imprime fin de ciclo en el puerto de serie
    Serial.println("fin de ciclo");

    // pone el contador en 1
    contador = 1;
    
    // vuelve a loop()
    loop;
  }
}
void loop() {
  iniciarCiclo();

}
