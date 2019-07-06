import serial #Import Serial Library
from Tkinter import *

path = []
 
arduinoSerialData = serial.Serial('/dev/ttyACM0',9600) #Create Serial port object called arduinoSerialData
master = Tk()
canvas_width = 300
canvas_height = 300
w = Canvas(master,width=canvas_width,height=canvas_height)
w.pack()

while(1)
if (arduinoSerialData.inWaiting()>0):
	myData = arduinoSerialData.readline()
	path.append(myData)
	w.create_line(path,tag="path",width=3,fill="#00b000")
