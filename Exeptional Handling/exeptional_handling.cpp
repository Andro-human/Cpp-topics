#include <iostream>
using namespace std;


class string_excep {           // here we are creating exception classes
};

void func() {
    cout << "YESS!" << endl;
    throw 100;
    cout << "NO" << endl; 
}

void func2() {
    cout << "func 2 called" << endl;
    throw string_excep();       // here we are throwing that exception class object
    cout << "DONE" << endl;
}

int main() {
    cout << "Starting" << endl;
    try {
        func();
    }   
    catch (int &ex) {
        cerr << "CATCHing!!" << endl;
    }

    try {
        func2();
    }

    catch (const string_excep &ex) {
        cerr << "Caught string exception" << endl;
    }
    catch (...) {  // catches all type of data but you wont be able to access it
        cerr << "Unknown error" << endl;
    }
    cout << "SIGNING OFF!" << endl;
}
