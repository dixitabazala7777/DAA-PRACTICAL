#include <iostream>
using namespace std;

int main() {
    int INF = 999, V = 3;              // 999 represents infinity
    int d[3][3] = {                    // Initial distance matrix
        {0, 4, 11},
        {6, 0, 2},
        {3, INF, 0}
    };

    for (int k = 0; k < V; k++)        // Intermediate vertex k
        for (int i = 0; i < V; i++)    // Source vertex i
            for (int j = 0; j < V; j++)// Destination vertex j
                if (d[i][k] + d[k][j] < d[i][j]) // If path via k is shorter
                    d[i][j] = d[i][k] + d[k][j]; // Update shortest distance

    for (int i = 0; i < V; i++) {      // Print final shortest distance matrix
        for (int j = 0; j < V; j++) cout << d[i][j] << " ";
        cout << endl;
    }
    return 0;
}
