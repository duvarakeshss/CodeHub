#include<iostream>
using namespace std;

int frog_jump(int arr[] , int n){

    int dp[n+1][n+1] = {0};

    dp[0][0] = 1;
    int jump = 0;

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            
            jump = arr[i] - arr[j];

            if( jump > 0 && jump < n && (dp[j][jump] == 1 || dp[j][jump-1] == 1 || ( jump+1 < n && dp[j][jump+1] == 1))){
                dp[i][jump] = 1;
            }

        }    
    }
    for (int j = 1; j < n; j++) {
        if (dp[n-1][j] == 1) {
            return 1;
        }
    }

    return 0;

}

int main(){
        int stones1[] = {0,1,3,5,6,8,12,17};
    int n1 = 8;
    cout << "Can the frog cross eg1 ? : " << (frog_jump(stones1, n1) ? "Yes" : "No") << endl;


    int stones2[] = {0, 1, 2, 3, 4, 8, 9, 11};
    int n2 = 8 ;
    cout << "Can the frog cross  eg2 : " << (frog_jump(stones2, n2) ? "Yes" : "No") << endl;

}