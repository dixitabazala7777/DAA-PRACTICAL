#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Iterative Factorial
unsigned long long factorialIterative(int n) {
    unsigned long long res = 1;
    for (int i = 1; i <= n; ++i) res *= i;
    return res;
}

// Recursive Factorial
unsigned long long factorialRecursive(int n) {
    return (n <= 1) ? 1 : n * factorialRecursive(n - 1);
}

int main() {
    int n;
    cout << "Enter a non-negative integer (e.g., 20): ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid input! Please enter a non-negative integer." << endl;
        return 1;
    }

    // Iterative
    auto t1 = high_resolution_clock::now();
    unsigned long long resIter = factorialIterative(n);
    auto t2 = high_resolution_clock::now();

    // Recursive
    auto t3 = high_resolution_clock::now();
    unsigned long long resRec = factorialRecursive(n);
    auto t4 = high_resolution_clock::now();

    // Output
    cout << "\n--- Results for " << n << "! ---\n";
    cout << "Iterative Result : " << resIter << "\n";
    cout << "Iterative Time   : " << duration_cast<nanoseconds>(t2 - t1).count() << " ns\n";
    cout << "-------------------------------\n";
    cout << "Recursive Result : " << resRec << "\n";
    cout << "Recursive Time   : " << duration_cast<nanoseconds>(t4 - t3).count() << " ns\n";

    return 0;
}
