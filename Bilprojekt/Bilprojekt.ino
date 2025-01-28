// skapa alla variabler som är globala
int hogermotor = 9;
int vanstermotor = 8;
const int sensorPinRight = 2;
const int sensorPinFrontRight = 3;
const int sensorPinFrontLeft = 4;
const int sensorPinLeft = 5;
int wallRight;
int wallLeft;
int wallFrontRight;
int wallFrontLeft;

// starta alla pins som styr motorerna samt tar in info från sensorerna
void setup() {
  pinMode(hogermotor, OUTPUT);
  pinMode(vanstermotor, OUTPUT);
  pinMode(sensorPinRight, INPUT);
  pinMode(sensorPinFrontRight, INPUT);
  pinMode(sensorPinFrontLeft, INPUT);
  pinMode(sensorPinLeft, INPUT);
}

// kalla på alla funktioner som ska köras
void loop() {
  rightSensor();
  frontSensorRight();
  frontSensorLeft();
  leftSensor();
  Gas();
  /*hogerGas();
  vansterGas();*/
}

// den här funktionen kollar om det finns ett hinder till högor om bilen. Om det gör det sätter den variabeln till true, annars false
 void rightSensor() {
  int sensorValueRight = digitalRead(sensorPinRight);
  if (sensorValueRight == LOW) {
    wallRight = true;
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
  Serial.println(wallLeft);
  delay(200);
 }

/*den här funktionen styr högermotorn till bilen. Om sensorn framför bilen upptäcker ett hinder så stoppar den motorn, och om det finns vägg 
framför och till vänster om bilen stoppar den oxå motorn 

 void hogerGas() {
  if (wallFront == false) {
    digitalWrite(hogermotor, HIGH);
  } else {
    digitalWrite(hogermotor, LOW);
  }

/* TILL NÄSTA GÅNG!
  kolla nästa gång om det bortkommenterade är korrekt eller inte. 
  Möjligtvis oxå göra så att båda motorerna bara har en funktion istället för 2 
  if (wallLeft == true) {
    digitalWrite(hogermotor, LOW);
  }
 }

/*den här funktionen styr vänstermotorn till bilen. Om sensorn framför bilen upptäcker ett hinder så stoppar den motorn, och om det finns vägg 
framför och till höger om bilen stoppar den oxå motorn 
 void vansterGas () {
    if (wallFront == false) {
    digitalWrite(vanstermotor, HIGH);
  } else {
    digitalWrite(vanstermotor, LOW);
  }

  if (wallRight == true) {
    digitalWrite(vanstermotor, LOW);
  }
 }
 */
 void Gas() {
  if (wallFrontRight == false && wallFrontLeft == false) {
    digitalWrite(vanstermotor, HIGH);
    digitalWrite(hogermotor, HIGH);
  } else {
    digitalWrite(vanstermotor, LOW);
    digitalWrite(hogermotor, LOW);
  }
  if (wallRight == true ) {
    digitalWrite(vanstermotor, LOW);
  }
    
  if (wallLeft == true) {
    digitalWrite(hogermotor, LOW);
  }
 }



