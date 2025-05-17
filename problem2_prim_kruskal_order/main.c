#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 5

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct EdgeNode {
    int dest, weight;
    struct EdgeNode* next;
} EdgeNode;

typedef struct {
    EdgeNode* head;
} AdjList;

AdjList graph[V];

// Adds an undirected edge
void addEdge(int u, int v, int w) {
    EdgeNode* node1 = malloc(sizeof(EdgeNode));
    node1->dest = v;
    node1->weight = w;
    node1->next = graph[u].head;
    graph[u].head = node1;

    EdgeNode* node2 = malloc(sizeof(EdgeNode));
    node2->dest = u;
    node2->weight = w;
    node2->next = graph[v].head;
    graph[v].head = node2;
}

// ---- PRIM'S ----
Edge primOrder[V - 1];

void primMST() {
    bool inMST[V] = { false };
    int key[V];
    int parent[V];
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V; count++) {
        int min = INT_MAX, u = -1;
        for (int v = 0; v < V; v++)
            if (!inMST[v] && key[v] < min)
                min = key[v], u = v;

        if (u == -1) {
            printf("Graph not connected (Prim)\n");
            return;
        }

        inMST[u] = true;

        EdgeNode* temp = graph[u].head;
        while (temp) {
            int v = temp->dest;
            if (!inMST[v] && temp->weight < key[v]) {
                key[v] = temp->weight;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    int idx = 0;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            primOrder[idx++] = (Edge){ parent[i], i, key[i] };
        }
    }
}

// ---- KRUSKAL'S ----
Edge allEdges[100];
Edge kruskalOrder[V - 1];
int edgeCount = 0;

int parent[V], rank[V];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void unionSets(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rank[rx] < rank[ry]) parent[rx] = ry;
    else if (rank[rx] > rank[ry]) parent[ry] = rx;
    else parent[ry] = rx, rank[rx]++;
}

int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskalMST() {
    for (int i = 0; i < V; i++) parent[i] = i, rank[i] = 0;

    // Extract edges from adjacency list (avoid duplicates)
    bool seen[V][V] = { false };
    edgeCount = 0;
    for (int u = 0; u < V; u++) {
        EdgeNode* temp = graph[u].head;
        while (temp) {
            int v = temp->dest;
            if (!seen[u][v]) {
                allEdges[edgeCount++] = (Edge){u, v, temp->weight};
                seen[u][v] = seen[v][u] = true;
            }
            temp = temp->next;
        }
    }

    qsort(allEdges, edgeCount, sizeof(Edge), compare);

    int count = 0;
    for (int i = 0; i < edgeCount && count < V - 1; i++) {
        int u = allEdges[i].src;
        int v = allEdges[i].dest;
        if (find(u) != find(v)) {
            kruskalOrder[count++] = allEdges[i];
            unionSets(u, v);
        }
    }

    if (count < V - 1) {
        printf("Graph not connected (Kruskal)\n");
    }
}

// ---- COMPARISON ----
void compareMSTOrders() {
    primMST();
    kruskalMST();

    printf("\nPrim's MST Order:\n");
    for (int i = 0; i < V - 1; i++)
        printf("%d -- %d (w=%d)\n", primOrder[i].src, primOrder[i].dest, primOrder[i].weight);

    printf("\nKruskal's MST Order:\n");
    for (int i = 0; i < V - 1; i++)
        printf("%d -- %d (w=%d)\n", kruskalOrder[i].src, kruskalOrder[i].dest, kruskalOrder[i].weight);
}

// ---- MAIN ----
int main() {
    // Build a connected graph with meaningful weights
    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    compareMSTOrders();

    return 0;
}

