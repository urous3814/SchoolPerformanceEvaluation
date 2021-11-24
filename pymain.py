import serial
import turtle as tu
import math as m
                        #현재는 이동등의 기능을 배제한 후 제작

arduino_port = input("통신 포트 이름: ")

turtle_size = int(input("터틀 DOT 크기 지정: "))

turtle_dis = int(input("터틀 거리 배율 지정: "))


serialFromArduino = serial.Serial(arduino_port, 9600, timeout=1)
t = tu.Pen()
t.speed(300)

while True:
    line = serialFromArduino.readline().decode("utf-8")
    print(line)
    ang, dis = line.split("_")
    ang = int(ang) - 90
    d = int(dis)
    
#     x = dis*m.cos(ang)
#     if(ang>90 and ang<270):
#       x=x*-1
#     y = dis*m.sin(ang)
  
    if(d>0 and d<60):
      t.left(ang)
      t.penup()
      t.forward(d*turtle_dis)
      t.begin_fill()
      t.circle(turtle_size)
      t.end_fill()
      t.backward(d*turtle_dis)
      t.right(ang)
      
