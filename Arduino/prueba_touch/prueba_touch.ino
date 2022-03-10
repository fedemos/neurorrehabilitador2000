//Libraries
#include <CapacitiveSensor.h>//https://github.com/PaulStoffregen/CapacitiveSensor

//Parameters
bool autocal  = 0;
const int numReadings  = 10;
long readings [numReadings];
int readIndex  = 0;
long total  = 0;
const int sensitivity  = 600;
const int thresh  = 200;
const int csStep  = 10000;
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

void setup() {
  //Init Serial USB
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
  Serial.println(F("1 de agosto de 2021"));
  Serial.println(F("v. 1.0.0"));

  //Init cs
  if (autocal == 0) {
    {
      cs.set_CS_AutocaL_Millis(0xFFFFFFFF);
    }
  }
}

void loop() {
  Serial.print("inicio: );
  Serial.println(inicio());
  Serial.print("programa0: );
  Serial.println(programa0());
  Serial.print("programa1: );
  Serial.println(programa1());
  Serial.print("programa2: );
  Serial.println(programa2());
  Serial.print("programa3: );
  Serial.println(programa3());
  Serial.print("program4: );
  Serial.println(programa4());
  Serial.print("programa5: );
  Serial.println(programa5());
  Serial.print("programa6: );
  Serial.println(programa6());
  Serial.print("programa7: );
  Serial.println(programa7());
  Serial.print("programa8: );
  Serial.println(programa8());
}
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
   
