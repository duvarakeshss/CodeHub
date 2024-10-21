#include <iostream>
using namespace std;

// Function to print the subset elements
void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

// Backtracking function to check if there exists a subset with sum S
bool isSubsetSum(int A[], int n, int S, int subset[], int& subsetIndex) {
    // Base cases
    if (S == 0) return true;      // If sum is 0, we found a subset
    if (n == 0) return false;     // No elements left and sum is not 0

    // Exclude the last element if it's greater than the sum S
    if (A[n - 1] > S)
        return isSubsetSum(A, n - 1, S, subset, subsetIndex);

    // Check if we can get the sum by excluding the current element
    // If we include the current element
    if (isSubsetSum(A, n - 1, S - A[n - 1], subset, subsetIndex)) {
        subset[subsetIndex++] = A[n - 1]; // Include the element in the subset
        return true;
    }
    
    // If we exclude the current element
    return isSubsetSum(A, n - 1, S, subset, subsetIndex);
}

int main() {
    // Input array
    int A[] = {3, 2, 7, 1};
    int S = 6;  // Target sum
    int n = sizeof(A) / sizeof(A[0]);  // Size of the array

    int subset[10]; // Array to store subset elements, assuming max size of 10
    int subsetIndex = 0; // Current index in the subset array

    // Check if a subset exists
    if (isSubsetSum(A, n, S, subset, subsetIndex)) {
        cout << "True, subset exists: ";
        printSubset(subset, subsetIndex); // Print the subset elements
    } else {
        cout << "False, no subset exists." << endl;
    }

    return 0;
}
