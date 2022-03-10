int milistaLed[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
long randomNumber;
int pinData  = 2;//4;
int pinLatch = 3;//5;
int pinClock = 4;//6;
void ledWrite(int Led) {
  //digitalWrite(12, LOW);
  digitalWrite(pinLatch, LOW);
  shiftOut(pinData, pinClock, LSBFIRST, Led);
  digitalWrite(pinLatch, HIGH);
}
void setup() {
  // put your setup code here, to run once:
  // los pines para controlar el 74hc595
  pinMode(pinData, OUTPUT);
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);
    randomSeed(analogRead(A0));
}

void loop() {
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
// da un número del 0 al 8
  randomNumber = random(8);

  //tiempo de espera antes de hacer el random
  delay(500);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  // prende el led
  ledWrite(milistaLed[randomNumber]);

}
