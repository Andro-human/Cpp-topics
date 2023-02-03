// priority_queue
// allow insertions and removal of elements in order from the front of the container
// elements are inserted in priority order
    //(largest value will always be at the front)
// no iterators are supported


#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;         //vector

    pq.push(10);
    pq.push(20);
    pq.push(3);
    pq.push(4);

    cout << pq.top() << endl;       // 20 (largest)
    pq.pop();                 // remove 20
    cout << pq.top() << endl;       // 10 (largest)

    for (int i: {100,13,67,87,45,7}) {
        pq.push(i);
    }

    while (!pq.empty()) {
        cout << pq.top() << " ";            // destructive type
        pq.pop();
    }
}