#include <L298N.h>

// Set array of sensor pins
// A5 Front, A4 Back, A3 Left, A2 Right
int sensorPins[] = {A5, A4, A3, A2};

// Set value of sensors
int front = 0;
int back = 0;
int left = 0;
int right = 0;

// Direction movement
double xDirection, yDirection = 0;

void setup() {
  Serial.begin(9600);
}


void loop() {
  // Get Value Of Light Sensors
  front = 1000 - analogRead(A5);
  back = 1000 - analogRead(A4);
  left = 1000 - analogRead(A3);
  right = 1000 - analogRead(A2);

 // testCalculateDirection(front, back, left, right);
  drive_at_angle(calculateDirection(front,back,left,right),150);
  delay(1000);
}

void testCalculateDirection(int front, int back, int left, int right) {
  Serial.print("up:");
  Serial.println(front);
  Serial.print("down:");
  Serial.println(back);
  Serial.print("left:");
  Serial.println(left);
  Serial.print("right:");
  Serial.println(right);
  Serial.print("direction:");
  Serial.println(calculateDirection(front, back, left, right));
}

double calculateDirection(int up, int down, int left, int right){
  yDirection = up - down;
  xDirection = right - left;
  return(atan2(yDirection,xDirection));
}
