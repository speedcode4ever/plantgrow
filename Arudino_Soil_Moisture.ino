int pump1 = 10;
int pump2 = 11;
int pump3 = 9;
int pump4 = 8;
int tarmois1 = 50;
int tarmois2 = 50;
int tarmois3 = 50;
int tarmois4 = 50;
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
int val1 = analogRead(0);
int val2 = analogRead(1);
int val3 = analogRead(2);
int val4 = analogRead(3);
int selector = analogRead(4);
int moisture = analogRead(5);
int selectorquad = map(selector, 0, 1023, 1, 5);
int moisper = map (moisture, 0, 1023, 0, 100);
int sensor1 = map(val1, 236, 506, 100, 0);
int sensor2 = map(val2, 219, 497, 100, 0);
int sensor3 = map(val3, 341, 486, 100, 0);
int sensor4 = map(val4, 232, 505, 100, 0);
//Serial.println(selectorquad);
//Serial.println(moisper);
//Serial.println("val1 = ");
//Serial.println(val1);
//Serial.println("val2 = ");
//Serial.println(val2);
//Serial.println("val3 = ");
//Serial.println(val3);
//Serial.println("val4 = ");
//erial.println(val4);
Serial.println("sensor1 = ");
Serial.println(sensor1);
Serial.println("sensor2 = ");
Serial.println(sensor2);
Serial.println("sensor3 = ");
Serial.println(sensor3);
Serial.println("sensor4 = ");
Serial.println(sensor4);
if (selectorquad == 1) {
  tarmois1 = moisper;
  }
if (selectorquad == 2) {
  tarmois2 = moisper;
  }
if (selectorquad == 3) {
  tarmois3 = moisper;
  }
if (selectorquad == 4) {
  tarmois4 = moisper;
  }
if (sensor1 < tarmois1) {
     digitalWrite(pump1, LOW);
  }
else {
  digitalWrite(pump1, HIGH);
  }
if (sensor2 < tarmois2) {
     digitalWrite(pump2, LOW);
  }
else {
  digitalWrite(pump2, HIGH);
  }
if (sensor3 < tarmois3) {
     digitalWrite(pump3, LOW);
  }
else {
  digitalWrite(pump3, HIGH);
  }
if (sensor4 < tarmois4) {
     digitalWrite(pump4, LOW);
  }
else {
  digitalWrite(pump4, HIGH);
  }
//Serial.print("quad: ");
//Serial.println(selectorquad);
//Serial.print("tarmois1: ");
//Serial.println(tarmois1);
//Serial.print("tarmois2: ");
//Serial.println(tarmois2);
//Serial.print("tarmois3: ");
//Serial.println(tarmois3);
//Serial.print("tarmois4: ");
//Serial.println(tarmois4);
delay(1000);
}
