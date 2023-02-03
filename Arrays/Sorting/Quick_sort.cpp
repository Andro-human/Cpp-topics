// Time Complexity O(n^2)

#include <iostream>
#include <limits>
using namespace std;

int partition (int *arr, int l, int h) {
    int pivot = arr[l];
    int i=l,j=h;

    do {
        do {
            i++;
        } while (arr[i] <= pivot);

        do {
            j--;
        } while (arr[j] > pivot);
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i <= j);

    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void quick_sort (int *arr, int l, int h) {
    if (l < h) {
        int j = partition(arr, l, h);
        quick_sort(arr, l, j);
        quick_sort(arr, j+1, h);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n+1];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    arr[n] = INT_MAX;

    quick_sort(arr, 0, n);

    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

}