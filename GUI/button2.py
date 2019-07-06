import serial
import tkinter as tk
s = serial.Serial('/dev/ttyACM1', 9600)

class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.create_widgets()

    def create_widgets(self):
        self.on = tk.Button(self)
        self.on["text"] = "ON"
        self.on["command"] = self.send_on
        self.on.pack(side="top")
        self.off = tk.Button(self)
        self.off["text"] = "OFF"
        self.off["command"] = self.send_off
        self.off.pack(side="bottom")

    def send_on(self):
        s.write(str.encode('O'))
    def send_off(self):
        s.write(str.encode('F'))

root = tk.Tk()
app = Application(master=root)
app.mainloop()

