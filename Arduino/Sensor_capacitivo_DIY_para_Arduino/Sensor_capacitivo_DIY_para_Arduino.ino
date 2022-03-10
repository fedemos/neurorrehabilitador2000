#include <CapacitiveSensor.h>

//Crear e indicar pines del sensor
//4 -> Sender 3 -> Receiver
CapacitiveSensor   sensor = CapacitiveSensor(9,12);

void setup()
{
    Serial.begin(9600);
//Pin 13 (led) como salida
pinMode(6,OUTPUT);
}

void loop()
{
//Almacenar lectura del sensor en una variable
long lectura =  sensor.capacitiveSensor(30);

//Comparar lectura
if(lectura > 60){
  Serial.println("on");
digitalWrite(6,HIGH);}

else{
digitalWrite(6,LOW);
  Serial.println("off");
delay(10);}
}
