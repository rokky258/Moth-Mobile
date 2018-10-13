
  // put your setup code here, to run once:
int sensorPins = {A5,A4,A3,A2}; // select the input pin for the potentiometer
//A5 Front, A4 Back, A3 Left, A2 Right
int ledPin = 13; // select the pin for the LED
int sensorValues = {0,0,0,0}; // vasriable to store the value coming from the sensor
int xDirection, yDirection = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  for (int i = 0; i < 4; i ++) {
    sensorValue[i] = analogRead(sensorPins[i]);
  }
  sensorValue = analogRead(sensorPin);
  delay(20);
  Serial.println(sensorValue, DEC);
}

int calculateDirection(){
  yDirection = sensorValues[0] - sensorValues[1];
  xDirection = sensorValues[2] - sensorValues[3];
  
}
