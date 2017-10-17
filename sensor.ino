#include <Servo.h>

#define trigPin 2
#define echoPin 3
#define led 4

Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 10) {  // This is where the LED On/Off happens
    Serial.write(4);
    digitalWrite(led,LOW);
    myservo.write(120);                  // sets the servo position according to the scaled value
    delay(1000);
  }
  else {
    digitalWrite(led,HIGH);
    myservo.write(50); 
    delay(1000);
  }
}
