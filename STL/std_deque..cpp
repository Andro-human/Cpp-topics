// can expend as needed
// not stored in contiguous memory
// allow rapid insertion at front and back

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    deque<int> d {1,2,3,4,5};
    deque<int> d1 (10,100);     //ten 100s
    d.push_front(0);
    d.push_back(10);
    d.pop_front();
    d.pop_back();

    d.clear();      //clears the whole array

    deque<string>d2;
    d2.emplace_back("Hello");
    d2.emplace_front("MOE");

    vector<int>vec {10,20,30};
    copy(vec.begin(), vec.end(), front_inserter(d));

    copy(vec.begin(), vec.end(), back_inserter(d));
}
