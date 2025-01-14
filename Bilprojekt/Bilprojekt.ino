int hogermotor = 9;
int vanstermotor = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(hogermotor, OUTPUT);
  pinMode(vanstermotor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000);
  digitalWrite(hogermotor, HIGH);
  digitalWrite(vanstermotor, HIGH);
  delay(3000);
  digitalWrite(hogermotor, LOW);
  delay(3000);
  digitalWrite(hogermotor, HIGH);
  digitalWrite(vanstermotor, LOW);
  delay(3000);
  digitalWrite(hogermotor, LOW);

}
