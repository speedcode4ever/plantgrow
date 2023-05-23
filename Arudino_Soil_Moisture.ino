int pump1 = 10;
int pump2 = 11;
int pump3 = 9;
int pump4 = 8;
int tarmois1 = 50;
int tarmois2 = 50;
int tarmois3 = 50;
int tarmois4 = 50;
int val1;
int val2;
int val3;
int val4;
int selector;
int moisture;
int selectorquad; 
int moisper;
int sensor1;
int sensor2;
int sensor3;
int sensor4;
void setup() {
Serial.begin(9600);
pinMode(pump1,OUTPUT);
pinMode(pump2,OUTPUT);
pinMode(pump3,OUTPUT);
pinMode(pump4,OUTPUT);
digitalWrite(pump1, HIGH);
digitalWrite(pump2, HIGH);
digitalWrite(pump3, HIGH);
digitalWrite(pump4, HIGH);
}
 
void loop() {
ReadData();
MapData();
PrintData();
SetTargetMoisture();
CompareMoisTakeAction();
delay(1000);
}

void ReadData() {
   val1 = analogRead(0);
   val2 = analogRead(1);
   val3 = analogRead(2);
   val4 = analogRead(3);
   selector = analogRead(4);
   moisture = analogRead(5);
  }
void MapData() {
  selectorquad = map(selector, 0, 1023, 1, 5);
  moisper = map (moisture, 0, 1023, 0, 100);
  sensor1 = map(val1, 225, 496, 100, 0);
  sensor2 = map(val2, 212, 491, 100, 0);
  sensor3 = map(val3, 320, 465, 100, 0);
  sensor4 = map(val4, 222, 498, 100, 0);
  }
void PrintData() {
Serial.print("val1 = ");
Serial.println(val1);
Serial.print("val2 = ");
Serial.println(val2);
Serial.print("val3 = ");
Serial.println(val3);
Serial.print("val4 = ");
Serial.println(val4);
Serial.print("sensor1 = ");
Serial.println(sensor1);
Serial.print("sensor2 = ");
Serial.println(sensor2);
Serial.print("sensor3 = ");
Serial.println(sensor3);
Serial.print("sensor4 = ");
Serial.println(sensor4);
Serial.print("quad: ");
Serial.println(selectorquad);
Serial.print("moisper: ");
Serial.println(moisper);
Serial.print("tarmois1: ");
Serial.println(tarmois1);
Serial.print("tarmois2: ");
Serial.println(tarmois2);
Serial.print("tarmois3: ");
Serial.println(tarmois3);
Serial.print("tarmois4: ");
Serial.println(tarmois4);
  }
void SetTargetMoisture() {
if (selectorquad == 1) {
  tarmois1 = moisper;
  }
else if (selectorquad == 2) {
  tarmois2 = moisper;
  }
else if (selectorquad == 3) {
  tarmois3 = moisper;
  }
else {
  tarmois4 = moisper;
  }
 }
void CompareMoisTakeAction() {
  PlantOne();
  PlantTwo();
  PlantThree();
  PlantFour();
  }
void PlantOne() {
if (sensor1 < tarmois1) {
     digitalWrite(pump1, LOW);
  }
else {
  digitalWrite(pump1, HIGH);
  }
}
void PlantTwo() {
if (sensor2 < tarmois2) {
     digitalWrite(pump2, LOW);
  }
else {
  digitalWrite(pump2, HIGH);
  }
}
void PlantThree() {
if (sensor3 < tarmois3) {
     digitalWrite(pump3, LOW);
  }
else {
  digitalWrite(pump3, HIGH);
  }
}
void PlantFour() {
if (sensor4 < tarmois4) {
     digitalWrite(pump4, LOW);
  }
else {
  digitalWrite(pump4, HIGH);
  }
}
