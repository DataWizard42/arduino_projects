/*........................
BTS7960 Motor Driver Test
https://www.instructables.com/member/Mohannad+Rawashdeh/
*/
int RPWM=5;
int LPWM=6;
// timer 0
int L_EN=7;
int R_EN=8;

void setup() {
  // put your setup code here, to run once:
//  for(int i=5;i<9;i++){
//   pinMode(i,OUTPUT);
//  }
//   for(int i=5;i<9;i++){
//   digitalWrite(i,LOW);
//  }
//   delay(1000);
    Serial.begin(9600);
  }



void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("EN High");
  digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
delay(1000);
analogWrite(RPWM,13);
delay(2000);
analogWrite(RPWM,0);
delay(5000);
analogWrite(LPWM,13);
delay(2000);
analogWrite(LPWM,0);
delay(3000);
//for(int i=0;i<155;i++){
//  analogWrite(RPWM,i);
////  analogWrite(LPWM,255-i);
//  delay(100);
//}
//delay(500);
//for(int i=155;i>0;i--){
//  analogWrite(RPWM,i);
//// analogWrite(LPWM,255-i);
//  delay(100);
//}
//delay(500);
}
