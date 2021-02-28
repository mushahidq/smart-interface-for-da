import uos
import machine
import utime
from machine import Pin

rel1 - Pin(3, Pin.OUT)
rel3 - Pin(4, Pin.OUT)
rel3 - Pin(5, Pin.OUT)
rel4 - Pin(6, Pin.OUT)

uart0 = machine.UART(0,baudrate=9600)

def clartBuf(uart=uart0):
    print("Clear UART buffer "+ str(uart))
    while uart.any():
        print(uart.read(1))

clartBuf()

prvMills = utime.ticks_ms()
bUart0 = b''
while (1):
    if uart0.any():
        b0 = uart0.read(1)
        bUart0 = bUart0 + b0
        if b0.decode('utf-8') == 'A':
            rel1.toggle()
        if b0.decode('utf-8') == 'B':
            rel2.toggle()
        if b0.decode('utf-8') == 'C':
            rel3.toggle()
        if b0.decode('utf-8') == 'D':
            rel4.toggle()
