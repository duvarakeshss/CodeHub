#include<iostream>
#include<algorithm>

using namespace std;

void maxEarn(int l[] , int h[] , int n){
    
    int dp[n];
    dp[0] = l[0];

    if(n > 1){
        dp[1] = max(l[1]+dp[0] , h[1]);
    }

    for(int i = 2 ; i < n ; i++){
        dp[i] = max({
                l[i]+dp[i-1],
                dp[i-1],
                h[i] + dp[i-2]
        });
    }
    cout<<"Max Earning : "<<dp[n-1];
}

int main(){
    
    int l[] = {30, 5, 20, 25, 500}; 
    int h[] = {0,50, 70, 100, 110};    
    int n = 5 ; 

    maxEarn(l,h,n);
}