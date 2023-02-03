#include <iostream>
using namespace std;

// function template
template <typename T, typename T1>
void MAX (T a, T1 b) {
   cout << a << endl;
   cout << b << endl;
}

//Class template
template <typename T2, typename T3>
class My_Pair{
    public:
    T2 first;
    T3 second;
};

int main() {
    int a = 20;
    double b = 20.35;
    MAX<int, double>(a,b);

    My_Pair <int,float> ani;
    ani.first = 10;
    ani.second = 20.03;
    cout << ani.first << "  ||  " << ani.second << endl;
}
