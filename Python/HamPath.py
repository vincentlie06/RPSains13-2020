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
    
