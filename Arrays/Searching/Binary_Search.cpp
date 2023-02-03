// TIME COMPLEXITY O(log n)


#include <iostream>
using namespace std;

int Binary_Search(int *arr, int n, int key) {
    
    int s = 0;
    int e = n-1;
    while (s <= e) {
        int mid = (s+e)/2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            e = mid-1;
        }
        else {
            s = mid+1;
        } 
    }
    return -1;
     
} 

int recur_binary_search(int *arr, int start, int end, int key) {
    if (start > end) {
        return -1;
    }
    
    int mid = (start+end)/2;
    
    if (arr[mid] == key) {
        return mid;
    }
    else if (arr[mid] > key) {
        return recur_binary_search(arr,start, mid-1, key);
    }
    else
        return recur_binary_search(arr, mid+1, end, key);   
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

    int ans = Binary_Search(arr, n, key);
    if (ans == -1) {
        cout << "NOT FOUND";
    }
    else 
        cout << ans;
}
