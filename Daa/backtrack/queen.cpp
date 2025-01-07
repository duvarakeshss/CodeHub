#include<iostream>
using namespace std;

int n;

//Function to check if it's safe to place a queen at board[i][j]
bool issafe(int i, int j, int board[20][20], int N)
{
    int k,l;
    //Check the column (no other queen above in the same column)
    for (k = 0; k <= i - 1; k++)
    {
        if(board[k][j] == 1)
            return false;
    }
    //Check the upper right diagonal
    k = i - 1;
    l = j + 1;
    while(k >= 0 && l < N)
    {
        if(board[k][l] == 1)
            return false;
        k--;
        l++;
    }
    // Check the upper left diagonal
    k = i - 1;
    l = j - 1;
    while(k >= 0 && l >= 0)
    {
        if(board[k][l] == 1)
            return false;
        k--;
        l--;
    }
    return true;
}

// Function to solve N-Queens problem using backtracking
bool n_queen(int row, int noqueen, int N, int board[20][20])
{
    if(noqueen == 0)  // Base case: all queens are placed
        return true;

    // Try placing the queen in all columns in the current row
    for(int j = 0; j < N; j++)
    {
        if(issafe(row, j, board, N))
        {
            board[row][j] = 1;  // Place the queen

            // Recur to place the remaining queens
            if(n_queen(row + 1, noqueen - 1, N, board))
                return true;

            // Backtrack if placing the queen doesn't lead to a solution
            board[row][j] = 0;
        }
    }
    return false;  // No place found for the current queen
}

int main()
{
    cout <<"Enter n (size of the board): ";
    cin >>n;
    int board[20][20];// Increase the array size to handle larger boards
    // Initialize the board with 0s
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    // Start solving the N-Queens problem
    if(n_queen(0, n, n, board))
    {
        // Print the solution if found
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists for " << n << " queens." <<endl;
    }
    return 0;
}