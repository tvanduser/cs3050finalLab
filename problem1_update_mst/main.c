// **** not complete ****
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Update MST when a new vertex and incident edges are added
// Problem 1: Implement a function that takes a graph and a new vertex with its incident edges
// and updates the minimum spanning tree (MST) of the graph.
// The graph is represented as an adjacency list, and the new vertex is represented as a list of edges.
// The function should return the updated MST as an adjacency list.
// The function should also handle the case where the new vertex is not connected to any existing vertices in the graph.
// The function should also handle the case where the new vertex is connected to multiple existing vertices in the graph.
// The function should also handle the case where the new vertex is connected to a single existing vertex in the graph.
// TODO: Implement this problem's solution

//define some constants
#define MAXVERTICIES 100

//ADTS
typedef struct Edge{
    int dest;
    int weight;
    struct Edge *next;
} Edge; 

//Existing mst
Edge* mst[MAXVERTICIES];
int vertexCount = 0;

//-----helper functions-------

//add edge to the adjacency list
void addEdge(Edge *adjList[], int src, int dest, int weight){
    Edge * newEdge = malloc(sizeof(Edge));
    if(!newEdge){
        printf("edge creation failed");
    }
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = adjList[src];
    adjList[src] = newEdge;
}

// create an edge node 
Edge * createEdge(int dest, int weight, Edge * next){
    //make the space for the new edge
    Edge *newEdge = malloc(sizeof(Edge));
    if(!newEdge){
        printf("edge creation failed\n");
        return NULL;
    }
    //set the values
    newEdge->dest = dest;
    newEdge->weight = weight;
    newEdge->next = next;
    //return it
    return newEdge;
}

// find the vertex with the min key that isn't in the MST yet from the adjecency list being passed in
// int findMinKey(int key[], int mst[], int n){
//
//     int min = INT_MAX;
//     int minIndex = -1;
//
//     for(int i = 0; i < n; i++){
//         if(!mst[i] && key[i] < min){
//             min = key[i];
//             minIndex = i;
//         }
//     }
//
//     return minIndex;
// }


//update MST function
void updataMST(int newVertex, Edge *newEdges){
    mst[newVertex] = NULL;

    int minWeight = INT_MAX;
    int bestDest = -1;

    //find the edge with the lowest weight that connects to an existing vertex 
    for(Edge * e = newEdges; e != NULL; e = e->next){
        if(e->dest < vertexCount && e->weight < minWeight){
            minWeight = e->weight;
            bestDest = e-> dest;
        }
    }


    if(bestDest !=-1){
        addEdge(mst, newVertex, bestDest, minWeight);
        addEdge(mst, bestDest, newVertex, minWeight);
    }


    if(newVertex >= vertexCount){
        vertexCount = newVertex + 1;
    }
}

void printGraph(Edge* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d:", i);
        for (Edge* e = adj[i]; e != NULL; e = e->next) {
            printf(" -> (%d, %d)", e->dest, e->weight);
        }
        printf("\n");
    }
}



int main() {
    printf("MST Problem\n");
    printf("---------------------------\n");

printf("MST Update Only\n");
    printf("---------------------------\n");

    // Start with a known MST with 3 nodes
    vertexCount = 3;
    addEdge(mst, 0, 1, 1);
    addEdge(mst, 1, 0, 1);
    addEdge(mst, 1, 2, 2);
    addEdge(mst, 2, 1, 2);

    printf("Initial MST:\n");
    printGraph(mst, vertexCount);

    // Add new vertex 3 with edges to 0 and 2
    Edge* newEdges = NULL;
    newEdges = createEdge(0, 4, newEdges);
    newEdges = createEdge(2, 1, newEdges);

    updataMST(3, newEdges);

    printf("\nMST after adding vertex 3:\n");
    printGraph(mst, vertexCount);

    // Add disconnected vertex 4
    updataMST(4, NULL);

    printf("\nMST after adding vertex 4 (disconnected):\n");
    printGraph(mst, vertexCount);

    return 0;

    
    return 0;
}
