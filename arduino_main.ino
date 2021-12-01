#include <SoftwareSerial.h>  //디지털 핀을 시리얼 통신 포트로 사용 가능하게 해주는 라이브러리
#include <Stepper.h> //스텝 모터의 편리한 사용을 위한 라이브러리
#define blueTx 2   //Tx (시리얼 통신 보내는핀 설정)  매크로 기능
#define blueRx 3   //Rx (시리얼 통신 받는핀 설정)
#define TRIG 10
#define ECHO 8
#define stepsPerRevolution = 57;  //스텝모터 작동 단위 지정(2048이 360도)
SoftwareSerial BTSerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);  //스텝모터 사용을 위한 객체선언
int ang = 0, dis = 0;             //각도와 거리를 나타내는 정수형 변수를 선언

void setup() {
  // put your setup code here, to run once:
  BTSerial.begin(9600);     //블루투스 시리얼의 보더레이트를 9600으로 설정
  pinMode(TRIG, OUTPUT);    //초음파센서의 TRIG 핀을 출력으로 설정    
  pinMode(ECHO, INPUT);     //초음파센서의 ECHO 핀을 입력으로 설정
  myStepper.setSpeed(100);  //RPM, 1분당 회전 수를 설정한다.
}

int pulse() {   //초음파센서 함수, 정수형 값을 return한다
  long duration, distance;     //int형 변수에 비해 범위가 넓은 long형 변수 선언
  digitalWrite(TRIG, LOW);      
  delayMicroseconds(2);     //백만분의 2초동안 delay
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);    //10μs
  digitalWrite(TRIG, LOW);
  duration = pulseIn (ECHO, HIGH);  //ECHO출력의 펄스 길이를 받아온다
  distance = duration * 17 / 1000;  //1cm 왕복에 걸리는 시간: 2*0.01/340=58.8μs
  return (distance);        //거리를 반환
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available())    // 시리얼 버퍼에 있는 데이터의 길이를 바이트 단위로 불러옴
  {
    for (ang = 0; ang < 360; ang += 10)
    {
        myStepper.step(stepsPerRevolution);    //10도 회전
        dis = pulse();      //거리값 받아옴
        String data = (String(ang) + "_" + String(dis));    //전송할 데이터
        BTSerial.println(data);
    }
    myStepper.step(-2048);
    delay(1000);
  }
}
