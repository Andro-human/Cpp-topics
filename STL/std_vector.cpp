// vector expand and contract as needed
// twice the amount of current storage is allocated when it runs out of space


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Account{
    int data;
    public:
    Account () = default;
    Account(int n) : data{n} {};
};

int main() {
    vector<int> vec {1,2,3,4,5};
    vector<int> vec1 (10,100);      //ten 100s
    vec1 = {2,4,6,8,10};
    
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    cout << vec.max_size() << endl;            // a very large number

    cout << vec.front() << " ";
    cout << vec.back() << endl;

    vec.push_back(20);          //add 20 in the back
    vec.pop_back();             //remove 20 from the back

    vector<Account> acc;
    acc.push_back(Account{20});
    acc.emplace_back(30);       //efficient!!


    cout << vec1.empty() << endl;      // 0 (false)
    // vec.swap(vec1);?

    sort(vec.begin(), vec.end());

    auto it = find(vec.begin(), vec.end(), 6);    //insertion of an element from any position
    vec.insert(it, 10);

    it = find(vec.begin(), vec.end(), 4);
    vec.insert(it, vec1.begin(), vec1.end());     //insertion of multiple elements from any position

    for (auto &v:vec) {
        cout << v << " ";
    }
    cout << endl;

    vec.shrink_to_fit();        //reduces the capacity
    vec.erase(it);          //deletes the element the iterator is pointing to
 
    //copy vec from beg to end to vec1 and back_inserter inserts a passed element to the back
    copy(vec.begin(), vec.end(), back_inserter(vec1));


}