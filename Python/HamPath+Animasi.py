from time import time
from HamPath import *
nodes=[[0, 0], [2, 2], [2, 0], [1, 2]]
import turtle
import math
x,y=nodes[0],nodes[1]
zoom=int(100/(math.sqrt((y[0]-x[0])**2+(y[1]-x[1])**2)))
updated=[[x[0]*zoom,x[1]*zoom] for x in nodes]
def anima(nodes,con):
    screen = turtle.getscreen()
    t = turtle.Turtle()
    t.speed(0)
    t.pu()
    for a in range(node_count):
        t.goto(updated[a])
        t.dot(10)
        t.write(f"({nodes[a][0]}, {nodes[a][1]})")
    for element in connections:
        t.pu()
        x,y=element[0],element[1]
        t.goto(updated[x])
        t.pd()
        t.goto(updated[y])
    t.color("green")
    t.pensize(3)
    h = all_paths[0]
    t.pu()
    t.goto(updated[int(h[0])])
    t.pd()
    for x in range(1,node_count):
        t.goto(updated[int(h[x])])
anima(nodes,connections)
print("Execution time for animations: ")
print(f"{time()-end} seconds")
