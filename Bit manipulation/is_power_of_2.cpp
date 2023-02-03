#include <iostream>
using namespace std;

// void solve(int n) {
//     if (n == 0) {
//         cout << "Not a power of 2";
//     }
//     else if (n & n-1) {
//         cout << "Not a power of 2";
//     }
//     else 
//         cout << "Power of 2";
// }

bool solve(int n) {
    return (n && !(n & n-1));
}

int main() {
    int n;
    cin >> n;

    cout << boolalpha << solve(n);
}