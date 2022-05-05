/*
   ---------
   programas
   ---------
*/

//Parameters
bool autocal, autocal1, autocal2, autocal3, autocal4, autocal5, autocal6, autocal7, autocal8, autocal9  = 0;
const int numReadings  = 10;
long readings [numReadings], readings1 [numReadings], readings2 [numReadings], readings3 [numReadings], readings4 [numReadings], readings5 [numReadings], readings6 [numReadings], readings7 [numReadings], readings8 [numReadings], readings9 [numReadings];
int readIndex, readIndex1, readIndex2, readIndex3, readIndex4, readIndex5, readIndex6, readIndex7, readIndex8, readIndex9  = 0;
long total, total1, total2, total3, total4, total5, total6, total7, total8, total9  = 0;
const int sensitivity  = 600;
//const int thresh  = 200;
//const int csStep  = 10000;

// libreria para sensor capasitivo
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
long inicio() { //pines 7,8
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

long programa0() { //pines 7,9
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
long programa1() { //pines 7,12
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

long programa2() { //pines 7,11
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
long programa3() { //pines 7,10
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
long programa4() { //pines 7,A1
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
long programa5() { //pines 7,A2
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
long programa6() { //pines 7,A3
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
long programa7() { //pines 7,A4
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
long programa8() { //pines 7,A5
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
