#include <SoftwareSerial.h>
#include <Servo.h> 
#define blueTx 0   //Tx (보내는핀 설정)
#define blueRx 1   //Rx (받는핀 설정)
#define TRIG 10
#define ECHO 8
#define servoPin 9
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
}                                                       

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

//   if(BTSerial.available())                     // BTSerial에 입력이 되면
      for(ang = 0; ang<360; ang+=5)
      {
        servo.write(ang);
        dis = pulse();
        String data = (String(ang)+"_"+String(dis));
        BTSerial.println(data);       
        Serial.println(data);
        delay(100); 
      }
  delay(1000);
}
