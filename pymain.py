import serial   #pyserial, 파이썬에서의 시리얼 통신에 이용되는 라이브러리
import turtle as tu #turtle, 파이썬의 대표적인 기초 그래픽 모델
while True:         #시리얼 통신 연결
    arduino_port = input("통신 포트 이름: ")
    try:
        serialFromArduino = serial.Serial(arduino_port, 9600, timeout=None)  #설정한 통신 포트로 시리얼 통신 형성
    except:
        continue
    else: 
        break
        

turtle_size = int(input("터틀 DOT 크기 지정: "))
turtle_dis = int(input("터틀 거리 배율 지정: "))
t = tu.Pen()    #터틀의 펜 선언
t.speed(300)    #펜의 속도 설정

while True:
    if serialFromArduino.in_waiting == 0 : #캐시에 받은 바이트 수
        pass
    line = serialFromArduino.readline().decode("utf-8") #문자열을 받아와 utf-8로 디코딩
    print(line)
    ang, dis = line.split("_")          #line = 각도_거리
    ang = int(ang)  #각도
    d = int(dis)    #거리
  
    if(d>0 and d<60):
      t.left(ang)
      t.penup()
      t.forward(d*turtle_dis)
      t.begin_fill()
      t.circle(turtle_size)
      t.end_fill()
      t.backward(d*turtle_dis)
      t.right(ang)
