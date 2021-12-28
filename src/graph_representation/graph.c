#include <stdlib.h>
#include <stdio.h>

//adj list node
typedef struct Node
{
    int value;
    struct Node *next;
}Node;

//adj list, vertices as head
typedef struct Adj
{
    struct Node *head;
}Adj;

//graph
typedef struct Graph
{
    int N;
    struct Adj* array;
}Graph;

//create new adj list node
Node * addNewNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

//create a graph of V vertices
Graph* createGraph(int N)
{
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->N = N;
 
    // Create an array of adjacency lists.  Size of array will be N
    graph->array = (Adj*) malloc(N * sizeof(Adj));
 
    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < N; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}

// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest)
{
	// Add an edge from src to dest. A new node is
	// added to the adjacency list of src. The node
	// is added at the beginning
    Node* temp = NULL;
    Node* newNode = addNewNode(dest);

    if(graph->array[src].head == NULL)
    {
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;
    }
    else
    {
        temp = graph->array[src].head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        //graph->array[src].head = newNode;
        temp->next = newNode;
    }
    
    newNode = addNewNode(src);

    if(graph->array[dest].head == NULL)
    {
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
    }
    else
    {
        temp = graph->array[dest].head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        //graph->array[src].head = newNode;
        temp->next = newNode;
    }
}

// representation of graph
void printGraph(Graph* graph)
{
	int v;
	for (v = 0; v < graph->N; ++v)
	{
		Node* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %d", pCrawl->value);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}
