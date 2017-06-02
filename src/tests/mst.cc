#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
using namespace std;
 
// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};
 
// a structure to represent a connected, undirected and weighted graph
struct Graph
{
        // V-> Number of vertices, E-> Number of edges
        int V, E;
 
        // graph is represented as an array of edges. Since the graph is
        // undirected, the edge from src to dest is also edge from dest
        // to src. Both are counted as 1 edge here.
        struct Edge* edge;
	void addEdge(int index, int src, int dest, int weight);
};
 
void
Graph::addEdge(int index, int src, int dest, int weight)
{
	this->edge[index].src = src;
	this->edge[index].dest = dest;
	this->edge[index].weight = weight;
}

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset
{
        int parent;
        int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
	// find root and make root as parent of i (path compression)
	if (subsets[i].parent != i) {
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
 
	return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
	// If ranks are same, then make one as root and increment
	// its rank by one
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*) a;
	struct Edge* b1 = (struct Edge*) b;
	return a1->weight > b1->weight;
}
 
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
	int V = graph->V;	// how many Edges
	struct Edge result[V]; // Tnis will store the resultant MST
	int e = 0; // An index variable, used for result[]
	int i = 0; // An index variable, used for sorted edges
 
	// Step 1:  Sort all the edges in non-decreasing order of their weight
	// If we are not allowed to change the given graph, we can create
	// a copy of array of edges
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
	// Allocate memory for creating V ssubsets
	struct subset *subsets;
	subsets = (struct subset*) malloc(V * sizeof(struct subset));
 
	// Create V subsets with single elements
	for (int v = 0; v < V; ++v) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
 
	// Number of edges to be taken is equal to V-1
	while (e < V - 1) {
		// Step 2: Pick the smallest edge. And increment the index
		// for next iteration
		struct Edge next_edge = graph->edge[i++];
 
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
 
		// If including this edge does't cause cycle, include it
		// in result and increment the index of result for next edge
		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
		// Else discard the next_edge
	}
 
	// print the contents of result[] to display the built MST
	cout<<"Following are the edges in the constructed MST\n";
	for (i = 0; i < e; ++i)
		printf("%d -- %d == %d\n", result[i].src, result[i].dest,
				result[i].weight);
}

#if 0
void prim(struct Graph *g, int root) {
        unordered_map<int, int> res;
        unordered_map<int, int> PARENT;
        unordered_map<int, int> KEY;

        for (auto c : g->V) {
                PARENT[c] = 0;
                KEY[c] = INT_MAX;
        }
        KEY[root] = 0;
        vector<int> Q = g->edge; 

        while (!Q.empty()) {    // O(V)
                int u = *std::min_element(Q.begin(), Q.end(), [&](int x, int y) {return KEY[x] < KEY[y];});  // O(v)
                vector<int>::iterator itr = remove(Q.begin(), Q.end(), u);  // O(V)
                Q.erase(itr, Q.end());  // erase() following remove() idiom
                if (PARENT[u] != '\0') {
                        res[u] = PARENT[u];   // This is one edge of MST
                }
                vector< pair<int, Edge> > adj = g.adjacent(u);   // O(E)
                for (pair<int, Edge> v : adj) {
                        if (find(Q.begin(), Q.end(), v.first) != Q.end()) {   // O(V)
                                if (v.second.weight < KEY[v.first]) {
                                        PARENT[v.first] = u;
                                        KEY[v.first] = v.second.weight;
                                }
                        }
                }
        }

        for (auto e : res) {
                cout << e.first << " -- " << e.second << endl;
        }
}


#endif
 
// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
         10
     0--------1
     | \      |
    6|   \5   |15
     |      \ |
     2--------3
     4       */
    int V = 4; // Number of vertices in graph
    int E = 6; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
 
    graph->addEdge(0, 0, 1, 10); // add edge 0-1
    graph->addEdge(1, 0, 2, 6); // add edge 0-2
    graph->addEdge(2, 0, 3, 5); // add edge 0-3
    graph->addEdge(3, 1, 3, 15); // add edge 1-3
    graph->addEdge(4, 2, 3, 4); // add edge 2-3
    graph->addEdge(5, 1, 2, 3); // add edge 1-2
 
    KruskalMST(graph);
    return 0;
}
