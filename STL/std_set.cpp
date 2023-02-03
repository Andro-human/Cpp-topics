// set is similar to a mathematical set
// ordered by key
// no duplicates are allowed


// multiset - a multiset is a set ordered by key but allows duplicate elements

// unordered_set <unordered_set> - an unordered set is a set that is unordered but does not allow duplicate elements
// unordered_multiset - an unordered_multiset does not order elements and allow duplicates.


// NOTE- in the case of class obejcts, overloaded < operator is used to order elements

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s {1,2,3,4,5};
    s = {4,1,1,3,3,2,5};
    for (auto &i:s) {
        cout << i << " ";
    }

    cout << endl << s.size() << endl;
    cout << s.max_size() << endl;

    // no concept of front or back

    s.insert(7);
    s.erase (3);    //erase the 3
    auto it = s.find(4);
    if (it != s.end()) {
        s.erase(it);            // erase the 4
    }
    
    int num = s.count(1);       // 0 or 1
    s.clear();          // remove all elements
    cout << s.empty() << endl;          // true or false;


    auto result = s.insert(10);         // returns a pair
    cout << boolalpha;
    cout << *result.first << endl;      // here first is an iterator to the 10 we inserted or the 10 that was already there
    cout << result.second << endl;      // second is a boolean which indicates if the insertion was successful

}