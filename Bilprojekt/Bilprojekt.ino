/*
  File: Bilprojekt
  Author: Elias Svensson
  Date: 2025-02-22
  Description: This program makes a car with 2 engines drive by itself.
*/

// creates all the variables
int rightEngine = 8; // setting the variable for the right engine to digital pin 8
int leftEngine = 9; // setting the variable for the left engine to digital pin 9
const int sensorPinRight = 2; // setting the variable for the sensor on the right to digital pin 2
const int sensorPinFrontRight = 3; // setting the variable for the sensor located to the right of the front on the car to digital pin 3
const int sensorPinFrontLeft = 4; // setting the variable for the sensor located to the left of the front on the car to digital pin 4
const int sensorPinLeft = 5; // setting the variable for the sensor on the left to digital pin 5
bool wallRight; // variable for the sensor on the right, which will be set to true or false
bool wallLeft; // variable for the sensor on the left, which will be set to true or false
bool wallFrontRight; // variable for the sensor which is located on the right side of the front, which will be set to true or false
bool wallFrontLeft; // variable for the sensor which is located on the left side of the front, which will be set to true or false

// starting all the sensors and engines
void setup() {
  pinMode(rightEngine, OUTPUT); // setting pin 8 to output
  pinMode(leftEngine, OUTPUT); // setting pin 9 to output
  pinMode(sensorPinRight, INPUT); // setting pin 2 to input
  pinMode(sensorPinFrontRight, INPUT); // setting pin 3 to input
  pinMode(sensorPinFrontLeft, INPUT); // setting pin 4 to input
  pinMode(sensorPinLeft, INPUT); // setting pin 5 to input
}

// runnning the functions
void loop() {
  rightSensor(); // function for sensor to the right
  frontSensorRight(); // function for front right sensor
  frontSensorLeft(); // function for front left sensor
  leftSensor(); // function for sensor to the left
  Gas(); // function for starting and stopping the engines
}

/*
  Checking if the sensor to the right finds a wall
  Parameters: void
  Returns: variable wallRight as true or false
*/
void rightSensor() {
  int sensorValueRight = digitalRead(sensorPinRight); // creating variable for the value of what the sensor to the right reads
  if (sensorValueRight == LOW) { // runs if there is a wall on the right
    wallRight = true; // setting boolean to true
  } else { // runs if there is no wall to the right
    wallRight = false; // setting boolean to false
  }
}

/*
  Checking if the right sensor on the front finds a wall
  Parameters: void
  Returns: variable wallFrontRight as true or false
*/
void frontSensorRight() {
  int sensorValueFront = digitalRead(sensorPinFrontRight); // creating variable for the value of what the sensor on the front to the right reads
  if (sensorValueFront == LOW) { // runs if there is a wall in front of the sensor
    wallFrontRight = true; // setting boolean to true
  } else { // runs if there is no wall in front of the sensor
    wallFrontRight = false; // setting boolean to false
  }
}

/*
  Checking if the left sensor on the front finds a wall
  Parameters: void
  Returns: variable wallFrontLeft as true or false
*/
void frontSensorLeft() {
  int sensorValueFront = digitalRead(sensorPinFrontLeft); // creating variable for the value of what the sensor on the front to the left reads
  if (sensorValueFront == LOW) { // runs if there is a wall in front of the sensor
    wallFrontLeft = true; // setting boolean to true
  } else { // runs if there is no wall in front of the sensor
    wallFrontLeft = false; // setting boolean to false
  }
}


/*
  Checking if the sensor on the left finds a wall
  Parameters: void
  Returns: variable wallLeft as true or false
*/
void leftSensor() {
  int sensorValueLeft = digitalRead(sensorPinLeft); // creating variable for the value of what the sensor on the left reads
  if (sensorValueLeft == LOW) { // runs if there is a wall in front of the sensor
    wallLeft = true; // setting boolean to true
  } else { // runs if there is no wall in front of the sensor
    wallLeft = false; // setting boolean to false
  }
}

/*
  Starts and stops the engines depending on what the wall variables are set to
  Parameters: void
  Returns: void
*/
void Gas() {
  if (wallLeft == true) { // if statement runs if there is a wall to the left
    digitalWrite(leftEngine, HIGH); // engine on the left continues
    digitalWrite(rightEngine, LOW); // engine on the right stops
    delay(300); // adds a delay to the engines so that they stop every 300ms
  } else if (wallFrontLeft == true) { // first else if statement runs if there is a wall infront of the sensor that is located to the left on the front
    digitalWrite(leftEngine, HIGH); // engine on the left continues
    digitalWrite(rightEngine, LOW); // engine on the right stops
    delay(300); // adds a delay to the engines so that they stop every 300ms
  } else if (wallFrontRight == true) { // second else if statement runs if there is a wall in front of the sensor that is located to the right on the front
    digitalWrite(leftEngine, LOW); // engine on the left stops
    digitalWrite(rightEngine, HIGH); // engine on the right continues
    delay(300); // adds a delay to the engines so that they stop every 300ms
  } else if (wallRight == true) { // third else if statement runs if there is a wall to the right 
    digitalWrite(leftEngine, LOW); // engine on the left stops
    digitalWrite(rightEngine, HIGH); // engine on the right continues
    delay(300); // adds a delay to the engines so that they stop every 300ms
  } else if (wallFrontLeft == true && wallFrontRight == true) { // last else if statement runs if there is a wall in front of both of the sensors on the front
    digitalWrite(leftEngine, HIGH); // engine on the left continues
    digitalWrite(rightEngine, LOW); // engine on the right continues
  }
  else { // else statement runs if all other statements are false
    digitalWrite(leftEngine, HIGH); // engine on the left continues
    digitalWrite(rightEngine, HIGH); // engine on the right continues
    delay(300); // adds a delay to the engines so that they stop every 300ms
  }
  digitalWrite(leftEngine, LOW); //every 300ms the left engine will stop
  digitalWrite(rightEngine, LOW); // every 300ms the right engine will stop
  delay(100); // the engines will stop for 100ms

}
