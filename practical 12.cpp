#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int d[4][4] = {                    // Distance matrix between 4 cities
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int city[] = {1, 2, 3};            // Cities to visit (starting from 0)
    int minCost = 999;

    do {                               // Try every possible route order
        int cost = d[0][city[0]] + d[city[0]][city[1]] + d[city[1]][city[2]] + d[city[2]][0];
        minCost = min(minCost, cost);  // Keep the lowest route cost
    } while (next_permutation(city, city + 3)); // Generate next permutation

    cout << "Min TSP Cost: " << minCost; // Print minimum tour cost
    return 0;
}
