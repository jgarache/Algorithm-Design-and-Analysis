#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

 
void bellmanFord(int vertices, int E){

	int u =0;
	int v =0;
	int w =0;
	int dist[vertices];
	int uarr[E];
	int varr[E];

	//creates matrix
    int graph[vertices][vertices];


    //sets entire matrix to zero
    for (int i = 0; i < vertices; ++i){
      for (int j = 0; j < vertices; ++j){
        graph[i][j]=0;
      }
    }

    //fills matrix with user input
    for (int i = 0; i < E; ++i){
      cin >> u;
      cin >> v;
      cin >> w;

      graph[u][v] = w;
      uarr[i] = u;
      varr[i] = v;
    }

    //1.initialized distance from source to all other vertices to infinity
    for(int i =0; i < vertices; i++){
    	dist[i] = INT_MAX;
    }

    //origin is 0
    dist[0]=0;

    //2.relax all edges
    for(int i =0; i < vertices-1; i++){
    	for (int j = 0; j < E; j++){
    		
    		u = uarr[j];
    		v = varr[j];
    		w = graph[u][v];

    		if(dist[u] != INT_MAX && dist[u] + w < dist[v])
    			dist[v] = dist[u] + w;
    	}
    }


    int count = 0;

    //3.check for negative weight cycles
    for(int i =0; i < E; i++){
    	u = uarr[i];
    	v = varr[i];
    	w = graph[u][v];

    	if(dist[u] != INT_MAX && dist[u] + w < dist[v]) count++;
    }

    //prints
    if (count == 0){
    	cout << "TRUE" << endl;
	    for (int i = 0; i < vertices; ++i){
	    	if(dist[i] == INT_MAX)
	    		cout << "INFINITY"<<endl;
	    	else
	    		cout << dist[i]<<endl;
	    }
    }
    else
    	cout << "FALSE"<<endl;
}

int main(){

	//vertices
	int vertices;
    cin >> vertices;

    //edges
    int E;
    cin >> E;

    //bellmanFord algo
    bellmanFord(vertices,E);

    return 0;
}