#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<algorithm>

using namespace std;
mutex mtx;

void RowSort(vector<vector<int>> & mat){

    lock_guard<mutex> lock(mtx);

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
    for(const auto &row : mat){
        for(const auto & elem : row){
            cout << elem << " ";
        }
        cout << endl;   
    }
}

   int main(){
    
    vector<vector<int>> matrix = {
        {45, 7, 9, 35},
        {12, 85, 16, 3},
        {40, 20, 72, 88},
        {55, 78, 69, 77}
    };
    
    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    
   while(true){

        vector<vector<int>> prev = matrix;
        
        thread rowThread(RowSort, ref(matrix));
        rowThread.join();
        cout << "After Row Sort:" << endl;
        printMatrix(matrix);

        thread colThread(columnSort, ref(matrix));
        colThread.join();
        cout << "After Column Sort:" << endl;
        printMatrix(matrix);
        if(prev == matrix){
            cout << "Matrix stabilized. Exiting sorting loop." << endl;
            break;
        }
    }
    
    return 0;
    
}
