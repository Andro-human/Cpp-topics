// TIME COMPLEXITY O(n^2)

#include <iostream>
using namespace std;

void selection_sort(int *arr, int n) {

    for (int i=0; i<n-1; i++) {
        int j,k;
        for (j=k=i; j<n; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        int temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }   

    selection_sort(arr, n);
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }   

    
}
