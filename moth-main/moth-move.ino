
const int ENA = 6;
const int IN1 = 8;
const int IN2 = 7;
const int IN3 = 2;
const int IN4 = 4;
const int ENB = 3;
L298N driver(ENA,IN1,IN2,IN3,IN4,ENB); 
int time_delay = 500;
int base_speed = 300;
int w_left = L298N::MOTOR_A;
int w_right = L298N::MOTOR_B;

void test_driving() {
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
}

void drive_at_angle(double angle, double sp){
//   int right_speed, left_speed;
//   if (rad_angle < (-PI/2)) {
//      left_speed = 0; // MIN TURN SPEED
//   }
//   else if (rad_angle < 0){
//    right_speed = 0;
//   }
//   else{
//   if (rad _angle > (PI/2))
//   rad_angle /= (PI / 2);
//   rad_angle = abs(rad_angle);
//   while (rad_angle > PI / 2) {
//    rad_angle -= PI / 2;
//   }
Serial.print("Angle: ");
   Serial.println(angle);
      if (angle < 0) {
        angle = (M_PI*2) + angle;
      }

      if (angle > 2.987 && angle <= 2*PI/3){
        angle = 2.987;
      } else if (angle < 0.524 || angle > (3*PI)/2){
        angle = 0.524;
      }
   //int real_speed = sp * (angle / (PI / 2));
   
  

   double mapped_val = (sp / PI) * angle; 
   Serial.print("Angle: ");
   Serial.println(angle);
   Serial.print("Mapped val: ");
   Serial.println(mapped_val);
   Serial.print("Speed - Mapped_val: ");
   Serial.println(sp - mapped_val);
   set_wheel(w_right, mapped_val);
   set_wheel(w_left, sp - mapped_val);
}

int set_wheel(int motor, int speed) {
  if (speed > 0){
    driver.setup_motor(motor,HIGH,LOW);
  } else {
    driver.setup_motor(motor,LOW,HIGH);
  }
  driver.drive_motor(motor,speed);
}
