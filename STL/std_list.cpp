// list (is basically a doubly linked list)
// they dont provide direct access to element via the [] or .at method
// but they are very efficient when we need to insert and delete element in the list once an element is found 


#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list <int> l {1,2,3,4,5};
    list <int> ll (10,100);         //ten 100s
    l = {2,4,6,8,10};

    cout << l.size() << endl;
    cout << l.max_size() << endl;       //a very large number
    cout << l.front() << endl;
    cout << l.back() << endl;

    l.push_back(100);
    l.pop_back();

    l.push_front(1);
    l.pop_front();

    l.emplace_back(10);           // add to back efficiently
    l.emplace_front(100);         // add to front efficiently

    list<int> li {1,2,3,4,5};
    list<int> ::iterator it = find(li.begin(), li.end(), 3);
    
    li.insert(it,10);
    li.erase(it);
    li.resize(2);       // 1 2
    li.resize(5);       // 1 2 0 0 0

}