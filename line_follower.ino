// Line follower code using Smartelex RLS-06 6 IR line sensors and an Arduino board

// Define the pins for the line sensors
int sensor1Pin = A0;
int sensor2Pin = A1;
int sensor3Pin = A2;
int sensor4Pin = A3;
int sensor5Pin = A4;
int sensor6Pin = A5;

// Define the pins for the left and right motors
int leftMotorPin1 = 8;
int leftMotorPin2 = 9;
int rightMotorPin1 = 10;
int rightMotorPin2 = 11;

// Define the threshold value for detecting the line
int threshold = 500;

void setup() {
  // Set the line sensor pins as inputs
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(sensor3Pin, INPUT);
  pinMode(sensor4Pin, INPUT);
  pinMode(sensor5Pin, INPUT);
  pinMode(sensor6Pin, INPUT);
  
  // Set the motor pins as outputs
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the sensor values
  int sensor1Value = analogRead(sensor1Pin);
  int sensor2Value = analogRead(sensor2Pin);
  int sensor3Value = analogRead(sensor3Pin);
  int sensor4Value = analogRead(sensor4Pin);
  int sensor5Value = analogRead(sensor5Pin);
  int sensor6Value = analogRead(sensor6Pin);
  Serial.print(sensor1Value);
  Serial.print(sensor2Value);
  Serial.print(sensor3Value);
  Serial.print(sensor4Value);
  Serial.print("\n");
  delay(2000);
  // Determine the line position based on the sensor values
  int position = 0;
  if (sensor1Value > threshold) position -= 3;
  if (sensor2Value > threshold) position -= 2;
  if (sensor3Value > threshold) position -= 1;
  if (sensor4Value > threshold) position += 1;
  if (sensor5Value > threshold) position += 2;
  if (sensor6Value > threshold) position += 3;

  // Adjust the motor speed based on the line position
  if (position < 0) {
    // Turn left
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else if (position > 0) {
    // Turn right
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else {
    // Move forward
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  }
}
