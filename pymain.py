import serial
import turtle as tu
import math as m
                        #현재는 이동등의 기능을 배제한 후 제작

arduino_port = input("통신 포트 이름: ")

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
      t.forward(d*15)
      t.begin_fill()
      t.circle(15)
      t.end_fill()
      t.backward(d*15)
      t.right(ang)
      
