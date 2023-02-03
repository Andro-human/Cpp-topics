#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

void binary_to_dec(int n) {
    int dec = 0;    
    int counter = 0;
    while (n) {
        dec += n%10*(1<<counter);
        n/=10;
        counter++;
    }
    cout << dec << endl;
}

void octal_to_dec(int n) {
    int oct = 0;
    int counter = 0;
    while (n) {
        oct += n%10 * pow(8,counter);
        counter++;
        n/=10;
    }
    cout << oct << endl;
}

void hex_to_dec (string s) {
    int hex = 0;
    int counter = 0;
    for (int i=s.length()-1; i>=0; i--) {
        if (s[i] >= 'A' && s[i]<='F') {
            hex+= (s[i]-'A'+10)*pow(16,counter);
        }
        else {
            hex += (s[i]-'0')*pow(16,counter);
        }
        counter++;
    }
    cout << hex << endl;
}

void dec_to_binary(int n) {
    vector<int> v;
    while (n) {
        int binary = n%2;
        v.push_back(binary);
        n/=2;
    }
    reverse(begin(v), end(v));
    for (auto &i:v) {
        cout << i;
    }
}

void dec_to_oct(int n) {
    vector<int>v;
    while (n) {
        v.push_back(n%8);
        n /= 8;
    }
    for (auto &i:v) {
        cout << i;
    }
    cout << endl;
}

void dec_to_hex(int n) {
    string in_hex;

    while (n > 0)
    {
        int rem = n % 16;           // n & 15

        if (rem < 10)
            in_hex.push_back(rem + '0');
        else
            in_hex.push_back('A' + (rem - 10));
        n /= 16;    // n >>= 4;
    }

    reverse(begin(in_hex), end(in_hex));
    cout << in_hex << endl;
}

int main() 
{
    int n;
    cin >> n;
    // binary_to_dec(n);
    // octal_to_dec(n);
    // dec_to_binary(n);
    // dec_to_oct(n);
    // dec_to_hex(n);


    // string n;
    // cin >> n;
    // hex_to_dec(n);
}


