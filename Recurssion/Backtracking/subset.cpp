#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

vector <int> temp;

void print(vector <vector <int>> &vec) {
    for (auto col: vec) {
        for (auto row: col) {
            cout << row << " ";
        }
        cout << endl;
    }
}

void subset (vector <int> v, vector<vector<int>> &result, int counter) {
    if (counter == v.size()) {
        result.push_back(temp);
        return;
    }

    temp.push_back(v[counter]);
    subset(v, result, counter+1);

    temp.pop_back();
    subset(v, result, counter+1);
}

int main() {

    int n;
    cin >> n;

    vector <int> v;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector <vector<int>> result;
    
    subset(v, result, 0);
    print(result);
}