#include <Servo.h>
#define trigPin 6
#define echoPin 5

Servo myservo;
int pos = 0;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(8);
}

int getDistance() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  return distance;
}

void loop() {
  int distance = getDistance();
  Serial.println(distance);
  if (distance < 20) {
    Serial.println("rotate to 180");
    myservo.write(180);
    delay(6000);
    Serial.println("rotate to 0");
    myservo.write(0);
  }
  delay(1000);
}
