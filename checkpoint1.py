# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import matplotlib.pyplot as plt
import numpy as np
import gzip
from matplotlib import colors

#load 1st iteration grid state data into a list
text0 = open(r'C:\Users\Shawn\source\repos\Project0c++\Project0c++\state0.txt', "r")
lines0 = text0.read().split(',')

text0.close()
#make a 100x100 array with the data from the list
state0=np.zeros((100,100))
for i in range(100):
    for j in range(100):
        state0[i][j]=lines0[i*100+j]

#repeat previous steps for 501st iteration data
text80 = open(r'C:\Users\Shawn\source\repos\Project0c++\Project0c++\state80.txt', "r")
lines80 = text80.read().split(',')

text80.close()
state80=np.zeros((100,100))
for i in range(100):
    for j in range(100):
        state80[i][j]=lines80[i*100+j]
        
#repeated for 5001st iteration data
text200 = open(r'C:\Users\Shawn\source\repos\Project0c++\Project0c++\state200.txt', "r")
lines200 = text200.read().split(',')

text200.close()
state200=np.zeros((100,100))
for i in range(100):
    for j in range(100):
        state200[i][j]=lines200[i*100+j]
        
        


# this following section of code is based off of https://stackoverflow.com/questions/43971138/python-plotting-colored-grid-based-on-values
#by
cmap = colors.ListedColormap(['w', 'k'])
bounds = [0,0.5,1.5]
norm = colors.BoundaryNorm(bounds, cmap.N)

fig, ax = plt.subplots()
ax.imshow(state0, cmap=cmap, norm=norm)
plt.title('1st iteration grid')
plt.show()

cmap = colors.ListedColormap(['w', 'k'])
bounds = [0,0.5,1.5]
norm = colors.BoundaryNorm(bounds, cmap.N)

fig, ax = plt.subplots()
ax.imshow(state80, cmap=cmap, norm=norm)
plt.title('801st iteration grid')
plt.show()

cmap = colors.ListedColormap(['w', 'k'])
bounds = [0,0.5,1.5]
norm = colors.BoundaryNorm(bounds, cmap.N)

fig, ax = plt.subplots()
ax.imshow(state200, cmap=cmap, norm=norm)
plt.title('2001st iteration grid')
plt.show()




