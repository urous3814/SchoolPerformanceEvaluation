#include <SoftwareSerial.h>
int blueTx=0;   //Tx (보내는핀 설정)
int blueRx=1;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
}                                                       //블루투스에 문제가 있음

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available())                     // BTSerial에 입력이 되면
      Serial.write(BTSerial.read());           // BTSerial에 입력된 값을 시리얼 모니터에 출력
    if(Serial.available())                     // 시리얼 모니터에 입력이 되면
      BTSerial.write(Serial.read());           // 그 값을 BTSerial에 출력
}
