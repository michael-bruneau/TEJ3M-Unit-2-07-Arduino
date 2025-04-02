/*
  Created by: Michael Bruneau
  Created on: March 2025

  This Arduio program causes micro Servo to to turn back and forth from 180 degress to 0 degrees
*/

#include <Servo.h>

Servo servoNumber1;

// variables & constants
const int TRIG_PIN = 11;
const int ECHO_PIN = 10;
const int MICRO_SERVO_SIGNAL_PIN = 8;
const int MICRO_SERVO_POWER_PIN = 7;
long duration;
int distance = 0;
int trigDelays[] = {2, 10};
const float SPEED_OF_SOUND = 0.034;
const int TOO_CLOSE = 50;

void setup()
{
  // Setups pins
  pinMode(TRIG_PIN, OUTPUT); // Sets the trigPin as an Output
  pinMode(ECHO_PIN, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  servoNumber1.attach(MICRO_SERVO_SIGNAL_PIN);
  servoNumber1.write(0);
  pinMode(MICRO_SERVO_POWER_PIN, OUTPUT);
}


void loop() {
  	// sends pulse
  	digitalWrite(TRIG_PIN, LOW);
  	delayMicroseconds(trigDelays[0]);
  	digitalWrite(TRIG_PIN, HIGH);
  	delayMicroseconds(trigDelays[1]);
  	digitalWrite(TRIG_PIN, LOW);
  
 	//recieves pulse
  	duration = pulseIn(ECHO_PIN, HIGH);
      
    // Calculating the distance
  	distance = duration * SPEED_OF_SOUND / 2;

  	// Prints the distance on the Serial Monitor
  	Serial.print("Distance: ");
  	Serial.println(distance);
    Serial.println(" cm");
  
  	// Turns on LED if a object gets close to the sonar
  	if (distance <= TOO_CLOSE) {
    	servoNumber1.write(180);
    } else {
    	servoNumber1.write(0);
    }
        
}
