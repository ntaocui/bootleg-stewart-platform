#https://stackoverflow.com/questions/34376656/matplotlib-create-real-time-animated-graph

#With Serial Input
# http://www.toptechboy.com/tutorial/python-with-arduino-lesson-11-plotting-and-graphing-live-data-from-arduino-with-matplotlib/

#Add 3d surface plot to 3d scatter
# https://stackoverflow.com/questions/17367558/plot-a-3d-surface-from-x-y-z-scatter-data-in-python

#clear plot or keep last x points
# https://stackoverflow.com/questions/47192614/matplotlib-funcanimation-clear-plot-each-repeat-cycle

import math
import random
import sys
import serial
import time
import numpy as np

from matplotlib import pyplot as plt
from matplotlib import animation
from mpl_toolkits.mplot3d import Axes3D

COM_PORT = "COM9"
BAUD_RATE = 115200
NUM_DATA_PTS = 100

def polar2cart(r, theta, phi):
    return [
         int(r * math.sin(theta) * math.cos(phi)),
         int(r * math.sin(theta) * math.sin(phi)),
         int(r * math.cos(theta))
    ]

def restart():
    result = input("Do you want to restart animation?")
    if result == "y" or result == "yes":
        ani.frame_seq = ani.new_frame_seq() 
        ani.event_source.start()
    else:
        plt.close()


def update_lines(num):
    while not ser.in_waiting:
        pass
    serial_input = ser.readline()
    uni_str = serial_input.decode('utf-8')
    if len(uni_str.split(' ')) <3 : 
        print('WRONG')
        uni_str = '0 0 0'
    pitch, heading, r = uni_str.split(' ')
    # print(pitch, heading, r)
    pitch, heading, r = (math.pi / 2) - float( pitch), float(heading), float(r)
    px, py, pz = polar2cart(r, pitch, heading)
    text.set_text("{:d}: [{:.0f},{:.0f},{:.0f}]".format(num, px, py, pz))  # for debugging
    x.append(px)
    y.append(py)
    z.append(pz)
    graph._offsets3d = (x, y, z)

    if num == NUM_DATA_PTS - 1:
        restart()
    return graph,


ser = serial.Serial(COM_PORT,BAUD_RATE,timeout=5)
ser.reset_input_buffer()
ser.reset_output_buffer()
time.sleep(5)

x = [0]
y = [0]
z = [0]

fig = plt.figure(figsize=(5, 5))
ax = fig.add_subplot(111, projection="3d")
graph = ax.scatter(x, y, z, color='orange')
text = fig.text(0, 1, "TEXT", va='top')  # for debugging

ax.set_xlim3d(-10, 100)
ax.set_ylim3d(-100, 100)
ax.set_zlim3d(-50, 50)

# Creating the Animation object
ani = animation.FuncAnimation(fig, update_lines, frames=NUM_DATA_PTS, interval=50, repeat=False, blit=False)

# Attempt to fit surface plot to data...
# ax.plot_surface(X, Y, Z)

plt.show()