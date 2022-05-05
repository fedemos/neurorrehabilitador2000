/*
  Autor: fedemos
  licencia: gpl3
  fecha: 7/11/2021
  versión: 0.0.10
*/
#include "programas.h"

//
int nu;
int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
int contador = 1;
int milistaLed[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000 };
long randomNumber;
long randomNumberold =  1;

void aleatorio();
long inicio();
long programa0();
long programa1();
long programa2();
long programa3();
long programa4();
long programa5();
long programa6();
long programa7();
long programa8();
void iniciarCiclo();
void tiempo();
void ledWrite();
int espera();
unsigned long tiempos = millis();

void ciclo();
void ruleta() {
  // da un número del 0 al 8
  randomNumber = random(9);
}

//-------------------------
void setup() {
  Serial.begin(9600);
  Serial.println("Autor: fedemos");
  Serial.println("licencia: gpl3 ");
  Serial.println("fecha: 7/11/2021");
  Serial.println("versión: 0.0.10");

  // los pines para controlar el 74hc595
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
  shiftOut(pinData, pinClock, LSBFIRST, B00000000);
  digitalWrite(pinLatch, LOW);
  //para hacer que el random sea seudo aleatorio
  randomSeed(analogRead(A0));

  //enciende el pin 13
  digitalWrite(13, HIGH);

}
void loop() {
  iniciarCiclo();

}
/*
  ---------------------------
  función random
  ---------------------------
*/

void aleatorio(int x) {

  // da un número del 0 al 8

  ruleta();
  //randomNumber = random(9);
  //
  if (randomNumber == randomNumberold) {

    // da un número del 0 al 8
    //randomNumber = random(9);
    ruleta();
    //luego de hacer el random repetido le resta 1 al contador
    contador--;
  }
  else {

    // prende el led
    ledWrite(milistaLed[randomNumber]);
    nu = milistaLed[randomNumber];
    //luego de hacer el random le suma 1 al contador
    contador++;

    //
    randomNumberold = randomNumber;
    //tiempo de espera antes de hacer el random
    delay(x);
  }
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


  if ((programa0() > 180) && (randomNumber == 8)) {//5-R8-9
    // imprime el numero cuando se presiona
    Serial.print(programa0());
    Serial.println(" - programa0");
    // apaga el led
    digitalWrite(5, LOW);
    aleatorio(espera(contador));
  }
  if ((programa1() > 180) && (randomNumber == 7)) {// Q0-R7-12
    Serial.print(programa1());
    Serial.println(" - programa1");

    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B10000000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa2() > 180) && (randomNumber == 6)) {//Q1-R6-11
    Serial.print(programa2());
    Serial.println(" - programa2");
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B010000000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa3() > 180) && (randomNumber == 5)) {//Q2-R5-10
    Serial.print(programa3());
    Serial.println(" - programa3");
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00100000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa4() > 180) && (randomNumber == 4)) {//Q3-R4-A1
    Serial.print(programa4());
    Serial.println(" - programa4");
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00010000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa5() > 180) && (randomNumber == 3)) {//Q4-R3-A2
    Serial.print(programa5());
    Serial.println(" - programa5");
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00001000
    digitalWrite(pinLatch, LOW);
    aleatorio(espera(contador));
  }
  if ((programa6() > 180) && (randomNumber == 2)) {//Q5-R2-A3
    Serial.print(programa6());
    Serial.println(" - programa6");
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000100
    aleatorio(espera(contador));
  }
  if ((programa7() > 180) && (randomNumber == 1)) {//Q6-R1-A4
    Serial.print(programa7());
    Serial.println(" - programa7");
    digitalWrite(pinLatch, LOW);
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);//B00000010
    digitalWrite(pinLatch, HIGH);
    aleatorio(espera(contador));
  }
  if ((programa8() > 180) && (randomNumber == 0)) {//Q7-R0-A5
    Serial.print(programa8());
    Serial.println(" - programa8");
    digitalWrite(pinLatch, LOW);
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

  // valores de los sensores capacitivos
  //  Serial.print(inicio());
  //   Serial.println(" - inicio");
  //   Serial.print(programa0());
  //     Serial.println(" - programa0");
  //   Serial.print(programa1());
  //     Serial.println(" - programa1");
  //        Serial.print(programa2());
  //     Serial.println(" - programa2");
  //   Serial.print(programa3());
  //   Serial.println(" - programa3");
  // Serial.print(programa4());
  //  Serial.println(" - programa4");
  // Serial.print(programa5());
  //  Serial.println(" - programa5");
  //  Serial.print(programa6());
  //   Serial.println(" - programa6");
  //  Serial.print(programa7());
  //   Serial.println(" - programa7");
  // Serial.print(programa8());
  // Serial.println(" - programa8");



  //si se toca el sensor
  if (inicio() > 180) {
    //delay(100);

    //prende el LED del pin 6
    digitalWrite(6, HIGH);
    // imprime inicio en el puerto de serie
    Serial.print(inicio());
    Serial.println(" - inicio");
    //espera 1000ms
    delay(1000);

    //   ruleta();

    // hace el primer random
    ledWrite(milistaLed[random(9)]);

    //luego de hacer el random le suma 1 al contador
    //contador++;
    //
    Serial.print(randomNumber, DEC);
    Serial.println(" - número random");

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
  unsigned long intervalo = 60000; // 1 minuto
  unsigned long ahora = millis();
  if (ahora - tiempos >= intervalo) { //si se cumple 1 minuto
    tiempos = ahora;

    // prende todos los led
    shiftOut(pinData, pinClock, LSBFIRST, B11111111);
    digitalWrite(pinLatch, HIGH);
    digitalWrite(5, HIGH);

    //espera 1500ms
    delay(1500);

    // apaga todos los led
    shiftOut(pinData, pinClock, LSBFIRST, B00000000);
    digitalWrite(pinLatch, LOW);
    digitalWrite(5, LOW);

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

/*
    --------------------------------------
    prende el Led aleatoreo
   --------------------------------------
*/

void ledWrite(int Led) {
  if (milistaLed[randomNumber] == 8) {
    digitalWrite(5, HIGH);
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

  // si el x es menor o igual a 6 el tiempo es de 1000ms
  if (x <= 9) { //1
    return 300;
  }
  // si el x es mayor a 9 o menoro igual a 18 el tiempo es de 500ms
  else if (x > 9 or x <= 18) { //2
    return 250;
  }
  // si el x es mayor a 18 o menor o igual a 27 el tiempo es de 250ms
  else if (x < 18 or x <= 27) {//3
    return 200;
  }
  // si no se dan las otras hipótesis el tiempo es de 50ms
  else  {//5
    return 150;
  }


}

// ----------------------------------

