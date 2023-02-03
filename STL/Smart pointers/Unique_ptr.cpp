// Unique pointers cannot be assigned or copied
// moving is allowed
// deletes automatically


#include <iostream>
#include <memory>
#include <vector>
using namespace std;
int main() {
    unique_ptr<int> ptr {new int {100}};
    cout << *ptr << endl;
    cout << ptr.get() << endl;      // to get the address of the data
    ptr.reset(); // ptr is now nullptr

    unique_ptr<float> p = make_unique<float>(10.32);    // better way to initialize
    cout << *p;

    unique_ptr<double>p1 = make_unique<double>(90.1);
    vector<unique_ptr<double>> vec;
    // vec.push_back(p1);   // Not allowed since we can't copy a unique pointer

    vec.push_back(move(p1));    //moving is allowed
}
