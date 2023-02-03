#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long


void print(vector<vector<char>> vec) {
    for (auto &v: vec) {
        for (auto &elem: v) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

bool is_safe(vector<vector<char>> &vec, int row, int col) {
    for (int i = row, j = col; i>=0 && j>=0; i--,j--) {
        if (vec[i][j] == 'q') {
            return false;
        }
    }
    for (int i = row, j = col; i>=0 and j<vec.size(); i--,j++) {
        if (vec[i][j] == 'q') {
            return false;
        }
    }
    for (int i=row; i>=0; i--) {
        if (vec[i][col] == 'q') {
            return false;
        }
    }
    return true;
}

int n_queens(vector<vector<char>> &board, int n,int row) {
    
    if (row == n) {
        print(board);
        return 1;
    }
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (is_safe(board,row,i)) {
            board[row][i] = 'q';
            ans += n_queens(board, n, row+1);

            board[row][i] = '-';
            // ans += n_queens(board,)
        }
    }

    return ans;

}

int main() {
    int n;
    cin >> n;

    vector <vector <char>> board (n, vector<char> (n, '-'));

    int ans = n_queens(board, n, 0);

    cout << "Total Solutions -> " << ans;
    // print(board);
}