#include<iostream>
#include <algorithm>
using namespace std;

int main(){

    int w = 26; // Knapsack capacity
    int n = 5;  // Number of items
    int wieght[] = {12, 7, 11, 8, 9};
    int profit[] = {24, 13, 23, 15, 16};




    int arr[n+1][w+1];

    for(int i = 0 ; i <= n ; i++){
        arr[i][0] = 0;
    }

    for (size_t i = 0; i <= w; i++)
    {
        arr[0][i] = 0;
    }

    for(int i = 1 ; i <=n ; i++){
        for(int j = 0 ; j <= w ; j++){
            if(wieght[i-1] <= j){
                
                arr[i][j] = max((arr[i-1][j]),(arr[i-1][j-wieght[i-1]]+profit[i-1]));
            }
            else{
                arr[i][j] = arr[i-1][j];
            }
            
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;

    cout<<"Max profit : "<<arr[n][w]<<endl;
    cout<<"Item included : ";
    int w_item = w;
    for(int i = n ; i > 0 && w_item > 0 ; i--){
        if(arr[i][w_item] != arr[i-1][w_item]){
            cout<<" "<<i - 1;
            w_item -= wieght[i-1];
        }
        
    }
    cout<<endl;


}