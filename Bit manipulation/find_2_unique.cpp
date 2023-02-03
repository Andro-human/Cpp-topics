 #include <iostream>
using namespace std;

int get_bit (int i, int pos) {
    return (i & (1 << pos));
}

void solve (int n, int *arr) 
{
    int xor_sum = 0;
    for (int i=0; i<n; i++) {
        xor_sum ^= arr[i];
    }
    
    int num = 0;
    int pos = 0;

    int temp_xor = xor_sum;
    while (num!=1) {
        num = xor_sum & 1;
        pos++;
        xor_sum = xor_sum >> 1;
    }

    int new_xor = 0;
    for (int i=0; i<n; i++) {
        if (get_bit(arr[i], pos-1)) {
            new_xor = new_xor^arr[i];
        } 
    }

    cout << new_xor << endl;
    cout << (temp_xor^new_xor) << endl;
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
