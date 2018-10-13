
  // put your setup code here, to run once:
int sensorPins[] = {A5,A4,A3,A2}; // select the input pin for the potentiometer
//A5 Front, A4 Back, A3 Left, A2 Right
int ledPin = 13; // select the pin for the LED
int sensorValues[] = {0,0,0,0}; // vasriable to store the value coming from the sensor
double xDirection, yDirection = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  for (int i = 0; i < 4; i ++) {
    sensorValues[i] = 1000 - analogRead(sensorPins[i]);
  }
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
