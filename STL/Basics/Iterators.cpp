// there are also const_iterator & const_reverse_iterator
// they just can't change the value they are pointing too

#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector <int> vec {1,2,3};
    vector <int>::iterator it = vec.begin();
    //can also be written auto it = vec.begin();

    while (it != vec.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    auto r_it = vec.rbegin();     // reverse_iterator
    while (r_it != vec.rend()) {
        cout << *r_it << " ";
        r_it++;
    } 
    cout << endl;
}
