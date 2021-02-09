from time import time
start=time()
nodes=[[0, 0], [2, 2], [2, 0], [1, 2]]
connections=[[0, 1], [1, 2], [1, 3], [2, 3]]
node_count=len(nodes)
def find(node):
    arr=[]
    for x in connections:
        if x[0]==node: arr.append(x)
        elif x[1]==node: arr.append([node,x[0]])
    return arr
def search(node,arr):
    for a in range(len(con[node])):
        x=con[node][a][1]
        if x not in arr:
            arr.append(x)
            search(x,arr)
            del arr[-1]
    if len(arr)==node_count:
        ham_paths.append(str(arr))
        print("ham paths:",arr)
con=[find(x) for x in range(node_count)]
def ham(node):
    arr=[]
    arr.append(node)
    search(node,arr)
ham_paths=[]
for x in range(node_count):
    ham(x)
end=time()
print("Execution time for finding hamiltonian paths: ")
print(str(end-start)+" seconds")
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
        t.write(("("+str(nodes[a][0])+" ,"+str(nodes[a][1])+")")) 
    for element in connections:
        t.pu()
        x,y=element[0],element[1]
        t.goto(updated[x])
        t.pd()
        t.goto(updated[y])
    t.color("green")
    t.pensize(3)
    h=list(ham_paths[0])
    del h[0]
    del h[-1]
    h="".join(h)
    h=h.split(", ")
    t.pu()
    t.goto(updated[int(h[0])])
    t.pd()
    for x in range(1,node_count):
        t.goto(updated[int(h[x])])
anima(nodes,connections)
print("Execution time for animations: ")
print(str(time()-end)+" seconds")
