import pyfirmata
import time
 
board = pyfirmata.Arduino('COM3')

it = pyfirmata.util.Iterator(board)
it.start()

board.digital[2].mode = pyfirmata.INPUT

while True:
   sw = board.digital[10].read()
   if sw is True:
       board.digital[2].write(1)
   else:
       board.digital[2].write(0)
   time.sleep(0.1)
