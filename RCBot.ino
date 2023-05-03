/**
 * @Author : vaibhav
 * @Date   : 26/Feb/2023
 * @Title  : RC Car
 * @Pin Connections :
 * Bluetooth Module --> Arduino Board
 * TX   --   RX
 * RX   --   TX
 * VCC  --   3.3V/5V
 * GND  --   GND
 * L2938 --> Arduino Board
 * IN1  --   D2
 * IN2  --   D3
 * IN3  --   D4
 * IN4  --   D5
 * @Warning : 
 * 1. If the wheels can't rotate freely the motor driver will get get heated
 * 2. Do the wiring connection properly
 * @Commands : 
 * 'F' -> Front
 * 'B' -> Back
 * 'L' -> Left
 * 'R' -> Right
 * 'S' -> Stop
 * @Supported Board: Arduino UNO/Maga/Nano/Mini/Pro-Mini... etc, ESP8266-12, ESP32
 */

int motorPins[4] = {2,3,4,5}; // IN1,IN2,IN3,IN4
char data;  // BLT. Data will be stored here

// Locomotion of the rover
void botStop(){
  digitalWrite(motorPins[0],LOW);
  digitalWrite(motorPins[1],LOW);
  digitalWrite(motorPins[2],LOW);
  digitalWrite(motorPins[3],LOW);
}
void botFront(){
  digitalWrite(motorPins[0],HIGH);
  digitalWrite(motorPins[1],LOW);
  digitalWrite(motorPins[2],HIGH);
  digitalWrite(motorPins[3],LOW);
}
void botBack(){
  digitalWrite(motorPins[0],LOW);
  digitalWrite(motorPins[1],HIGH);
  digitalWrite(motorPins[2],LOW);
  digitalWrite(motorPins[3],HIGH);
}
void botLeft(){
  digitalWrite(motorPins[0],LOW);
  digitalWrite(motorPins[1],HIGH);
  digitalWrite(motorPins[2],HIGH);
  digitalWrite(motorPins[3],LOW);
}
void botRight(){
  digitalWrite(motorPins[0],HIGH);
  digitalWrite(motorPins[1],LOW);
  digitalWrite(motorPins[2],LOW);
  digitalWrite(motorPins[3],HIGH);
}

void setup(){
  // Establish Serial Communication
  Serial.begin(9600);
  // Setup the pin for output
  for(int i = 0; i<4; i++){
    pinMode(motorPins[i],OUTPUT);
  }
  // Setup the pins to 0 at beginning
  for(int i = 0; i<4; i++){
    digitalWrite(motorPins[i],LOW);
  }
}

void loop(){
  // Check is serial communication is available or not
  if(Serial.available()){
    // If it is available then check the commands reciving 
    data = Serial.read();
    Serial.println(data);
    if(data == 'F'){botFront();}
    else if(data == 'B'){botBack();}
    else if(data == 'S'){botStop();}
    else if(data == 'L'){botLeft();}
    else if(data == 'R'){botRight();}
    else{Serial.println("Invalid Input");}
  }
}
