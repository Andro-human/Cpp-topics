// TIME COMPLEXITY O(n)

#include <iostream>
using namespace std;

int linearSearch (int *arr, int n, int key) {
    
    for (int i=0; i<n; i++) {
        if (arr[i] == key) {
            return i;
        }
    } 
    return -1; 
}

int recur_linear_search(int *arr, int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    if (arr[low] == key) {
        return low;
    }
    return recur_linear_search(arr, low+1, high, key);
}
int main() {
    int n;
    cin >> n;
    int arr[n];  
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    int ans = linearSearch(arr, n, key);
    if (ans == -1) {
        cout << "NOT FOUND";
    }
    else cout << ans;

}
