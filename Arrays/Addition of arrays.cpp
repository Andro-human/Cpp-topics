#include <iostream>
using namespace std;

void input(int *arr, int size) {
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
}

void output(int *arr, int size) {
    for (int i=0; i<size; i++) {
        cout << arr[i];
    }
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1];
    int arr2[n2];

    input(arr1, n1);
    input(arr2, n2);

    int size = max(n1, n2);
    int sum[size+1] {};
    int counter = 0;
    int carry = 0;
    while (size--) {
        int add = carry;
        if (counter < n1) add +=  arr1[counter];
        if (counter < n2) add += arr2[counter];
        int res = add%10;
        carry = add/10;
        sum[counter++] = res;
    }

    if (carry) sum[counter++] += carry;

    output(sum, counter);

}
