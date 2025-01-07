#include <iostream>
using namespace std;

// Function to print the current state of the board
void printBoard(char board[], int size) {
    // This function loops through the board array and prints each element (marble or empty space)
    // It helps in visualizing the current arrangement of the marbles on the board.
    for (int i = 0; i < size; i++) {
        cout << board[i] << " ";
    }
    cout << endl;
}

// Function to check if the puzzle is solved (All Greens on the left, Empty space in the middle, Reds on the right)
bool isSolved(char board[], int n) {
    // This function checks if the board has reached the goal state:
    // 1. The first 'n' positions should contain Green marbles ('G')
    // 2. The middle position (at index 'n') should be the empty space ('_')
    // 3. The last 'n' positions should contain Red marbles ('R')
    
    // Check if first 'n' positions are Green marbles ('G')
    for (int i = 0; i < n; i++) {
        if (board[i] != 'G') return false;
    }

    // Check if the middle position is empty ('_')
    if (board[n] != '_') return false;

    // Check if the last 'n' positions are Red marbles ('R')
    for (int i = n + 1; i < 2 * n + 1; i++) {
        if (board[i] != 'R') return false;
    }

    // If all conditions are met, the puzzle is solved
    return true;
}

// Backtracking function to solve the puzzle
bool solvePuzzle(char board[], int n, int emptyPos) {
    // This function uses backtracking to solve the puzzle.
    // It explores different moves (moving 'R' to the right and 'G' to the left) and backtracks if a move doesn't lead to a solution.

    // Print the current state of the board
    printBoard(board, 2 * n + 1);
    
    // Check if the current board configuration is the solution
    if (isSolved(board, n)) {
        // If the puzzle is solved, return true
        return true;
    }

    // Try moving Red marbles ('R') to the right
    if (emptyPos > 0 && board[emptyPos - 1] == 'R') {
        // Move 'R' right by 1 step
        board[emptyPos] = 'R';
        board[emptyPos - 1] = '_';
        
        // Recursive call to try solving the puzzle after the move
        if (solvePuzzle(board, n, emptyPos - 1)) return true;
        
        // Backtrack: undo the move
        board[emptyPos] = '_';
        board[emptyPos - 1] = 'R';
    }

    if (emptyPos > 1 && board[emptyPos - 2] == 'R') {
        // Jump 'R' over 1 step to the right
        board[emptyPos] = 'R';
        board[emptyPos - 2] = '_';
        
        // Recursive call to try solving the puzzle after the move
        if (solvePuzzle(board, n, emptyPos - 2)) return true;
        
        // Backtrack: undo the move
        board[emptyPos] = '_';
        board[emptyPos - 2] = 'R';
    }

    // Try moving Green marbles ('G') to the left
    if (emptyPos < 2 * n && board[emptyPos + 1] == 'G') {
        // Move 'G' left by 1 step
        board[emptyPos] = 'G';
        board[emptyPos + 1] = '_';
        
        // Recursive call to try solving the puzzle after the move
        if (solvePuzzle(board, n, emptyPos + 1)) return true;
        
        // Backtrack: undo the move
        board[emptyPos] = '_';
        board[emptyPos + 1] = 'G';
    }

    if (emptyPos < 2 * n - 1 && board[emptyPos + 2] == 'G') {
        // Jump 'G' over 1 step to the left
        board[emptyPos] = 'G';
        board[emptyPos + 2] = '_';
        
        // Recursive call to try solving the puzzle after the move
        if (solvePuzzle(board, n, emptyPos + 2)) return true;
        
        // Backtrack: undo the move
        board[emptyPos] = '_';
        board[emptyPos + 2] = 'G';
    }

    // No valid move found, return false to backtrack further
    return false;
}

int main() {
    int n;
    cout << "Enter the number of Red and Green marbles (n): ";
    cin >> n;

    // Create a board of size 2*n + 1 (n Red marbles, 1 empty space, n Green marbles)
    int boardSize = 2 * n + 1;
    char board[boardSize];

    // Initialize the board:
    // 1. Place Red marbles ('R') on the left
    for (int i = 0; i < n; i++) {
        board[i] = 'R';
    }

    // 2. Place the empty space ('_') in the middle
    board[n] = '_';

    // 3. Place Green marbles ('G') on the right
    for (int i = n + 1; i < boardSize; i++) {
        board[i] = 'G';
    }

    // Print the initial board configuration
    cout << "Initial board: ";
    printBoard(board, boardSize);

    // Start the backtracking process to solve the puzzle
    if (solvePuzzle(board, n, n)) {
        // If a solution is found, print success
        cout << "Puzzle solved!" << endl;
    } else {
        // If no solution is found, print failure
        cout << "No solution found." << endl;
    }

    return 0;
}
