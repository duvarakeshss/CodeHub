#include<iostream>
using namespace std;

bool isSubset(int A[] , int n ,int s , int subs[] , int &index){
    if(s==0) return true;
    if(n==0) return false;

    if(A[n-1] > s){
        return isSubset(A,n-1,s,subs,index);
    }

    if(isSubset(A,n-1,s-A[n-1],subs,index)){
        subs[index++]=A[n-1];
        return true;
    }

    return isSubset(A,n-1,s,subs,index);
}

void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {1, 2, 7, 3};
    int S = 6;  
    int n = 4;

    int subs[10]; 
    int Index = 0; 

    
    if (isSubset(A, n, S, subs, Index)) {
        cout << "True, subset exists: ";
        printSubset(subs, Index); 
    } else {
        cout << "False, no subset exists." << endl;
    }

    return 0;
}