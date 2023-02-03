

#include <iostream>
using namespace std;

void solve(int n, int *arr) 
{
    int count = 0;
    for (int i=0; i<n; i++) {
        count = count^arr[i];
    }
    cout << count << endl;
}


int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    solve(n, arr);

}
