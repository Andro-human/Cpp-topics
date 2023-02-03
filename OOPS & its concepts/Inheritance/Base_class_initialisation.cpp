// This is an example of Base class initialisation
// Here we have a value class and a doubled value class
// This shows how you can initialise the attributes of base
// class using from the derived class 


// What we have done here can also be done for copy/move constructor and 
// other overloaded operators. 
// Object 'Slicing' will take care of the constructor/operator type issue.


#include <iostream>
using namespace std;

class Value {
protected:
    int val;
public:
    Value(int x=0) : val{x} {
        cout << "ONE -args constructor called" << endl;
    }
    ~Value() {
        cout << "Destructor called" << endl;
    };

    void get_val() {
        cout << "value : " << val << "  |  ";
    }
};

class Double: public Value {
protected:
    int double_val;
public:
    Double(int x=0) : Value(x), double_val{x*2} {
        cout << "DOUBLED ONE-args consrtuctor called" << endl;
    }
    ~Double() {
        cout << "Doubled Destructor called" << endl;
    };
    void get_val() {
        Value::get_val();
        cout << "Doubled val : " << double_val << endl;
    }
};

int main() {
    // Value first;
    // Value second(10);
    // second.get_val();
    // cout << endl << endl;

    Double third(100);
    third.get_val();
    // Double fourth(100);
    // fourth.get_val();
}
