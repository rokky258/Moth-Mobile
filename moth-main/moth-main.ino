#include <L298N.h>

// Initialize Motors
#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define ENB 5
L298N motorA(ENA, IN1, IN2);
L298N motorB(ENB, IN3, IN4);

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

#define base_speed 80

void setup() {

  // Set up motor speed
  motorA.setSpeed(80); // an integer between 0 and 255
  motorB.setSpeed(80);
  Serial.begin(9600);
}


void loop() {
  // Get Value Of Light Sensors
  front = 1000 - analogRead(A5);
  back = 1000 - analogRead(A4);
  left = 1000 - analogRead(A3);
  right = 1000 - analogRead(A2);
  testCalculateDirection(front, back, left, right);
  delay(5000);
}

void testCalculateDirection(int front, int back, int left, int right) {
 /*
  Serial.print("up:");
  Serial.println(front);
  Serial.print("down:");
  Serial.println(back);
  Serial.print("left:");
  Serial.println(left);
  Serial.print("right:");
  Serial.println(right);
  */
  drive_at_angle(calculateDirection(front, back, left, right), 60);
  drive_at_angle(1.57,base_speed);
  delay(2000);
  drive_at_angle(0.85,base_speed);
  delay(2000);
  drive_at_angle(0,base_speed);
  delay(2000);
  drive_at_angle(0.85,base_speed);
  delay(2000);
  drive_at_angle(1.57,base_speed);
//  delay(2000);
  delay(2000);
}

double calculateDirection(int up, int down, int left, int right){
  yDirection = up - down;
  xDirection = right - left;
  return(atan2(yDirection,xDirection));
}


void drive_at_angle(double rad_angle, double sp){
   double mapped_val = (sp / PI) * rad_angle; 
   Serial.print(mapped_val);
   Serial.print(" : "); 
   set_wheel(motorA, mapped_val);
   Serial.println(sp - mapped_val);
   set_wheel(motorB, sp - mapped_val);
}

int set_wheel(L298N motor, int sp) {
  if (sp >= 0){
    motor.forward();
  } else {
    motor.backward();
  }
  motor.setSpeed(sp);
}
