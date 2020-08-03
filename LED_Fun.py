#!/usr/bin/env python
import serial ## need pip
import time

class Strip:
    def __init__(self, arduino_port, baudrate,num):
        # arduino_port : port for the Arduino Board
        # baudrate : baud rate
        # num : the number of LED units
        ser = serial.Serial(arduino_port, baudrate)
        if ser.isOpen():
            self.serial=ser
            self.num=num
            a=self.serial.readline()
            self.read=a.decode("utf-8")
            print(self.read)
        else :
            print('serial port is not open.')

    def setPixelColor(self,i,r,g,b):
        ## i : the serial number for a LED unit, starting from No.0
        ## r : the intensity of red light
        ## g : the intensity of green light
        ## b : the intensity of blue light

        i_bytes = bytes(str(i), 'utf-8')
        self.serial.write(b'i'+i_bytes)
        r_bytes = bytes(str(r), 'utf-8') 
        self.serial.write(b'r'+r_bytes)
        g_bytes = bytes(str(g), 'utf-8') 
        self.serial.write(b'g'+g_bytes)
        b_bytes = bytes(str(b), 'utf-8') 
        self.serial.write(b'b'+b_bytes+b'\n')
        return 0

    def delay(self,delay_time):
        # time : minisecond (10^-3)
        time.sleep(delay_time*0.001)
        return 0

    def show(self):
        show_bytes = bytes(str("show"), 'utf-8') 
        self.serial.write(b'show\n')
        return 0

    def clear(self) :
        num=self.num
        for i in range(num) : 
            self.setPixelColor(i,0,0,0 )
        self.show()

    def close(self):
        self.serial.close()
        return 0


    def breath(self):
        max_valx_val=180
        v=0
        num=self.num
        slope=6
        wait=10
        self.clear()

        while v<max_valx_val :
            for i in range(num):
                self.setPixelColor(i,v,v,v )
            self.show()
            self.delay(wait)
            v=v+slope

        while v>0 :
            v=v-slope
            for i in range(num):
                self.setPixelColor(i,v,v,v )
            self.show()
            self.delay(wait)
        return 0

    def forward(self,number=5):    
        # number : the number of lighting LED units
        max_val=180
        num=self.num
        wait=50
        gap=int(max_val/number)
        mid=int((number/2)+1)
        self.clear()
        t=int(1-mid)
        while t<num+mid :
            for i in range(int(1+(number/2))):
                self.setPixelColor((t+i), 0,(max_val-i*gap),(max_val-i*gap) )
                self.setPixelColor((t-i), 0,(max_val-i*gap),(max_val-i*gap ))
            self.setPixelColor( t-int(1+(number/2)), 0,0,0)
            self.show()
            self.delay(wait)
            t=t+1
        return 0


    def backward(self,number=5): 
        # number : the number of lighting LED units
        max_val=180
        num=self.num
        number=5
        wait=50
        gap=int(max_val/number)
        mid=int((number/2)+1)
        self.clear()
        t=int(num+mid-1)
        while t>(0-mid) :
            for i in range(int(1+(number/2))):
                self.setPixelColor((t+i), (max_val-i*gap),(max_val-i*gap),0 )
                self.setPixelColor((t-i), (max_val-i*gap),(max_val-i*gap),0)
            self.setPixelColor(t+(1+(number/2)), 0,0,0)
            self.show()
            self.delay(wait)
            t=t-1
        self.setPixelColor(0, 0,0,0)
        self.show()
        self.delay(wait)
        return 0
    
    def blink(self):
        wait=200
        num=self.num
        times=5
        self.clear()
        for t in range(times):
            for i in range(num):
                    self.setPixelColor(i,50,0,50 )
            self.show()
            self.delay(wait)
            self.clear()
            self.delay(wait)
        return 0



def demo(port_arduino,baudrate,num):
    s=Strip(port_arduino,baudrate,num)
    s.clear()
    print("clear")
    s.delay(1000)
    s.setPixelColor(1,180,0,0)
    print("No.1 unit is red")
    s.show()
    s.delay(1000)
    s.setPixelColor(2,0,180,0)
    print("No.2 unit is green")
    s.show()
    s.delay(1000)
    s.setPixelColor(3,0,0,180)
    print("No.3 unit is blue")
    s.show()
    s.delay(1000)
    s.clear()
    print("clear")
    s.delay(1000)
    print("blink")
    s.blink()
    print("move from the end to the start")
    s.backward()
    s.delay(1000)
    print("move from the start to the end")
    s.forward()
    s.delay(1000)
    print("breath")
    s.breath()
    s.clear()
    s.close()
    print("close port")




if __name__ == '__main__':

    port='/dev/ttyUSB0' ## port for the Arduino Board
    rate=115200 ## baud rate
    num=30 ## the number of LED units
    demo(port,rate,num)





