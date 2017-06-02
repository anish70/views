/*
 * C++ Program to Check whether Undirected Graph is Connected using BFS
 */
#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

/*
 * Class Declaration
 */
class Graph
{
    private:
        int V;		// num vertices
        list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], int parent);

    public:
        Graph(int V) {
            this->V = V;
            adj = new list<int>[V];
        }

	~Graph() {
		delete[] adj;
	}

	// Add Edge to connect v and w
        void addEdgeUndirected(int v, int w) {
	    adj[v].push_back(w);
	    adj[w].push_back(v);
	}

	void addEdgeDirected(int v, int w) {
	    adj[v].push_back(w);
	}

        void BFS(int s, bool visited[]);
	void DFSUtil(int v, bool visited[]);
        Graph getTranspose();
        bool isConnected();
	int isEulerian();
	bool isDFSConnected();
	bool isCyclic();
	bool isReachable(int s, int d);
	void topologicalSort();
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
	void bridgeUtil(int u, bool visited[], int disc[], int low[],
		int parent[]);
	void bridge();
	void AP();
	void APUtil(int u, bool visited[], int disc[], 
        		int low[], int parent[], bool ap[]);
};
 
Graph *newUndirected1();
Graph *newUndirected2();
Graph *newDirected1();
Graph *newDirected2();
Graph *newTree();

 
/*
 *  A recursive function to print DFS starting from v
 */
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;

    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
	}
    }
}

/*
 *  A recursive function to print BFS starting from s
 */
void Graph::BFS(int s, bool visited[])
{
    list<int> q;
    visited[s] = true;	// Mark S as visited
    q.push_back(s);	// put S in q

    while (!q.empty()) {	// While Q is not empty
        s = q.front();		// remove a node from the queue
        q.pop_front();

	// for each edge(v,w); do ; if w is unexplored; mark it visited.
        for(list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;

		// add w to end of the queue
                q.push_back(*i);
            }
        }
    }
}

/*
 * Function that returns reverse (or transpose) of this graph
 */
Graph Graph::getTranspose()
{
	Graph g(V);

	// walk through all vertices
	for (int v = 0; v < V; v++) {
		for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

/*
 * Check if Graph is Connected via BFS
 */
bool Graph::isConnected()
{
    bool visited[V];

    // 1. mark all nodes as not visited.
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // 2. BFS to figure out all vertices
    BFS(0, visited);

    // 3. if not found: Set to false
    for (int i = 0; i < V; i++) {
        if (visited[i] == false)
            return false;
    }

    // 4. Local variable
    Graph gr = getTranspose();

    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

	// 4. repeat BFS
    gr.BFS(0, visited);
    for (int i = 0; i < V; i++) {
        if (visited[i] == false)
            return false;
    }

    return true;
}

/*
 * Check if Graph is Connected via DFS
 * 1. mark all nodes as not visited
 * 2. DFS search
 * 3. get a Transpose
 * 4. DFS search of transpose (local var)
 * 5. repeat DFS search
 */
bool Graph::isDFSConnected()
{
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    DFSUtil(0, visited);
    for (int i = 0; i < V; i++) {
        if (visited[i] == false)
            return false;
    }

    Graph gr = getTranspose();
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
    gr.DFSUtil(0, visited);

    for (int i = 0; i < V; i++) {
        if (visited[i] == false)
            return false;
    }
    return true;
}

// A recursive function that uses visited[] and parent to detect
// cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
        // If an adjacent is not visited, then recur for that adjacent
        if (!visited[*i]) {
            if (isCyclicUtil(*i, visited, v))
                return true;
        } else if (*i != parent) {
            // If an adjacent is visited and not parent of current vertex,
            // then there is a cycle.
            return true;
	}
    }
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++) {
        if (!visited[u]) // Don't recur for u if it is already visited
            if (isCyclicUtil(u, visited, -1))
                return true;
    }
 
    return false;
}


// A recursive function that find articulation points using DFS traversal
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree
// ap[] --> Store articulation points
void Graph::APUtil(int u, bool visited[], int disc[], 
                                      int low[], int parent[], bool ap[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Count of children in DFS Tree
    int children = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of u
 
        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // u is an articulation point in following cases
 
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == -1 /* NIL */ && children > 1)
               ap[u] = true;
 
            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != -1  /* NIL */&& low[v] >= disc[u])
               ap[u] = true;
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
// The function to do DFS traversal. It uses recursive function APUtil()
void Graph::AP()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V]; // To store articulation points
 
    // Initialize parent and visited, and ap(articulation point) arrays
    for (int i = 0; i < V; i++) {
        parent[i] = -1; /* NIL */
        visited[i] = false;
        ap[i] = false;
    }
 
    // Call the recursive helper function to find articulation points
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
 
    // Now ap[] contains articulation points, print them
    cout << "AP:\n";
    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << " ";
    cout << endl;
}
 
 
// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;	// Mark the current node as visited.
 
    // Recur for all the vertices adjacent to this vertex
    for (list<int>::iterator i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    }
 
    Stack.push(v);	// Push current vertex to stack which stores result
}
 
// The function to do Topological Sort. It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    cout << "Topological Sorted: ";

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++) {
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    }
 
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

Graph *newUndirected1() {
    Graph *g = new Graph(4);
    g->addEdgeUndirected(0, 1);
    g->addEdgeUndirected(0, 2);
    g->addEdgeUndirected(1, 2);
    g->addEdgeUndirected(2, 3);
    g->addEdgeUndirected(3, 3);
    return g;
}

Graph *newUndirected2() {
    Graph *g = new Graph(5);
    g->addEdgeUndirected(0, 1);
    g->addEdgeUndirected(1, 2);
    g->addEdgeUndirected(2, 3);
    g->addEdgeUndirected(3, 0);
    g->addEdgeUndirected(2, 4);
    g->addEdgeUndirected(4, 2);
    return g;
}

Graph *newDirected1() {
    Graph *g = new Graph(4);
    g->addEdgeDirected(0, 1);
    g->addEdgeDirected(0, 2);
    g->addEdgeDirected(1, 2);
    g->addEdgeDirected(2, 3);
    g->addEdgeDirected(3, 3);
    return g;
}

Graph *newDirected2() {
    Graph *g = new Graph(5);
    g->addEdgeDirected(0, 1);
    g->addEdgeDirected(1, 2);
    g->addEdgeDirected(2, 3);
    g->addEdgeDirected(3, 0);
    g->addEdgeDirected(2, 4);
    g->addEdgeDirected(4, 2);
    return g;
}

Graph *newTree() {
    Graph *g = new Graph(6);
    g->addEdgeDirected(5, 0);
    g->addEdgeDirected(5, 2);
    g->addEdgeDirected(4, 0);
    g->addEdgeDirected(4, 1);
    g->addEdgeDirected(2, 3);
    g->addEdgeDirected(3, 1);
    return g;
}

void Graph::bridgeUtil(int u, bool visited[], int disc[], int low[],
        int parent[])
{
    // A static variable is used for simplicity, we can avoid use of static
    // variable by passing a pointer.
    static int time = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of u
 
        // If v is not visited yet, then recur for it
        if (!visited[v]) {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
 
            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u] = min(low[u], low[v]);
 
            // If the lowest vertex reachable from subtree under v is
            // below u in DFS tree, then u-v is a bridge
            if (low[v] > disc[u])
                cout << u << " " << v << endl;
        } else if (v != parent[u]) {
	    // Update low value of u for parent function calls.
            low[u] = min(low[u], disc[v]);
	}
    }
}
 
// DFS based function to find all bridges. It uses recursive function bridgeUtil()
void Graph::bridge()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
 
    // Initialize parent and visited arrays
    for (int i = 0; i < V; i++) {
        parent[i] = 0;
        visited[i] = false;
    }
 
    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 0; i < V; i++) {
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
    }
}

/* The function returns one of the following values
 0 --> If grpah is not Eulerian
 1 --> If graph has an Euler path (Semi-Eulerian)
 2 --> If graph has an Euler Circuit (Eulerian)  */
int Graph::isEulerian()
{
    // Check if all non-zero degree vertices are connected
    if (isConnected() == false)
        return 0;
 
    // Count vertices with odd degree
    int odd = 0;
    for (int i = 0; i < V; i++) {
        if (adj[i].size() & 1)
            odd++;
    }
 
    // If count is more than 2, then graph is not Eulerian
    if (odd > 2) {
        return 0;
    }
 
    // If odd count is 2, then semi-eulerian.
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd) ? 1 : 2;
}


// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(int s, int d)
{
    // Base case
    if (s == d)
        return true;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            // If this adjacent node is the destination node, then return true
            if (*i == d)
                return true;
 
            // Else, continue to do BFS
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
 
    return false;
}

/*
 * Main Contains Menu
 */
int main()
{
    Graph *g1;

    g1 = newUndirected1();
    cout << "The Undirected Graph is " << (g1->isConnected() ? "Connected" : "not Connected") << endl;
    cout << "The Graph is " << (g1->isCyclic() ? "not Tree" : "Tree") << endl;
    cout << "The Graph has " << (g1->isReachable(0,3) ? "a " : "no ")  << "path from 0  to 3" << endl;
    int j = g1->isEulerian();
    switch(j) {
    case 0:
	cout << "Graph is not Eulerian\n"; break;
    case 1:
	cout << "Graph has Euler path\n"; break;
    case 2:
	cout << "Graph has Euler cycle\n"; break;
    default: 
	cout << "Unknown Graph\n"; break;
    }
    g1->bridge();
    g1->AP();
    delete g1;
 
    g1 = newUndirected2();
    cout << "The Undirected Graph is " << (g1->isConnected() ? "Connected" : "not Connected") << endl;
    delete g1;

    g1 = newDirected2();
    cout << "The Directed Graph is DFS " << (g1->isDFSConnected() ? "Connected" : "not Connected") << endl;
    cout << "The Graph is " << (g1->isCyclic() ? "not Tree" : "Tree") << endl;
    g1->bridge();
    g1->topologicalSort();
    delete g1;

    g1 = newDirected1();
    cout << "The Directed Graph is DFS " << (g1->isDFSConnected() ? "Connected" : "not Connected") << endl;
    delete g1;

    g1 = newTree();
    cout << "The Graph is " << (g1->isCyclic() ? "not Tree" : "Tree") << endl;
    g1->topologicalSort();
    delete g1;
 
    return 0;
}
