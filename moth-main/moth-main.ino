#include <L298N.h>

#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5
L298N motorA(ENA, IN1, IN2);
L298N motorB(ENB, IN3, IN4);

// put your setup code here, to run once:
int sensorPins[] = {A5, A4, A3, A2}; // select the input pin for the potentiometer

//A5 Front, A4 Back, A3 Left, A2 Right
int ledPin = 13; // select the pin for the LED
int sensorValues[] = {0,0,0,0}; // vasriable to store the value coming from the sensor

int front = 0;
int back = 0;
int left = 0;
int right = 0;

double xDirection, yDirection = 0;


void setup() {
  // Test Values
  front = 10;
  motorA.setSpeed(80); // an integer between 0 and 255
  motorB.setSpeed(80);
  Serial.begin(9600);
  //run_movement_test();
}


void loop() {
  front = 1000 - analogRead(A5);
  back = 1000 - analogRead(A4);
  //left = 1000 - analogRead(A3);
  //right = 1000 - analogRead(A2);
  if (front >= back) {
    motorA.forward();
    motorB.forward();  
  } else {
    motorA.backward();
    motorB.backward();
  }
}

void testCalculateDirection() {
  Serial.print("up:");
  Serial.println(sensorValues[0]);
  Serial.print("down:");
  Serial.println(sensorValues[1]);
  Serial.print("left:");
  Serial.println(sensorValues[2]);
  Serial.print("right:");
  Serial.println(sensorValues[3]);
  delay(2000);
  Serial.println(calculateDirection(sensorValues[0],sensorValues[1],sensorValues[2],sensorValues[3]), DEC);
}

double calculateDirection(int up, int down, int left, int right){
  yDirection = up - down;
  xDirection = right - left;
  return(atan2(yDirection,xDirection));
}
