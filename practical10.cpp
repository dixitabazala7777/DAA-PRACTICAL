#include <iostream>
#include <algorithm>
using namespace std;

struct Edge { int u, v, w; };          // Structure to store an edge
int parent[4];                         // Array to track connected components

int find(int i) {                      // Find root parent of vertex i
    while (parent[i] != i) i = parent[i];
    return i;
}

int main() {
    Edge e[] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 5}, {0, 3, 6}, {1, 3, 8}}; // Graph edges
    for (int i = 0; i < 4; i++) parent[i] = i; // Each node is its own parent

    sort(e, e + 5, [](Edge a, Edge b) { return a.w < b.w; }); // Sort edges by weight

    int cost = 0;
    for (int i = 0; i < 5; i++) {      // Loop through sorted edges
        int a = find(e[i].u);          // Root of u
        int b = find(e[i].v);          // Root of v
        if (a != b) {                  // If they don't form a cycle
            parent[a] = b;             // Connect them
            cost += e[i].w;            // Add weight
            cout << e[i].u << " - " << e[i].v << " : " << e[i].w << endl;
        }
    }
    cout << "Total Cost: " << cost;
    return 0;
}
