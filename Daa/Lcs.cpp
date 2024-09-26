#include<iostream>
#include<algorithm>

using namespace std;

void lcs(char x[] , char y[] , int m , int n){

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
    int m, n;
    
    cout << "Enter no. of characters in 1st word: ";
    cin >> n;
    char x[n];
    cout << "Enter the word: ";
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter no. of characters in 2nd word: ";
    cin >> m;
    char y[m];
    cout << "Enter the word: ";
    for(int i = 0; i < m; i++) {
        cin >> y[i];
    }

    lcs(x,y,n,m);
}
