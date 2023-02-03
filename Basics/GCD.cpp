#include <iostream>
using namespace std;

#define ll long long

int gcd (ll a, ll b) {

    if (a==0) {
        return b;
    }
    else if (b==0) {
        return a;
    }
    else if (a==b) {
        return a;
    }
    int mini = min(a,b);
    int ans = 1;
    for (int i=2; i<=mini/2; i++) {
        if (a%i==0 && b%i==0) {
            ans = i;
        }
    }
    if (a%mini==0 && b%mini==0) {
        ans = mini;
    }
    return ans;
}

int euclid_gcd(ll a, ll b) {
    if (b==0) {
        return a;
    }
    return euclid_gcd(b, a%b);
}

int main() {
    ll a, b;
    cin >> a >> b;
    // cout << gcd(a,b) << " ";
    cout << euclid_gcd(a,b) <<" ";
    cout << endl;
    
}
