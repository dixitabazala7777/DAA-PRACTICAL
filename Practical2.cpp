#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 100000;
    vector<int> arr(n);

    // Populate a sorted array (1 to 100000)
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    
    auto start = high_resolution_clock::now();
    auto it = find(arr.begin(), arr.end(), key);
    auto stop = high_resolution_clock::now();

    cout << "\nLinear Search:\n";
    if (it != arr.end()) 
        cout << "Element found at index " << distance(arr.begin(), it) << endl;
    else 
        cout << "Element not found\n";
    cout << "Time Taken: " << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    
    start = high_resolution_clock::now();
    auto lb = lower_bound(arr.begin(), arr.end(), key);
    stop = high_resolution_clock::now();

    cout << "\nBinary Search:\n";
    if (lb != arr.end() && *lb == key) 
        cout << "Element found at index " << distance(arr.begin(), lb) << endl;
    else 
        cout << "Element not found\n";
    cout << "Time Taken: " << duration_cast<microseconds>(stop - start).count() << " microseconds\n";

    return 0;
}
