#include <iostream>
using namespace std;

int main() {
    int V = 4;                         // Number of vertices
    int G[4][4] = {                    // Adjacency matrix of graph
        {0, 2, 0, 6},
        {2, 0, 3, 8},
        {0, 3, 0, 5},
        {6, 8, 5, 0}
    };
    bool vis[4] = {true, false, false, false}; // Start with vertex 0 visited
    int cost = 0;                      // Total MST weight

    for (int edges = 0; edges < V - 1; edges++) { // MST always has V-1 edges
        int minW = 999, u = 0, v = 0;
        for (int i = 0; i < V; i++) {              // Check visited vertices
            if (vis[i]) {
                for (int j = 0; j < V; j++) {      // Check unvisited neighbors
                    if (!vis[j] && G[i][j] && G[i][j] < minW) {
                        minW = G[i][j]; u = i; v = j; // Find smallest edge
                    }
                }
            }
        }
        vis[v] = true;                 // Mark new vertex visited
        cost += minW;                  // Add edge weight to total
        cout << u << " - " << v << " : " << minW << endl; // Print edge
    }
    cout << "Total Cost: " << cost;
    return 0;
}
