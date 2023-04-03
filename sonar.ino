#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
bool isDone = false;

// defines pins numbers
const int trigPin = 6;
const int echoPin = 7;
const int servoPin = 5;
// defines variables
long duration;
int distance;

float calc_distance_average(int samples)
{
  samples = max(0,samples);
  float distance = 0 ;
  for(int i=0;i<samples;i++){
    distance = max(read_distance (), distance);
  }
  return distance;
}

float read_distance()
{
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
 
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return (duration/2) / 29.1; //Distance calculation per cm
}

void setup() {
  myservo.attach(servoPin);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(servoPin, OUTPUT);//Sets the servoPin as Output
  Serial.begin(115200); // Starts the serial communication
}
void loop() {
  distance = calc_distance_average(2);
  Serial.print(distance);
  Serial.print(",");
  Serial.print(pos);
  Serial.print(" ");

  if (pos < 180 && !isDone){
    pos++;
    // in steps of 1 degree
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15); // waits 15ms for the servo to reach the position
  }
  if (pos == 180){
    isDone = true;
  }
  if (isDone){
    pos--;
    // in steps of 1 degree
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15); // waits 15ms for the servo to reach the position
  }
  if (pos == 0){
    isDone = false;
  }
 delay(50);
}
