// Here we are inheriting an Account class from a Savings class.
// The account class attributes balance & name is inherited to the savings class.
// Moreover we are also inheriting the withdrawal method here as we have not 
// provided our own specialized withdrawal method.
// While the deposit method of account is not getting inherited
// because we have provided our own.




#include <iostream>
#include <string>
using namespace std;

class Account {

// Protected acts as Private for main body but in Inheritance we can't access private attributes 
// therefore we use protected. Protected contents are inherited as private in savings body

// NOTE: Private attributes are inherited, we just can't access it
protected:
    double balance;
    std::string name;
public:
    void deposit(double amount);
    void withdraw(double amount);
    Account();
    ~Account();
};

Account::Account()  
    :  balance{0.0}, name{"An Account"} {
}

Account::~Account() {}

void Account::deposit(double amount) {
    std::cout << "Account deposit called with " << amount  << std::endl;
    balance += amount;
    cout << "Current balance is : " << balance << endl;
}

void Account::withdraw(double amount) {
    std::cout << "Account withdraw called with " << amount << std::endl;
    if (balance - amount >= 0) {
        balance -= amount;
        cout << "Updated balance is : " << balance << endl; 
    } 
    else 
        cout << "Insufficient balance" << endl;
}

// Here we are using public inheritance
class Savings_Account: public Account {
protected:
    double int_rate = 3.0;
public:
    Savings_Account();
    ~Savings_Account();
    void deposit(double amount);

    // we dont need a specialized withdrawal method here
    // void withdraw(double amount);
};

// We are using default constructor for Savings account;
Savings_Account::Savings_Account() = default;

Savings_Account::~Savings_Account() {}

void Savings_Account::deposit(double amount) {
    std::cout << "Savings Account deposit called with " << amount << std::endl;
    balance += amount + amount*(int_rate/100);
    cout << "Updated balance is : " << balance << endl;
}




int main() { 
    
    // Use the Account class
    cout << "\n=== Account ==================================" << endl;
    Account acc {};
    acc.deposit(2000.0);               
    acc.withdraw(2001.0);
    
    cout << endl;
    
    // Dynamic memory allocation
    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

// Use the Savings Account class
    
    cout << "\n=== Savings Account ==========================" << endl;
    Savings_Account sav_acc {};
    sav_acc.deposit(2000.0);               
    sav_acc.withdraw(500.0);
    
    cout << endl;
    
    Savings_Account *p_sav_acc {nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;

    cout << "\n==============================================" << endl;
    return 0;
}