#include <stdio.h>
#include <limits.h>
#include <iostream>
using namespace std;

// finds minimum key values from list outside of MST set
int minimumKey(int vertices, int key[], bool mstSet[]){

   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < vertices; v++)
     if (mstSet[v] == false && key[v] < min){

         min = key[v]; 
     	 min_index = v;
     } 
 
   return min_index;
}
 
void prim(int vertices, int E){

	int u,v,w;

	//creates matrix
    int graph[vertices][vertices];


    //sets entire matrix to zero
    for (int i = 0; i < vertices; ++i)
    {
      for (int j = 0; j < vertices; ++j)
      {
        graph[i][j]=0;
      }
    }

    //fills matrix with user input
    for (int i = 0; i < E; ++i)
    {
      cin >> u;
      cin >> v;
      cin >> w;

      graph[u][v] = w;
      graph[v][u] = w;

    }

     // Array of minimum weight
     int parent[vertices];

	// Key values used to pick minimum weight edge in cut
     int key[vertices];   
     
     // To represent set of vertices in MST
     bool mstSet[vertices];  
 
     // Initialize all keys as INFINITE
     // compare this INFINITE to small numbers to swap with for a new minimum
     for (int i = 0; i < vertices; i++){
		key[i] = INT_MAX; 
		mstSet[i] = false;
     }
 
     // Make key 0 so that this vertex is picked as first vertex
     key[0] = 0; 
 
     // The MST will have the number of vertices the user inputed
     for (int i = 0; i < vertices-1; i++)
     {
        // Finds minimum value from vertices not yet inside MST set
        int u = minimumKey(vertices,key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // update key values & add to parent array of relevant vertices (not in mst)
        for (int v = 0; v < vertices; v++){
			
			//add vertice to parent and update key value for adj vertices 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v]){	

            	parent[v]  = u; 
             	key[v] = graph[u][v];	//set key to new value of weight
          }
        }
     }
 
   //prints results
   for (int i = 1; i < vertices; i++)
      cout << parent[i] << endl;

}

int main(){

	//vertices
	int vertices;
    cin >> vertices;

    //edges
    int E;
    cin >> E;

    //prim algo
    prim(vertices,E);

    return 0;
}