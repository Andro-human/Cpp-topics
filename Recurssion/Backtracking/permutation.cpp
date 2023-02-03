#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

vector<int> temp;

vector<bool> status;

void print (vector <vector<int>> &v) {
    for (auto row: v) {
        for (auto colm: row) {
            cout << colm << " ";
        }
        cout << endl;
    }
}

void permutations(vector <int> &nums, vector<vector<int>> &result, int counter) {

    if (counter == nums.size()) {
        result.push_back(temp);
    }

    // temp[counter++];
    for (int i=0; i<nums.size(); i++) {
        if (status[i] == false) {
            temp.push_back(nums[i]);
            status[i] = true;
            permutations(nums, result, counter+1);
            
            temp.pop_back();
            status[i] = false;
        }
    }
    



}

int main() {
    int n;
    cin >> n;


    vector <int> nums;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    status.resize(n, false);

    vector <vector <int>> result;

    permutations(nums, result, 0);

    print(result);
}