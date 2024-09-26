#include<iostream>
#include<algorithm>

using namespace std;

void lcs(string x , string y , int m , int n){

    int dp[m+1][n+1];
    
    for(int i = 0 ; i <= m ; i++){
        dp[i][0] = 0;
    }

    for(int i = 0  ; i <= n ; i++){
        dp[0][i] =  0 ; 
    }

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(x[i-1] != y[j-1]){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

            else{
                dp[i][j] = 1+dp[i-1][j-1];
            }
        }
    }

    cout<<"Matched length : "<<dp[m][n]<<endl;

    for(int i = 0 ;  i <= m ; i++){
        for(int j =  0 ; j <= n ; j++){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<"Matched Sequence :";

    int index = dp[m][n];
    char sq[index+1];
    sq[index] = '\0';
    int i = m , j = n;
    while( i > 0 && j > 0 ){
        if(x[i-1] == y[j-1]){
            sq[--index] = x[i-1];
            j--;
            i--;
        }
        else if(dp[i-1][j] > dp[i][j-1] ){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<sq;

}

int main(){
    string x;
    cout << "Enter word : ";
    cin>>x;
    int n = x.length();
    string y = x;
    reverse(y.begin(),y.end());    
    lcs(x,y,n,n);
}
