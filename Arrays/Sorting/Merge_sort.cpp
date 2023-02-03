#include <iostream>
using namespace std;

int merge (int *arr, int l, int mid, int h) {
    int i=l, j=mid+1, k=l;
    int B[h+1];

    while (i <= mid && j <= h) {
        if (arr[i] < arr[j]) {
            B[k++] = A[i++];
        }
        else
            B[k++] = A[j++];
    }
    for (; i<=mid; i++) {
        B[k++] = A[i];
    }
    for (; j<=h; j++) {
        B[k++] = A[j];
    }

    for (int i=l; i<h; i++) {
        A[i] = B[i];
    }
}

void IMerge_sort(int *arr, int n) {
    int p,l,h,mid,i;

    for (int p=2; i<n; p*=2) {
        for (int i=0; i+p-1<n; i+=p) {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(arr,l,mid,h);
        }
    }
    if (p/2<n) {
        Merge(arr, 0, p/2-1, n);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Merge_sort(arr, n)
}