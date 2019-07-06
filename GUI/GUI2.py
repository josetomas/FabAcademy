from Tkinter import *
import serial

def idle(parent,canvas):
   global path, baseline
   #
   # idle routine
   #
   # look for framing
   #
   byte2 = 0
   byte3 = 0
   byte4 = 0
   while 1:
      byte1 = byte2
      byte2 = byte3
      byte3 = byte4
      byte4 = ord(ser.read())
      if ((byte1 == 1) & (byte2 == 2) & (byte3 == 3) & (byte4 == 4)):
         break
   path = []
   for i in range(nloop):
      lo = ord(ser.read())
      hi = ord(ser.read())
      reading = 256*hi + lo
      baseline = baseline_filt*reading + (1-baseline_filt)*baseline
      value = NY/2 + gain*(reading - baseline)
      path.append(i*NY/float(nloop))
      path.append(value)
   canvas.delete("path")
   canvas.create_line(path,tag="path",width=3,fill="#00b000")
   parent.after_idle(idle,parent,canvas)
