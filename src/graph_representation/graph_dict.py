# Python3 program to represent adjacency
# list using dictionary
class graph:
    def __init__(self, v):
        self.N = v
        self.graph = dict()

    def addEdge(self, src, dest):
        if src not in self.graph:
            self.graph[src] = {dest}
        else:
            self.graph[src].add(dest)

        if dest not in self.graph:
            self.graph[dest] = {src}
        else:
            self.graph[dest].add(src)


    def print(self):
        for i, adjlist in sorted(self.graph.items()):
            print(f"Adjacency list of vertex {i}")
            for j in sorted(adjlist, reverse = True):
                print(j, end = " ")
                print('\n')
	
    # Search for a given edge in graph
    def searchEdge(self,source,destination):
        if source in self.graph:
            if destination in self.graph[source]:
                print("Source vertex {} is present in graph.\n".format(source))
                return
        print(f'source vertex {source} is not present in graph')
		
# Driver code
if __name__=="__main__":
	g = graph(5)
	
	g.addEdge(0, 1)
	g.addEdge(0, 4)
	g.addEdge(1, 2)
	g.addEdge(1, 3)
	g.addEdge(1, 4)
	g.addEdge(2, 3)
	g.addEdge(3, 4)

	# Print adjacenecy list
	# representation of graph
	g.print()

	# Search the given edge in a graph
	g.searchEdge(2, 1)
	g.searchEdge(0, 3)
