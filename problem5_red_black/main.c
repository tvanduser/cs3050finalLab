#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// ----- ADTS -----
//struct to represent an edge with source dest and weight
typedef struct Edge{
    int dest;
    int src;
    int weight;
} Edge;

//struct to represent a graph, # of verticies, edges, and an array of edges
typedef struct Graph{
    int V;
    int E;
    Edge *edges;
} Graph;

//struct for subsets when we need a union field
typedef struct Subset{
    int parent;
    int rank;
} Subset;

// ----- HELPER FUNCS -----
Graph *createGraph(int V, int E){
    Graph *graph = malloc(sizeof(Graph));
    graph->E = E;
    graph->V = V;
    graph->edges = malloc(E *sizeof(Edge)); // make enough space for all the edges that the graph has
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


// Union by rank
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int computeBST(Graph* graph, Edge* result) {
    int V = graph->V;
    qsort(graph->edges, graph->E, sizeof(Edge), compareEdges);

    Subset* subsets = malloc(V * sizeof(Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0; // index for result[]
    int i = 0; // index for sorted edges
    int bottleneck = -1;

    while (e < V - 1 && i < graph->E) {
        Edge next = graph->edges[i++];
        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);

        if (x != y) {
            result[e++] = next;
            unionSets(subsets, x, y);
            if (next.weight > bottleneck)
                bottleneck = next.weight;
        }
    }

    free(subsets);

    if (e != V - 1)
        return -1; // not connected

    return bottleneck;
}

int main() {
    // Compute Bottleneck Spanning Tree
    // Problem 5: Implement a function that takes a graph and computes the bottleneck spanning tree (BST) of the graph.
    // The graph is represented as an adjacency list, and the function should return the edges of the BST.
    // The function should also handle the case where the graph is not connected.
    // The function should also handle the case where the graph is a complete graph.
    // The function should also handle the case where the graph is a tree.
    // TODO: Implement this problem's solution
    int V = 4; // vertices
    int E = 5; // edges
    Graph* graph = createGraph(V, E);

    // Add edges: src, dest, weight
    graph->edges[0] = (Edge){0, 1, 10};
    graph->edges[1] = (Edge){0, 2, 6};
    graph->edges[2] = (Edge){0, 3, 5};
    graph->edges[3] = (Edge){1, 3, 15};
    graph->edges[4] = (Edge){2, 3, 4};

    Edge* result = malloc((V - 1) * sizeof(Edge));
    int bottleneck = computeBST(graph, result);

    if (bottleneck == -1) {
        printf("Graph is not connected, no spanning tree.\n");
    } else {
        printf("Bottleneck Spanning Tree Edges:\n");
        for (int i = 0; i < V - 1; i++)
            printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        printf("Bottleneck value: %d\n", bottleneck);
    }

    free(graph->edges);
    free(graph);
    free(result);
    return 0;
}
