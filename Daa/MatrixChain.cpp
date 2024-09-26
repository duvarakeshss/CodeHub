#include<iostream>
#include<climits>

using namespace std;

int minMultiplication(int p[] , int n){
    int dp[n][n] = {0};
    
    int cost = 0;

    for(int l = 2 ; l < n ; l++){
        for(int i = 1 ; i < n - l + 1 ; i++){
            int j = i + l - 1;

            dp[i][j] = INT_MAX;

            for(int k = i ; k < j ; k++){
                cost = dp[i][k] + dp[k+1][j] + p[i - 1]* p[k] * p[j];
                dp[i][j] = min(dp[i][j],cost);
            }

            
        }
    }

    return dp[1][n-1];
}

int main(){
    int p[] = {1, 2, 3, 4};
    int n = 4;
    cout<<"Minimum Multiplication : "<<minMultiplication(p,n);
}