import serial
import turtle as tu


#arduino_port = input("통신 포트 이름: ")

#serialFromArduino = serial.Serial(arduino_port, 9600, timeout=1)
t = tu.Pen()
t.speed(300)

while True:
    #line = serialFromArduino.readline().decode("utf-8")
    # print(line)
    # d = int(line)
    d = 30
    if(d>0 and d<60):
        t.penup()
        t.forward(d*15)
        t.begin_fill()
        t.circle(15)
        t.end_fill()
        t.backward(d*15)
        t.left(5)
