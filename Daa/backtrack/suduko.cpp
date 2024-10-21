#include<iostream>
using namespace std;
#define n 9


void printGrid(int grid[n][n]) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isEmpty(int grid[n][n] , int &row ,int &col){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[n][n],int row , int col , int num){
    for(int i = 0 ; i < n; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(grid[i][col] == num){
            return false;
        }
    }

    return true;
}

bool isSolve(int grid[n][n]){
    int row,col;
    if(!isEmpty(grid,row,col)) return true;

    for(int i = 1 ; i <= n ; i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col] = i;
        
        
            if(isSolve(grid)) return true;
            grid[row][col] = 0;
        }


    }
    return false;
  
}

int main() {
     int grid[n][n] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (isSolve(grid)) {
        cout << "Solved Sudoku grid:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}