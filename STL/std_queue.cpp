// queue
// First-in First-out (FIFO) data structure
// implemented as an adapater over other STL container
// Elements are pushed at the back and popped at the front
// No iterators are supported

#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main() {
    queue<int> q;           // implemented as deque by default
    queue<int, list<int>> q2;    // implemented as list

    q.push(10);     // 10
    q.push(20);     // 20 10
    q.push(30);     // 30 20 10

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();        // 30 20  - removes 10
    q.pop();        // 30   - removes 20

    cout << q.size() << endl;           //1

    for (int i: {10,20,30,40,50}) {
        q2.push(i);
    }

    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }
}