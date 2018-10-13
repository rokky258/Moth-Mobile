
#define ENA 10
#define IN1A 9
#define IN2A 8
#define ENB 5
#define IN1B 7
#define IN2B 6

L298N motorA(ENA, IN1A, IN2A);
L298N motorB(ENB, IN1B, IN2B);

int time_delay = 500;
int base_speed = 70;

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
  motorA.stop();
  motorB.stop();
  delay(10000);
}

void drive_at_angle(double rad_angle,double sp){
   double mapped_val = (sp/ PI) * rad_angle; 
   set_wheel(motorA, mapped_val);
   set_wheel(motorB, sp - mapped_val);
}

int set_wheel(L298N motor, int sp) {
  if (sp > 0){
    motor.forward();
  } else {
    motor.backward();
  }
  motor.setSpeed(sp);
}
