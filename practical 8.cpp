#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    cout << u << " ";
    for (int v : adj[u])
        if (!vis[v]) dfs(v, adj, vis);
}

void bfs(int start, const vector<vector<int>>& adj, int V) {
    vector<bool> vis(V, false);
    queue<int> q;
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V, E, start;
    cout << "Enter number of vertices: "; cin >> V;
    cout << "Enter number of edges: "; cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Enter starting vertex: "; cin >> start;

    // DFS Time
    vector<bool> visDFS(V, false);
    auto t1 = high_resolution_clock::now();
    cout << "\nDFS Traversal: ";
    dfs(start, adj, visDFS);
    auto t2 = high_resolution_clock::now();

    // BFS Time
    auto t3 = high_resolution_clock::now();
    cout << "\n\nBFS Traversal: ";
    bfs(start, adj, V);
    auto t4 = high_resolution_clock::now();

    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << duration_cast<nanoseconds>(t2 - t1).count() << " ns";
    cout << "\nBFS: " << duration_cast<nanoseconds>(t4 - t3).count() << " ns";

    return 0;
}
