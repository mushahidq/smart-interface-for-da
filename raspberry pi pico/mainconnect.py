import uos
import machine
import utime

print(uos.uname())
uart0 = machine.UART(0,baudrate=38400)  #at-command

def sendCMD_waitResp(cmd, uart=uart0, timeout=2000):
    print("CMD: " + cmd)
    uart.write(cmd)
    waitResp(uart, timeout)
    print()

def waitResp(uart=uart0, timeout=2000):
    prvMills = utime.ticks_ms()
    resp = b""
    while (utime.ticks_ms()-prvMills)<timeout:
        if uart.any():
            resp = b"".join([resp, uart.read(1)])
    print(resp)

print("- uart0 -")
waitResp()
sendCMD_waitResp("AT\r\n")
sendCMD_waitResp("AT+ORGL\r\n")           #Restore default setting
sendCMD_waitResp("AT+VERSION\r\n")
sendCMD_waitResp("AT+UART?\r\n")
sendCMD_waitResp("AT+UART=9600,0,0\r\n")  #9600 baud, 1 stop, parity=none
sendCMD_waitResp("AT+UART?\r\n")
sendCMD_waitResp("AT+PSWD?\r\n")
sendCMD_waitResp("AT+PSWD=4321\r\n")      #Set PIN = "4321"
sendCMD_waitResp("AT+PSWD?\r\n")
sendCMD_waitResp("AT+ROLE?\r\n")
sendCMD_waitResp("AT+ROLE=1\r\n")         #Master
sendCMD_waitResp("AT+ROLE?\r\n")
sendCMD_waitResp("AT+CMODE?\r\n")
sendCMD_waitResp("AT+CMODE=1\r\n")        #connect any address
sendCMD_waitResp("AT+CMODE?\r\n")

sendCMD_waitResp("AT+ADDR?\r\n")


print("Done")