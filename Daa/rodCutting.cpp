#include<iostream>
#include<algorithm>

using namespace std;

int rodcut(int price[] , int n){
    
    int dp[n+1] = {0};

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= i; j++){
            dp[i] = max(dp[i] , dp[i-j]+price[j-1]);
        }
    } 

    return dp[n];
}

int main(){
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout<<"Max obtainable value : "<<rodcut(price,n);
}