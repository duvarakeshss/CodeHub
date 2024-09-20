#include<iostream>
using namespace std;

int main(){
    int coins[] = {1,2,5};
    int n = 3;
    int amount = 11;

    int dp[amount+1];

    for(int i = 0 ; i < amount+1;i++){
        dp[i] = amount+1;
    }
    dp[0] = 0;
    for(int i = 1 ; i <= amount ; i++ ){
        for(int j = 0 ; j < n ; j++){
            if(coins[j] <= i){
                dp[i] = min(dp[i] , dp[i-coins[j]]+1);
            }
        }
    }

    if(dp[amount] > amount)
        cout<<"-1";
    else
        cout<<dp[amount];


}