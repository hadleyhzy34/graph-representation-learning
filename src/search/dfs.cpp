#include<bits/stdc++.h>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
//void addEdge(vector<int> adj[], int u, int v)
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<vector<int>> adj, int V)
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Adjacency list of vertex "
			<< v << "\n head ";
		for (auto x : adj[v])
		    cout << "-> " << x;
		printf("\n");
	}
}

void dft(int n, std::vector<std::vector<int>> adj, std::vector<bool> &visited, int j)
{
    visited[j] = true;
    std::cout<<j<<std::endl;
    
    for(int i = 0; i < adj[j].size(); i++){
        //std::cout<<"check: "<<adj[j].size()<<std::endl;
        if(!visited[adj[j][i]]){
            //std::cout<<adj[j][i]<<std::endl;
            dft(n, adj, visited, adj[j][i]);
        }
    }
}

void dfs(int n, 
         std::vector<std::vector<int>> adj,
         std::vector<bool> &visited,
         int j,
         int target)
{
    visited[j] = true;
    if(j == target){
        std::cout<<"found target: "<<j<<std::endl;
        return;
    }
    
    for(int i = 0; i < adj[j].size(); i++){
        if(!visited[adj[j][i]]){
            dfs(n, adj, visited, adj[j][i], target);
        }
    }
}
