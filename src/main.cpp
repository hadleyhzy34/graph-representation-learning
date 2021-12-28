// A simple representation of graph using STL
#include<bits/stdc++.h>
//#include "graph_representation/graph.cpp"
//#include "graph_representation/graph.c"
//#include "search/dfs.cpp"
#include "search/bfs.cpp"
using namespace std;

// Driver code
int main()
{
	int V = 5;
	//vector<int> adj[];
    //must declare size of adj
    vector<vector<int>> graph(V);
    //Graph *graph = createGraph(V);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	printGraph(graph, V);
    //printGraph(graph);
    vector<bool> visited(V,false);
    //dft(V,graph,visited,0);
    //dfs(V,graph,visited,0,5);
    bft(V, graph); 

    bfs(V, graph, 3);
    bfs(V, graph, 5);
	return 0;
}

