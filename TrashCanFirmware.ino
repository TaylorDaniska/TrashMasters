//////////////////////////////////////////////////////////////////////
//  The Trash Master's Trash Can                                    //
//  CPT 264 Final Project                                           //
//  Taylor Daniska, Michael Orr, Jacob Strickland, and Ryan Parker  //
//                                                                  //
//  Ultrasonic sensor controls servo to open trash can lid          //
//////////////////////////////////////////////////////////////////////
#include <Servo.h>

void openlid(int);
int getspeed();

Servo servo1;

const int triggerpin = 9;
const int echopin = 10;
const int servopin = 11;
int servoposition = 0;
long duration;
int distance;
int minrotate = 0;
int maxrotate = 90;
int mindist = 10;

void setup() {
  servo1.attach(servopin);
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

void loop() {
  servo1.write(minrotate);
    while (1){
    distance = getspeed();
Serial.print("Distance: ");
Serial.println(distance);
  if (distance<mindist)
    openlid(5);
  }
}
int getspeed(){
    digitalWrite(triggerpin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerpin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerpin, LOW);
    duration = pulseIn(echopin, HIGH);
    distance= duration*0.034/2;
    return distance;
}

void openlid(int openduration){
  servo1.write(maxrotate);
  delay(1000*openduration);
  servo1.write(minrotate);
}


