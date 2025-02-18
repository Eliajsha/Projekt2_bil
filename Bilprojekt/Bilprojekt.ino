/*
  File: Bilprojekt
  Author: Elias Svensson
  Date: 2025-02-18
  Description: This program makes a car with 2 engines drive by itself.
*/

// creates all the variables
int rightEngine = 8;
int leftEngine = 9;
const int sensorPinRight = 2;
const int sensorPinFrontRight = 3;
const int sensorPinFrontLeft = 4;
const int sensorPinLeft = 5;
bool wallRight;
bool wallLeft;
bool wallFrontRight;
bool wallFrontLeft;

// starting all the sensors and engines
void setup() {
  pinMode(rightEngine, OUTPUT);
  pinMode(leftEngine, OUTPUT);
  pinMode(sensorPinRight, INPUT);
  pinMode(sensorPinFrontRight, INPUT);
  pinMode(sensorPinFrontLeft, INPUT);
  pinMode(sensorPinLeft, INPUT);
}

// runnning the functions
void loop() {
  rightSensor();          // function for sensor to the right
  frontSensorRight();     // function for front right sensor
  frontSensorLeft();      // function for front left sensor
  leftSensor();           // function for sensor to the left
  Gas();                  // function for driving the engines
}

void rightSensor() {
  int sensorValueRight = digitalRead(sensorPinRight);
  if (sensorValueRight == LOW) {
    wallRight = true; //if tg
  } else {
    wallRight = false;
  }
}

// den här funktionen kollar om det finns ett hinder framför bilen. Om det gör det sätter den variabeln till true, annars false
void frontSensorRight() {
  int sensorValueFront = digitalRead(sensorPinFrontRight);
  if (sensorValueFront == LOW) {
    wallFrontRight = true;
  } else {
    wallFrontRight = false;
  }
}

void frontSensorLeft() {
  int sensorValueFront = digitalRead(sensorPinFrontLeft);
  if (sensorValueFront == LOW) {
    wallFrontLeft = true;
  } else {
    wallFrontLeft = false;
  }
}


// den här funktionen kollar om det finns ett hinder till vänster om bilen. Om det gör det sätter den variabeln till true, annars false
void leftSensor() {
  int sensorValueLeft = digitalRead(sensorPinLeft);
  if (sensorValueLeft == LOW) {
    wallLeft = true;
  } else {
    wallLeft = false;
  }
}

void Gas() {
  if (wallLeft == true) {
    digitalWrite(leftEngine, HIGH);
    digitalWrite(rightEngine, LOW);
    delay(300);
  } else if (wallFrontLeft == true) {
    digitalWrite(leftEngine, HIGH);
    digitalWrite(rightEngine, LOW);
    delay(300);
  } else if (wallFrontRight == true) {
    digitalWrite(leftEngine, LOW);
    digitalWrite(rightEngine, HIGH);
    delay(300);
  } else if (wallRight == true) {
    digitalWrite(leftEngine, LOW);
    digitalWrite(rightEngine, HIGH);
    delay(300);
  } else if (wallFrontLeft == true && wallFrontRight == true) {
    digitalWrite(leftEngine, HIGH);
    digitalWrite(rightEngine, LOW);
  }
  else {
    digitalWrite(leftEngine, HIGH);
    digitalWrite(rightEngine, HIGH);
    delay(300);
  }
  digitalWrite(leftEngine, LOW);
  digitalWrite(rightEngine, LOW);
  delay(100);

}
