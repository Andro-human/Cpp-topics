// forward_list (is basically singly linked list)
// less overhead than list


#include <iostream>
#include <forward_list>
#include <algorithm>
#include <iterator>         //std::advance() 
using namespace std;

int main() {
    forward_list<int> fl {1,2,3,4,5};

    cout << fl.max_size() << endl;          // a very large number
    cout << fl.front() << endl;      

    fl.push_front(0);         // add 0 to the front
    fl.pop_front();
    fl.emplace_front(10);

    forward_list<int> l {1,2,3,4,5};
    auto it = find(l.begin(), l.end(), 3);

    l.insert_after(it, 10);
    l.emplace_after(it,100);
    l.erase_after(it);
    l.resize(2);            // 1 2  -- iterator become invalid
    l.resize(5);            // 1 2 0 0 0

    it = find(l.begin(), l.end(), 2);
    cout << *it << endl;

    advance(it, 2);             // increments or decrements an iterator
    cout << *it << endl;


}