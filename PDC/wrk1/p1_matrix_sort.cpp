#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<algorithm>

using namespace std;

// Mutex for synchronizing access to the matrix
mutex mtx;

void RowSort(vector<vector<int>> & mat){

    lock_guard<mutex> lock(mtx);

    // Sort even indexed rows in ascending order and odd indexed rows in descending order
    for(int i = 0 ; i < mat.size(); i++){
        if( i % 2 == 0){
            sort(mat[i].begin(), mat[i].end());
        } else {
            sort(mat[i].rbegin(), mat[i].rend());
        }
    }
}

void columnSort(vector<vector<int>> & mat){

    lock_guard<mutex> lock(mtx);

    int n = mat.size();
    int m = mat[0].size();

    // Sort each column in ascending order
    for(int i = 0; i < m; i++){

        vector<int> col;
        
        for(int j = 0 ; j < n; j++){
            col.push_back(mat[j][i]);
        }
        sort(col.begin(), col.end());

        for(int j = 0 ; j < n; j++){
            mat[j][i] = col[j];
        }
    }
}

void printMatrix(const vector<vector<int>> &mat){
    
    // Print the matrix
    for(const auto &row : mat){
        for(const auto & elem : row){
            cout << elem << " ";
        }
        cout << endl;   
    }
}

   int main(){
    
    // initial matrix
    vector<vector<int>> matrix = {
        {45, 7, 9, 35},
        {12, 85, 16, 3},
        {40, 20, 72, 88},
        {55, 78, 69, 77}
    };
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    
   while(true){

        // Store previous state of the matrix to check for stabilization
        vector<vector<int>> prev = matrix;
        
        // Create and join threads for row and column sorting
        thread rowThread(RowSort, ref(matrix));
        rowThread.join();
        cout << "After Row Sort:" << endl;
        printMatrix(matrix);

        // Create and join thread for column sorting
        thread colThread(columnSort, ref(matrix));
        colThread.join();
        cout << "After Column Sort:" << endl;
        printMatrix(matrix);

        // Check for stabilization
        if(prev == matrix){
            cout << "Matrix stabilized. Exiting sorting loop." << endl;
            break;
        }
    }
    
    return 0;
    
}
