#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// MAX HEAP
void maxHeapify(vector<int> &arr, int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) maxHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// MIN HEAP
void minHeapify(vector<int> &arr, int n, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest]) smallest = left;
    if (right < n && arr[right] < arr[smallest]) smallest = right;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) minHeapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
    reverse(arr.begin(), arr.end());
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);
    srand(time(0));
    for (int i = 0; i < n; i++) original[i] = rand() % 100000;

    vector<int> maxHeapArray = original, minHeapArray = original;

    // Max Heap Timing
    auto t1 = high_resolution_clock::now();
    maxHeapSort(maxHeapArray);
    auto t2 = high_resolution_clock::now();

    // Min Heap Timing
    auto t3 = high_resolution_clock::now();
    minHeapSort(minHeapArray);
    auto t4 = high_resolution_clock::now();

    // Display Time
    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << duration_cast<nanoseconds>(t2 - t1).count() << " ns\n";
    cout << "Microseconds : " << duration_cast<microseconds>(t2 - t1).count() << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << duration_cast<nanoseconds>(t4 - t3).count() << " ns\n";
    cout << "Microseconds : " << duration_cast<microseconds>(t4 - t3).count() << " us\n";

    return 0;
}
