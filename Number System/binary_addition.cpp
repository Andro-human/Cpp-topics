#include <iostream>
#include <algorithm>
using namespace std;

void binary_add(int *arr1, int n1, int *arr2, int n2)
{
    int idx = 0;
    int max_len = max(n1, n2);

    int ans[max_len + 1]{};
    int carry = 0;

    while (idx <= max_len)
    {
        if (idx < n1)
            carry += arr1[idx];
        if (idx < n2)
            carry += arr2[idx];

        ans[idx++] = carry % 2;
        carry /= 2;
    }

    reverse(ans, ans + max_len + 1);

     for (int i=0; i<= max_len; i++) {
         cout << ans[i];
     }
    
}

int main() {
    int n,m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for (int i=0; i<n; i++) {
        cin >> arr1[i];
    }
    for (int i=0; i<m; i++) {
        cin >> arr2[i];
    }

    reverse(arr1, arr1+n);
    reverse(arr2, arr2+m);

    binary_add(arr1,n,arr2,m);
}
