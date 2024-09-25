#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n = 9;
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int dp[n+1];
    dp[0] = arr[0];

    int maxi = dp[0];

    for(int i =1 ; i < n ; i++){
        dp[i] = max(dp[i-1]+arr[i] , arr[i]);
        maxi = max(maxi,dp[i]);
    }

    cout<<maxi;

}