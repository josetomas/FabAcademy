from Tkinter import *
import serial
NX = 500 
NY = 500
myData = 100
path = []
baseline = 0
baseline_filt = 0.01
gain = 5
data=0
root = Tk()

root.title(':D')
port = "/dev/ttyACM0"
arduinoSerialData = serial.Serial(port,9600)

canvas = Canvas(root, width=NX, height=NY, background='white')
canvas.pack()

if (arduinoSerialData.inWaiting()>0):
	data = arduinoSerialData.readline()
	baseline = baseline_filt*float(data) + (1-baseline_filt)*baseline
      	value = NY/2 + gain*(float(data) - float(baseline))
      	myData.append(i*NY/float(nloop))
      	myData.append(value)



canvas.create_line(myData,tag="value",width=3,fill="#00b000")
#canvas.create_line(myData, 200, 200, 100)
root.after(1,idle,root,canvas)
root.mainloop()

