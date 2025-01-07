#include <iostream>
using namespace std;

// Function to perform backtracking to find all unique ways to climb the staircase
void findWays(int N, int path[], int index, int& totalWays) {
    // If exactly N steps are climbed, print the current path and increment the count
    if (N == 0) {
        totalWays++;  // Increment the total number of ways
        for (int i = 0; i < index; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    // If more than N steps are climbed, return (invalid path)
    if (N < 0) {
        return;
    }

    // Try to take 1 step
    path[index] = 1;
    findWays(N - 1, path, index + 1, totalWays);
    
    // Try to take 2 steps
    path[index] = 2;
    findWays(N - 2, path, index + 1, totalWays);
}

int main() {
    int N;
    cout << "Enter the number of steps: ";
    cin >> N;

    int path[N];     // Array to store the current path
    int totalWays = 0; // To count the total number of ways

    // Backtracking function call
    findWays(N, path, 0, totalWays);

    // Print the total number of ways
    cout << "Number of unique ways: " << totalWays << endl;

    return 0;
}
