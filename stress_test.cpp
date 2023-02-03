// This is an implementation of stress test on maximum pairwise product question


#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll max_pair_product(int n, vector<int> &v) {
    ll res = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if ((ll)v[i]*v[j] > res) {
                res = (ll)v[i]*v[j];
            }
        }
    }
    return res;
}

ll max_pair_product_fast(int n, vector<int> &v) {
    int max_ind = 0;
    for (int i=1; i<n; i++) {
        if (v[i] > v[max_ind]) {
            max_ind = i;
        }
    }

    int sec_max_ind;
    if (max_ind == 0) {
        sec_max_ind = 1;
    }
    else    
        sec_max_ind = 0;
    
    for (int i=0; i<n; i++) {
        if (v[i] > v[sec_max_ind] && i != max_ind ) {
            sec_max_ind = i;
        } 
    }
    
    return (ll)v[max_ind]*v[sec_max_ind];
}

int main() {
    while (true) { 
        int n = rand()%1000+2;              // input size to be determined as needed
        cout << n << endl;
    
        vector<int> v;
        for (int i=0; i<n; i++) {
            v.push_back(rand()%10 * 100000);            // values of the input - to be taken as needed
            cout << v[i] << " ";
        }
        cout << endl;

        ll res1 = max_pair_product(n, v);
        ll res2 = max_pair_product_fast(n,v);

        if (res1 == res2) {
            cout << "OK" << endl;
        }
        else {    
            cout << "WRONG ANSWER : " << res1 << " | " << res2 << endl;
            break;
        }
    }
}