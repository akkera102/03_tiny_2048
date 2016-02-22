import serial, time

ser = serial.Serial(port=2, baudrate=1200)
ser.close()
time.sleep(2)
