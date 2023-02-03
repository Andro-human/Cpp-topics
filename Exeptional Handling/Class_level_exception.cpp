// Here we are throwing exception from constructor


#include <iostream>
using namespace std;

class illegalbalanceexception {
};

class Account {
    int balance;
    public:
    Account() = default;
    Account(int n) 
    :balance{n} {
        if (balance < 0) {
            throw illegalbalanceexception();
        }
    }
};

int main() {
    try {
        Account a (-10);
    }  

    catch (illegalbalanceexception &ex) {
        cerr << "Couldn't create account" << endl;
    }
}
