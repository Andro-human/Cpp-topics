// An abstract class is a class which cannot be instantiated
// i.e its objects cannot be created

#include <iostream>

//This is an abstract class used as an interface
class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
    public:

    // virtual function
    virtual void print(std::ostream &os) const = 0; // =0 makes it an abstract class
    // virtual destructor (not needed here)
    virtual ~I_Printable() {}
};


std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

// this is also an abstract class since it is not implementing the virtual function
// 'correctly'. All the virtual functions must be implemented
class Account : public I_Printable {
    protected:
    std::string name;
    double balance;
    public:
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
     
     //override makes sure we are override the virtual function
     // and not modifying it.
     virtual void print(std::ostream &os) const override{
        os << "Checking display";
    }
    virtual ~Checking() {  }
};


class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    // here final is to prevent the virtual from overriding anymore down 
    // the hierarchy
     virtual void print(std::ostream &os) const override final {
        os << "Savings display";
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
     virtual void print(std::ostream &os) const override {
        os << "Trust display";
    }
    virtual ~Trust() {  }
};

class Dog : public I_Printable {
public:
  virtual void print(std::ostream &os) const override {
        os << "Woof woof";
    } 
};

void print(const I_Printable &obj) {
    std::cout << obj << std::endl;
}


int main() {
    
    Dog *dog = new Dog();
    std::cout << *dog<< std::endl;  
    
    print(*dog);
    
    Account *p1 = new Savings();
    std::cout << *p1<< std::endl;
        
    Account *p2 = new Checking();
    std::cout << *p2<< std::endl;  

    
        
    delete p1;
    delete p2;
    delete dog;
    return 0;
}
