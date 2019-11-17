#https://stackoverflow.com/questions/34376656/matplotlib-create-real-time-animated-graph

#With Serial Input
#http://www.toptechboy.com/tutorial/python-with-arduino-lesson-11-plotting-and-graphing-live-data-from-arduino-with-matplotlib/

#Add 3d surface plot to 3d scatter
# https://stackoverflow.com/questions/17367558/plot-a-3d-surface-from-x-y-z-scatter-data-in-python

import random
import time
import serial
import numpy as np


from matplotlib import pyplot as plt
from matplotlib import animation
from mpl_toolkits.mplot3d import Axes3D



def update_lines(num):
    dx, dy, dz = np.random.random((3,)) * 255 * 2 - 255  # replace this line with code to get data from serial line
    text.set_text("{:d}: [{:.0f},{:.0f},{:.0f}]".format(num, dx, dy, dz))  # for debugging
    x.append(dx)
    y.append(dy)
    z.append(dz)
    graph._offsets3d = (x, y, z)
    return graph,


x = [0]
y = [0]
z = [0]

fig = plt.figure(figsize=(5, 5))
ax = fig.add_subplot(111, projection="3d")
graph = ax.scatter(x, y, z, color='orange')
text = fig.text(0, 1, "TEXT", va='top')  # for debugging

ax.set_xlim3d(-255, 255)
ax.set_ylim3d(-255, 255)
ax.set_zlim3d(-255, 255)

# Creating the Animation object
ani = animation.FuncAnimation(fig, update_lines, frames=100, interval=50, repeat=False, blit=False)


ax.plot_surface(X, Y, Z)
plt.show()