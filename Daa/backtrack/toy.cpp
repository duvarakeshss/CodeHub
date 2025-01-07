#include <iostream>
#include <algorithm>

using namespace std;

int min_toys_to_buy(int toys[], int n) {
    // Sort the array of toy weights
    sort(toys, toys + n);
    
    int num_buys = 0;
    int i = 0;
    
    while (i < n) {
        // Buy the toy with weight toys[i]
        num_buys++;
        cout<<i;
        // Find the range [toys[i], toys[i] + 4]
        int j = i;
        while (j < n && toys[j] <= toys[i] + 4) {
            j++;
        }
        // Move to the next uncovered toy
        i = j;
      
    }
    
    return num_buys;
}

int main() {
    // Input
    int toys[] = {1, 2, 3, 17, 10};
    int n = sizeof(toys) / sizeof(toys[0]);

    // Output
    cout << min_toys_to_buy(toys, n) << endl;

    return 0;
}
