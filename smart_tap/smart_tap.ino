const int pinInfraRed = A0;
const int pinReley = 13;
int obstacleDistance = 0;

void setup() {
  pinMode(pinReley, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  obstacleDistance = analogRead(pinInfraRed);
  Serial.println(obstacleDistance);
  
  if(obstacleDistance > 650) {
    Serial.println("Activating relay...");
    digitalWrite(pinReley, LOW);
    delay(2000);
  } else {
    digitalWrite(pinReley, HIGH);
  }
}
