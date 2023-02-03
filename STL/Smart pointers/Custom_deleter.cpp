// Sometimes we have to provide a specialized way
// of destroying smart pointers.
// Custom deleters are used in these cases.
// we can write a custom deleters using functions or lamdas


#include <iostream>
#include <memory>
using namespace std;

void my_deleter(int *p) {
    cout << "Custom deleter function used" << endl;
    delete p;
}

int main() {
    shared_ptr<int> ptr {new int(10), my_deleter}; 

    shared_ptr<float> p {new float(3.54), [] (float *ptr) {
        cout << "Custom deleted lambda used" << endl;
        delete ptr;
    }};
}