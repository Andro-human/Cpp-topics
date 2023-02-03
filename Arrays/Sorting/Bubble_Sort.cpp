// TIME COMPLEXITY O(n^2)

#include <iostream>
using namespace std;

void bubble_sort(int *arr, int n) {

    bool flag;
    for (int i=1; i<n; i++) {
        flag = false;
        for (int j=0; j<n-i;j++) {
            if (arr[j+1] < arr[j]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                flag = true;
            }
        }

        if (flag == false) {
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }   

    bubble_sort(arr, n);
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }   

    
}
