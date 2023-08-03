import serial
import time

with serial.Serial(
    "/dev/cu.usbserial-AI03K384",
    baudrate=115200,
    timeout=1.0,
) as actuator:
    print("enter speed in [0, 255]")
    while True:
        speed = int(input())
        actuator.write(bytes([speed]))
        actuator.flush()
        print(f"{speed=}")
