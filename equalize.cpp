#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of operations to convert array A to array B
long solution(vector<long> A, vector<long> B) {
    int n = A.size(); // Get the size of the arrays
    long incr = 0, decr = 0, ops = 0; // Initialize variables to track increments, decrements, and operations

    // Iterate through each element of the arrays
    for (int i = 0; i < n; i++) {
        long diff = B[i] - A[i]; // Calculate the difference between corresponding elements of B and A

        if (diff > 0) { // If the difference is positive (B[i] > A[i])
            if (incr < diff)
                ops += diff - incr; // Increment operations if the required increment is more than the current
            incr = diff; // Update the increment value
            decr = 0; // Reset decrement value
        } else if (diff < 0) { // If the difference is negative (B[i] < A[i])
            if (diff < decr)
                ops += decr - diff; // Increment operations if the required decrement is more than the current
            decr = diff; // Update the decrement value
            incr = 0; // Reset increment value
        } else {
            incr = decr = 0; // Reset both increment and decrement if A[i] == B[i]
        }
    }

    return ops; // Return the total number of operations
}

int main() {
    long n;
    cin >> n; // Input the number of elements
    vector<long> a(n); // Initialize vector a with n elements
    vector<long> b(n); // Initialize vector b with n elements
    
    // Input elements of vector a
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Input elements of vector b
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    // Calculate the minimum number of operations and print the result
    long ans = solution(a, b);
    cout << ans << endl;
    
    return 0; 
}
