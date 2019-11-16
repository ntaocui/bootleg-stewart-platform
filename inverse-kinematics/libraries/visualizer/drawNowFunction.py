import random
import time
import serial
import numpy as np


from matplotlib import pyplot as plt
from matplotlib import animation
from mpl_toolkits.mplot3d import Axes3D

radii= []
theta1s=[]
theta2s=[]
arduinoData = serial.Serial('com4', 115200)
plt.ion()
cnt = 0

#Create a function that makes our desired plot
def makeFig():  
    plt.ylim(80,90)                                 #Set y min and max values
    plt.title('My Live Streaming Sensor Data')      #Plot the title
    plt.grid(True)                                  #Turn the grid on
    plt.ylabel('Temp F')                            #Set ylabels
    plt.plot(tempF, 'ro-', label='Degrees F')       #plot the temperature
    plt.legend(loc='upper left')                    #plot the legend
    plt2=plt.twinx()                                #Create a second y axis
    plt.ylim(93450,93525)                           #Set limits of second y axis- adjust to readings you are getting
    plt2.plot(pressure, 'b^-', label='Pressure (Pa)') #plot pressure data
    plt2.set_ylabel('Pressrue (Pa)')                    #label second y axis
    plt2.ticklabel_format(useOffset=False)           #Force matplotlib to NOT autoscale y axis
    plt2.legend(loc='upper right')                  #plot the legend

while True:
    while(arduinoData.inWaiting() == 0):   #Wait here until there is data
        pass
    arduinoString = arduinoData.readline() #read the line of text from the serial port
    dataArray = arduinoString.split(',')   #Split it into an array called dataArray
    radius = float( dataArray[0] )         #Convert first element to floating number and put in radius
    theta1 = float( dataArray[1] )         #Convert second element to floating number and put in theta1
    theta2 = float( dataArray[2] )         #Convert third element to floating number and put in theta2
    radii.append(radius)                   #Build our radii array by appending radii readings
    theta1s.append(theta1)                 #Building our theta1s array by appending theta1 readings
    theta2s.append(theta2)                 #Building the theta2s array by appending theta2 readings
    drawnow(makeFig)                       #Call drawnow to update our live graph
    plt.pause(.000001)                     #Pause Briefly. Important to keep drawnow from crashing
    cnt+=1
    if(cnt>50):                            #If you have 50 or more points, delete the first one from the array
        radii.pop(0)                       #This allows us to just see the last 50 data points
        theta1s.pop(0)
        theta2s.pop(0)


