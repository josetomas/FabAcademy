#
# hello.mag.45.py
#
# receive and display magnetic field 
#    hello.mag.45.py serial_port
#
# Neil Gershenfeld 11/3/13
# (c) Massachusetts Institute of Technology 2013
#
# This work may be reproduced, modified, distributed,
# performed, and displayed for any purpose. Copyright is
# retained and must be preserved. The work is provided
# as is; no warranty is provided, and users accept all 
# liability.
#

from Tkinter import *
import serial

WINDOW = 600 # window size
nsamples = 100.0 # number of samples accumulated

def idle(parent,canvas):
   global filter, eps
   #
   # idle routine
   #
   byte2 = 0
   byte3 = 0
   byte4 = 0
   ser.flush()
   while 1:
      #
      # find framing 
      #
      byte1 = byte2
      byte2 = byte3
      byte3 = byte4
      byte4 = ord(ser.read())
      if ((byte1 == 1) & (byte2 == 2) & (byte3 == 3) & (byte4 == 4)):
         break
   lo = ord(ser.read())
   hi = ord(ser.read())
   value = 256*hi + lo
   canvas.itemconfigure("text",text="%.1f"%value)
   parent.after_idle(idle,parent,canvas)

#
#  check command line arguments
#
if (len(sys.argv) != 2):
   print "command line: hello.mag.45.py serial_port"
   sys.exit()
port = sys.argv[1]
#
# open serial port
#
ser = serial.Serial(port,9600)
ser.setDTR()
#
# set up GUI
#
root = Tk()
root.title('hello.mag.45.py (q to exit)')
root.bind('q','exit')
canvas = Canvas(root, width=WINDOW, height=.25*WINDOW, background='white')
canvas.create_text(.1*WINDOW,.125*WINDOW,text=".33",font=("Helvetica", 24),tags="text",fill="#0000b0")
canvas.pack()
#
# start idle loop
#
root.after(100,idle,root,canvas)
root.mainloop()