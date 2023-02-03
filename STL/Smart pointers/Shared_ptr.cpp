// Shared pointers can be shared among many shared ptrs.
// can be assigned and copied
// deletes automatically


#include <iostream>
#include <memory>
#include <vector>
using namespace std;
int main() {
    shared_ptr<int> ptr {new int {100}};
    cout << *ptr << endl;
    *ptr = 200;
    cout << *ptr << endl;

    shared_ptr<int> p {ptr};      // shared ownership
    cout << ptr.use_count() << endl;

    cout << ptr.get() << endl;      // to get the address of the data

    ptr.reset(); // decrement the use count, ptr is nulled out
    cout << ptr.use_count() << endl;
    cout << p.use_count() << endl;

    vector<shared_ptr<int>> vec;
    vec.push_back(p);   // ok - copy is allowed
    cout << p.use_count() << endl;


    shared_ptr<double>p1 = make_shared<double>(90.1);   // better way to initialize
    
}
