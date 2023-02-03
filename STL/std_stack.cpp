// stack
// Last in First out (LIFO) data structure
// Implemented as an adapter over other container
// All operations occuro n one end of the stack (top)
// no iterators are supported

#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

int main() {
    stack<int>s;            // implemented as deque by default
    stack<int, vector<int>> s1;     // vector
    stack <int, list<int>> s2;      // list

    s.push(10);     // 10
    s.push(20);     // 10 20
    s.push(30);     // 10 20 30

    cout << s.top() << endl;

    s.pop();     // 30 is removed
    s.pop();     // 20 is removed
    cout << s.size() << endl;       //1

    for (int i: {10,20,30,40,50}) {
        s1.push(i);
    }

    while (!s1.empty()) {               // display
        cout << s1.top() << " ";        // destructive process
        s1.pop();                       // s1 is destroyed
    }
    cout << endl; 
}
