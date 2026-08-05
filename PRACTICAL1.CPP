#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

template <typename Func>
void measureTime(string name, Func task) {
    auto start = high_resolution_clock::now();
    task();
    auto stop = high_resolution_clock::now();
    cout << name << " Time: " 
         << duration_cast<microseconds>(stop - start).count() 
         << " microseconds\n";
}

int main() {
    int n = 1000;
    vector<int> arr(n), temp;

    
    for (int i = 0; i < n; i++) arr.push_back(rand() % 1000);

    cout << "Number of Elements = " << n << "\n\n";

    
    temp = arr;
    measureTime("std::sort (IntroSort/QuickSort)", [&]() {
        sort(temp.begin(), temp.end());
    });


    temp = arr;
    measureTime("std::stable_sort (Merge Sort)", [&]() {
        stable_sort(temp.begin(), temp.end());
    });

   
    temp = arr;
    measureTime("Heap Sort", [&]() {
        make_heap(temp.begin(), temp.end());
        sort_heap(temp.begin(), temp.end());
    });

    return 0;
}
