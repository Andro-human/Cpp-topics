
// Hash-map {similar to a dictionary}
// elements stored as key, value pairs (std::pair)
// ordered by key
// no duplicate keys
// direct element access using the key
// all iterators available and invalidate when corresponding element is deleted


// Multimap - ordered by key but allows duplicate elements (key)

// unordered_map <unordered_map> - unordered map is a map thats unordered
                    // does not allow reverse iterators
// unordered_multimap - does not order elements and does allow duplicates
                    // no reverse iterators allowed

#include <iostream>
#include <map>
using namespace std;

int main() {
    map <string, int> m {
        {"Larry", 18},
        {"Moe", 25}
    };

    cout << m.size() << endl;           //2
    cout << m.max_size() << endl;       // a very large number

    // no concept of front and back

    pair <string,int> p1 {"Curly", 32};
    m.insert(p1);

    m.insert(make_pair("Tony", 8));     // efficient way to insert

    m["Maddy"] = 45;        // insert
    m["Maddy"] = 17;        //update value
    m.at("Maddy") = 33;     //update value

    m.erase("Moe");         //erase Moe

    if (m.find("Larry") != m.end())
            cout << "Found Larry" << endl;
    auto it = m.find("Maddy");
    if (it != m.end()) {
        m.erase(it);        // erase maddy
    }

    for (auto &i:m) {
        cout << i.first << " ";
        cout << i.second << endl;
    }

    int num = m.count("Curly");     // 0 or 1
    m.clear();              // remove all elements
    cout << m.empty();      // true or false
}