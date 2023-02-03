// std array is an object type
// Efficient than normal array  (element access in constant time )
// it is part of the stl so we can use it with iterators and algorithms


#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 5> arr {1,2,3,4,5};          //double {{}} if C++ 11
    array<int,5> arr2;
    arr2 = {10,20,30,40,50};

    cout << arr.size() << endl;
    cout << arr.at(0) << endl;
    cout << arr[1] << endl; 
    cout << arr.front() << endl;
    cout << arr.back() << endl;

    cout << arr.empty() << endl;    // will return true if the array is empty
    arr.fill(10);       // fills whole array with parameter
    arr.swap(arr2);
    int *data = arr.data();     // get raw array address

    for (auto &a: arr2) {
        cout << a << " ";
    }

}