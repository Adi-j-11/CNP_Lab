#include <stdio.h>
#include <stdlib.h>

#define V 5  // Number of vertices in the graph
#define INF 999999  // A large value to represent infinity

// A structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// A utility function to find the parent of an element
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// A utility function to do union of two sets
void Union(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (xroot != yroot)
        parent[xroot] = yroot;
}

// Function to compare two edges (used in qsort)
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Function to implement Kruskal's algorithm
void KruskalMST(int graph[V][V]) {
    Edge edges[V * V];
    int edgeCount = 0;

    // Convert the adjacency matrix to an edge list
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] != INF) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort all edges in non-decreasing order of their weight
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    int parent[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    printf("Edge \tWeight\n");
    for (int i = 0; i < edgeCount; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        // If including this edge does not cause a cycle
        if (x != y) {
            printf("%d - %d \t%d\n", edges[i].src, edges[i].dest, edges[i].weight);
            Union(parent, x, y);
        }
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    KruskalMST(graph);

    return 0;
}
