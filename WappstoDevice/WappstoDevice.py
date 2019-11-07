#!/usr/bin/env python
"""
 Blinks an LED on digital pin 13
 in 1 second intervals
 
 https://pypi.org/project/arduino-python3/
 https://github.com/mkals/Arduino-Python3-Command-API
"""

from Arduino import Arduino
import time

 # plugged in via USB, serial com at rate 115200
board = Arduino(baud = 115200, port = "COM3")
board.pinMode(2, "OUTPUT")

while True:
  board.digitalWrite(2, "LOW")
  time.sleep(0.2)
  board.digitalWrite(2, "HIGH")
  time.sleep(0.2)



print(board.digitalRead(2))

