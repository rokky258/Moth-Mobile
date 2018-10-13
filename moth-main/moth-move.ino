///*#include <L298N.h>
//
//#define ENA 10
//#define IN1 9
//#define IN2 8
//#define IN3 7
//#define IN4 6
//#define ENB 5
//L298N motorA(ENA, IN1, IN2);
//L298N motorB(ENB, IN3, IN4);
//
//int time_delay = 500;
//int base_speed = 70;
//
//void run_movement_test()
//{
//  motorA.setSpeed(120); // an integer between 0 and 255
//  motorB.setSpeed(120);
//  motorA.forward();
//  motorB.forward();
//  /*
//  drive_at_angle(1.57,base_speed);
//  delay(2000);
//  drive_at_angle(0.85,base_speed);
//  delay(2000);
//  drive_at_angle(0,base_speed);
//  delay(2000);
//  drive_at_angle(0.85,base_speed);
//  delay(2000);
//  drive_at_angle(1.57,base_speed);
//  delay(2000);
//  motorA.stop();
//  motorB.stop();
//  delay(10000);
//  
//}
//*/
//void drive_at_angle(double rad_angle, double sp){
//   double mapped_val = (sp / PI) * rad_angle; 
//   set_wheel(motorA, mapped_val);
//   set_wheel(motorB, sp - mapped_val);
//}
//
//int set_wheel(L298N motor, int sp) {
//  if (sp > 0){
//    motor.forward();
//  } else {
//    motor.backward();
//  }
//  motor.setSpeed(sp);
//}*/
