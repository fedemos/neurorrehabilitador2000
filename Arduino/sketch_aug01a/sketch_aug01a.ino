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
CapacitiveSensor cs  = CapacitiveSensor(9, 12);

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
  Serial.println(smooth());
}

long smooth() { /* function smooth */
  ////Perform average on sensor readings
  long average;
  // subtract the last reading:
  total = total - readings[readIndex];
  // read the sensor:
  readings[readIndex] = cs.capacitiveSensor(sensitivity);
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
