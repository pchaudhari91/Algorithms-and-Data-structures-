#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include<conio.h>
#include "MINPRIOR.H"
#define Vertices 100
using namespace std;

//const int V = 9;
// A structure to represent a node in adjacency list
struct AdjListNode
{
    int Destination;
    int weight;
    struct AdjListNode* next;
};

// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};


class MSTApp
{
	public:
		// A utility function to create a new adjacency list node
		struct AdjListNode* newAdjListNode(char Destination, int weight)
		{
			struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
			newNode->Destination = Destination;
			newNode->weight = weight;
			newNode->next = NULL;
			return newNode;
		}

		// A utility function that creates a graph of V vertices
		struct Graph* createGraph(int V)
		{
			struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
			graph->V = V;

			// Create an array of adjacency lists.  Size of array will be V
			graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

			// Initialize each adjacency list as empty by making head as NULL
			for (int i = 0; i < V; ++i)
			{
				graph->array[i].head = NULL;
			}

			return graph;
		}

		// Adds an edge to an undirected graph
		void addEdge(struct Graph* graph, int Source, int Destination, int weight)
		{
			// Add an edge from Source to Destination.  A new node is added to the adjacency
			// list of Source.  The node is added at the begining
			struct AdjListNode* newNode = newAdjListNode(Destination, weight);
			newNode->next = graph->array[Source].head;
			graph->array[Source].head = newNode;

			// Since graph is undirected, add an edge from Destination to Source also
			newNode = newAdjListNode(Source, weight);
			newNode->next = graph->array[Destination].head;
			graph->array[Destination].head = newNode;
		}
		// A utility function used to print the constructed MST
		void printMinimumSpanningTree(int arr[], int n)
		{
			cout<<"----------------------- Prim's Algorithm Simulation on Graph Data Structure -------------------------"<<endl;
			cout<<"----------------------- Minimum Spanning Tree -------------------------"<<endl;
			for (int i = 1; i < n; ++i)
			{
				printf("Source -> %d to Destination -> %d\n", arr[i], i);
			}

		}

		// The main function that constructs Minimum Spanning Tree (MST)
		// using Prim's algorithm
		void PrimsAlgorithmonGraph(struct Graph* graph)
		{
			int V = graph->V;// Get the number of vertices in graph
			int parent[Vertices];   // Array to store constructed MST
			int key[Vertices];      // Key values used to pick minimum weight edge in cut

			// minHeap represents set E
			struct MinHeap* minHeap = createMinHeap(V);

			// Initialize min heap with all vertices. Key value of
			// all vertices (except 0th vertex) is initially infinite
			for (int v = 1; v < V; ++v)
			{
				parent[v] = -1;
				key[v] = INT_MAX;
				minHeap->array[v] = newMinHeapNode(v, key[v]);
				minHeap->pos[v] = v;
			}

			// Make key value of 0th vertex as 0 so that it
			// is extracted first
			key[0] = 0;
			minHeap->array[0] = newMinHeapNode(0, key[0]);
			minHeap->pos[0]   = 0;

			// Initially size of min heap is equal to V
			minHeap->size = V;

			// In the followin loop, min heap contains all nodes
			// not yet added to MST.
			while (!isEmpty(minHeap))
			{
				// Extract the vertex with minimum key value
				struct MinHeapNode* minHeapNode = extractMin(minHeap);
				int u = minHeapNode->v; // Store the extracted vertex number

				// Traverse through all adjacent vertices of u (the extracted
				// vertex) and update their key values
				struct AdjListNode* pCrawl = graph->array[u].head;
				while (pCrawl != NULL)
				{
					int v = pCrawl->Destination;

					// If v is not yet included in MST and weight of u-v is
					// less than key value of v, then update key value and
					// parent of v
					if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v])
					{
						key[v] = pCrawl->weight;
						parent[v] = u;
						decreaseKey(minHeap, v, key[v]);
					}
					pCrawl = pCrawl->next;
				}
			}

			// print edges of MST
			printMinimumSpanningTree(parent, V);
		}
};

	// Driver program to test above functions
	int main()
	{
		// Let us create the graph given in above figure
		//int V = 9;
//		clrscr();
		int Vertex, Edges;

		cout<<"----------------------- Prim's Algorithm Simulation on Graph Data Structure -------------------------"<<endl;
		cout<<"----------------------- Minimum Spanning Tree -------------------------"<<endl;

		int s,d,w;
		cout<<"Enter Total Vertices in Graph - ";
		cin>>Vertex;

		cout<<"Enter Total Edges in Graph -- ";
		cin>>Edges;


		MSTApp gobj;
		struct Graph* graph = gobj.createGraph(Vertex);

		for(int i = 0; i < Edges; i++)
		{
			cout<<"Enter Source Destination & Weight of Edge - ";
			cin>>s>>d>>w;
			gobj.addEdge(graph, s, d, w);
		}

		/*
		gobj.addEdge(graph, 0, 1, 4);
		gobj.addEdge(graph, 0, 7, 8);
		gobj.addEdge(graph, 1, 2, 8);
		gobj.addEdge(graph, 1, 7, 11);
		gobj.addEdge(graph, 2, 3, 7);
		gobj.addEdge(graph, 2, 8, 2);
		gobj.addEdge(graph, 2, 5, 4);
		gobj.addEdge(graph, 3, 4, 9);
		gobj.addEdge(graph, 3, 5, 14);
		gobj.addEdge(graph, 4, 5, 10);
		gobj.addEdge(graph, 5, 6, 2);
		gobj.addEdge(graph, 6, 7, 1);
		gobj.addEdge(graph, 6, 8, 6);
		gobj.addEdge(graph, 7, 8, 7);

		struct Graph* graph = gobj.createGraph(9);
		gobj.addEdge(graph, 'A', 'B', 4);
		gobj.addEdge(graph, 'A', 'H', 8);
		gobj.addEdge(graph, 'B', 'C', 8);
		gobj.addEdge(graph, 'B', 'H', 11);
		gobj.addEdge(graph, 'C', 'D', 7);
		gobj.addEdge(graph, 'C', 'I', 2);
		gobj.addEdge(graph, 'C', 'F', 4);
		gobj.addEdge(graph, 'D', 'E', 9);
		gobj.addEdge(graph, 'D', 'F', 14);
		gobj.addEdge(graph, 'E', 'F', 10);
		gobj.addEdge(graph, 'F', 'G', 2);
		gobj.addEdge(graph, 'G', 'H', 1);
		gobj.addEdge(graph, 'G', 'I', 6);
		gobj.addEdge(graph, 'H', 'I', 7);
		*/


		gobj.PrimsAlgorithmonGraph(graph);
		getch();

		return 0;
	}