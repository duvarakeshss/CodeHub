#include<iostream>
#include<vector>
#include<algorithm>
#include<thread>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}



void mergeSort(vector<int> &arr , int left, int right){

    if(left >= right){
        return;
    }
    int mid = left + (right - left) / 2;
    thread t1(mergeSort, ref(arr), left, mid);
    thread t2(mergeSort, ref(arr), mid + 1, right);
    t1.join();
    t2.join();
    merge(arr, left, mid, right);
}

int main(){

    vector<int> arr = { 10, 49, 9, 34, 32, 37, 37, 48, 45, 19,
                        5, 31, 20, 19, 29, 22, 45, 30, 40, 31,
                        35, 8, 36, 39, 14
                    };

    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}