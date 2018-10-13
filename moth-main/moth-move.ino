#include <L298N.h>
const int ENA = 10;
const int IN1 = 9;
const int IN2 = 8;
const int IN3 = 7;
const int IN4 = 6;
const int ENB = 5;
L298N driver(ENA,IN1,IN2,IN3,IN4,ENB); 
int time_delay = 500;
int base_speed = 150;
int w_left = L298N::MOTOR_A;
int w_right = L298N::MOTOR_B;

void run_movement_test()
{
   drive_at_angle(1.57,base_speed);
  delay(2000);
  drive_at_angle(0.85,base_speed);
  delay(2000);
  drive_at_angle(0,base_speed);
  delay(2000);
  drive_at_angle(0.85,base_speed);
  delay(2000);
  drive_at_angle(1.57,base_speed);
  delay(2000);
  driver.full_stop();
  delay(10000);
}

void drive_at_angle(double rad_angle,sp){
   double mapped_val = (sp/ PI) * rad_angle; 
   set_wheel(w_left, mapped_val);
   set_wheel(w_right, sp - mapped_val);
}

int set_wheel(int motor, int speed) {
  if (speed > 0){
    driver.setup_motor(motor,HIGH,LOW);
  } else {
    driver.setup_motor(motor,LOW,HIGH);
  }
  driver.drive_motor(motor,speed);
}
