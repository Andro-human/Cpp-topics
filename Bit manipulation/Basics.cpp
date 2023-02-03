#include <iostream>
using namespace std;

void get_bit (int n, int pos) {                 // get the bit at the given position
    cout << ((n & (1<<pos))?1:0) << endl;
}

void change_bit (int n, int pos) {      // changes (1 to 0) & (0 to 1)
    cout << (n ^ (1<<pos)) << endl;
}

void set_bit (int n, int pos) {         // change (1 to 0)
    cout << (n | (1<<pos)) << endl;
}

void clear_bit (int n, int pos) {       // change (0 to 1)
    cout << (n & (~(1<<pos))) << endl;
}

int updatebit (int n , int pos , int value) {            // update bit to the given bit
    n = (n & ~(1<<pos));
    return n | (value<<pos);
}

int main() {
    int n, pos;
    cin >> n >> pos;
    
    get_bit(n, pos);
    change_bit(n, pos);
    set_bit(n, pos);
    clear_bit(n, pos);
    cout << updatebit (5,3,1) << endl;
