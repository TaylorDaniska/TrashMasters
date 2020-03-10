//////////////////////////////////////////////////////////////////////
//  The Trash Master's Trash Can                                    //
//  CPT 264 Final Project                                           //
//  Taylor Daniska, Michael Orr, Jacob Strickland, and Ryan Parker  //
//                                                                  //
//  Ultrasonic sensor controls servo to open trash can lid          //
//////////////////////////////////////////////////////////////////////
#include <Servo.h>

Servo servo1;

const int triggerpin = 8;
const int echopin = 10;
const int servopin = 9;
int servoposition = 0;
long duration;
int distance;

void setup() {
  servo1.attach(servopin);
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
  for (servoposition=0;servoposition<=180;servoposition++){ 
    servo1.write(servoposition);              
    delay(20);}
  for (servoposition=180;servoposition>=0;servoposition++){ 
    servo1.write(servoposition);              
    delay(20);}
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance= duration*0.034/2;
}
