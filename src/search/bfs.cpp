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


void bft(int n, std::vector<std::vector<int>> adj)
{
    std::vector<bool> visited(n,false);
    std::queue<int> q;
    q.push(0);

    while(!q.empty()){
        int temp = q.front();
        visited[temp] = true;
        for(auto x:adj[temp]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
        std::cout<<temp<<std::endl;
        q.pop();
    }
}


void bfs(int n, std::vector<std::vector<int>> adj, int target)
{
    std::vector<bool> visited(n,false);
    std::queue<int> q;
    q.push(0);
    if(q.back() == target){
        std::cout<<"target is found"<<std::endl;
        return;
    }

    while(!q.empty()){
        int temp = q.front();
        visited[temp] = true;
        for(auto x:adj[temp]){
            if(!visited[x]){
                if(x == target){
                    std::cout<<"target is found"<<std::endl;
                    return;
                }
                q.push(x);
                visited[x] = true;
            }
        }
        //std::cout<<temp<<std::endl;
        q.pop();
    }
    std::cout<<"target is not found"<<std::endl;
}
