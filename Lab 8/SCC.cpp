#include <iostream>
#include <list>
#include <stack>
using namespace std;
 
class Graph{
    
    //# Of vertices
    int V;

	// An array of adjacency lists
    list<int> *adj;
 
 	//fills stack with finish time
    void fillOrder(int v, bool visited[], stack<int> &Stack);
    
    //dfs through structure
    void DFS(int v, bool visited[],int *SCC, int *min);

public:

    Graph(int V){

    	this->V = V;
    	adj = new list<int>[V];
	}
 
    void addEdge(int v, int w);
    void printSCCs();
 
    Graph getTranspose();
};
  
// A recursive function to print DFS starting from v
void Graph::DFS(int v, bool visited[], int *arr, int *min){

    // Mark the current node as visited and print it
    visited[v] = true;
 	if(v <*min)
 		*min = v;
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited, arr, min);
    arr[v] = *min;
    
}
 
Graph Graph::getTranspose(){

    Graph g(V);
    for (int v = 0; v < V; v++){

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;

        for(i = adj[v].begin(); i != adj[v].end(); ++i){

            g.adj[*i].push_back(v);
        }
    }
    return g;
}
 
void Graph::addEdge(int v, int w){

    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack){

    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
 
    // All vertices reachable from v are processed by now, push v 
    Stack.push(v);
}
 
void Graph::printSCCs(){

    stack<int> Stack;
 
    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
 
    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(int i = 0; i < V; i++)
        visited[i] = false;
 	int *arr = new int[V];
 	int mem;
 	int *min = &mem;

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false){
    	*min = 1000000;
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();
 
        // Print Strongly connected component of the popped vertex
        if (visited[v] == false){

            gr.DFS(v, visited, arr, min);
                 
        }
    }
    for (int i = 0; i < V; ++i)
    	cout << arr[i] << endl;
}
 
 
int main(){
    
	int vertices;
	cin >> vertices;

	int edges;
	cin >> edges;

    Graph g(vertices);

    int u,v;

    for(int i =0; i < edges; i++){
    	cin >> u;
    	cin >> v;
    	g.addEdge(u,v);
    }

    g.printSCCs();

    return 0;
}