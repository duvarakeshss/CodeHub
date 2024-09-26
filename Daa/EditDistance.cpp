#include <iostream>
#include <string>
#include <algorithm> // for min function

using namespace std;

void Edit_distance(string x, string y, int n, int m) {
    // Create a 2D array for storing edit distances
    int dp[m + 1][n + 1];

    // Initialize the base cases (transforming empty string to a string)
    for (int j = 0; j <= n; j++)
        dp[0][j] = j; // Cost of inserting characters
    for (int i = 0; i <= m; i++)
        dp[i][0] = i; // Cost of deleting characters

    // Fill dp array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                // If characters match, no change needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Take the minimum of insertion, deletion, or substitution
                dp[i][j] = min({1 + dp[i - 1][j],    // Deletion
                                1 + dp[i][j - 1],    // Insertion
                                1 + dp[i - 1][j - 1] // Substitution
                               });
            }
        }
    }

    // Print the edit distance table
    cout << "\nEdit distance table: " << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    // The final edit distance
    cout << "\nEdit distance is: " << dp[m][n] << endl;
}

int main() {
    string x, y;

    cout << "Enter the 1st word: ";
    cin >> x;
    cout << "Enter the 2nd word: ";
    cin >> y;

    int n = x.length();
    int m = y.length();

    Edit_distance(x, y, n, m);

    return 0;
}
