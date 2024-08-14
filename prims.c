#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph
#define INF 999999  // A large value to represent infinity

// Function to find the vertex with the minimum key value that is not yet included in the MST
int minKey(int key[], bool mstSet[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to implement Prim's algorithm
void PrimMST(int graph[V][V]) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values used to pick the minimum weight edge
    bool mstSet[V]; // Array to track vertices included in the MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Start from the first vertex (index 0)
    key[0] = 0;
    parent[0] = -1; // The first vertex is the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex not yet included in the MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update the key value and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
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

    PrimMST(graph);

    return 0;
}
