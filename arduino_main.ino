#include <SoftwareSerial.h>
#include <Servo.h> 
#define blueTx 0   //Tx (보내는핀 설정)
#define blueRx 1   //Rx (받는핀 설정)
#define TRIG 10
#define ECHO 8
int servoPin=9;
SoftwareSerial BTSerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
Servo servo; 
int ang = 0, dis = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //시리얼모니터
  BTSerial.begin(9600); //블루투스 시리얼
  servo.attach(servoPin); 
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}                                                       //블루투스에 문제가 있음

int pulse(){
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn (ECHO, HIGH);
  distance = duration * 17 / 1000; 
  return(distance);
}

void loop() {
  // put your main code here, to run repeatedly:

   if(BTSerial.available())                     // BTSerial에 입력이 되면
      for(ang; ang>360; ang)
      {
        servo.write(ang);
        dis = pulse();
        BTSerial.write(ang+"#"+dis);       
        delay(300); 
      }
}
