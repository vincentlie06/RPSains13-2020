from time import time
start=time()
connections=[[0, 1], [1, 2], [1, 3], [2, 3]]
node_count = 4
def buildGraph(connections, node_count):
    graph = {i : [] for i in range(node_count)}
    for x, y in connections:
        graph[x].append(y)
        graph[y].append(x)
    return graph
def search(node, graph, path = [], visited = dict()):
    if path == []: path = [node]
    if visited == dict():
        visited = {n : False for n in graph}
        visited[node] = True
    for v in graph[node]:
        if not visited[v]:
            visited[v] = True
            path.append(v)
            search(v, graph, path, visited)
            del path[-1]
            visited[v] = False
    if len(path) == len(graph):
        all_paths.append(path.copy())
graph = buildGraph(connections, node_count)
all_paths = []
for node in range(node_count):
    search(node, graph)
for path in all_paths:
    print(f"{path = }")
end=time()
print("Execution time for finding paths: ")
print(f"{end-start} seconds")
