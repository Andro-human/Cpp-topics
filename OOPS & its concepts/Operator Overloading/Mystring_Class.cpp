// This is operator overloading as Member functions
// We can overload operators using global functions as well by declaring
// it as a friend of the class or using getters.
// The only difference is that there will be no (this) pointer therefore
// we would also need to consider the left hand side object and access
// its member as we do for the right hand side.


#include <iostream>
#include <vector>
#include <cstring> // Needed for all the c style string operations
using namespace std; 

class Mystring
{
    char *str;

public:
    // NO-arg constructor prototype
    //  Mystring();

    // Default One-arg constructor
    Mystring(const char *s = "\0")
        : str{nullptr}
    {
        cout << "Constructor Called!" << endl;
        if (s == "\0")
        {
            str = new char[1];
            str[0] = '\0';
        }
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor
    Mystring(Mystring &source)
        : str{nullptr}
    {
        cout << "Copy Constructor Called!" << endl;
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
    }

    // Move constructor
    Mystring(Mystring &&source)
        : str{nullptr}
    {
        cout << "Move Constructor Called!" << endl;
        str = new char[strlen(source.str) + 1];
        str = source.str;
        source.str = nullptr;
    }

    // str_Getter
    void display()
    {
        cout << str << " " << strlen(str) << endl;
    }

    // Destructor
    ~Mystring()
    {
        if (str == nullptr)
        {
            cout << "Destructor is Called for nullptr!" << endl;
        }
        else
            cout << "Destructor is Called!" << endl;
        delete[] str;
    }

    // Copy assignment
    Mystring &operator=(const Mystring &rhs)
    {
        cout << "Copy Assignment Called!" << endl;

        if (this == &rhs)
        {
            return *this;
        }
        delete[] this->str;
        str = new char[strlen(rhs.str) + 1];
        strcpy(str, rhs.str);
        return *this;
    }

    // Move assignment
    Mystring &operator=(Mystring &&rhs)
    {
        cout << "Move Assignment Called!" << endl;

        if (this == &rhs)
        {
            return *this;
        }
        delete[] this->str;
        str = new char[strlen(rhs.str) + 1];
        str = rhs.str;
        rhs.str = nullptr;
        return *this;
    }

    // Additional overloaded operators

    // Unary operator- for converting string to lowercase
    Mystring operator-() const;

    // Binary operator+ for concatenating two strings
    Mystring operator+(const Mystring &rhs);

    // Binary operator== for comparing two strings
    bool operator==(const Mystring &rhs);

    // Overloaded operators as global function
    // They can access the private attribute as they are friend of the class
    friend istream &operator>>(istream &input, Mystring &rhs);        // Overloaded Input operator>>
    friend ostream &operator<<(ostream &output, const Mystring &rhs); // Overloaded output operator<<

};

int main()
{
    cout << boolalpha;
    Mystring mussu("MY NAME IS KHAN");
    mussu.display();

    Mystring saman;
    saman.display();

    // Mystring Ani {mussu};
    // Ani.display();

    // vector<Mystring> vec;
    // vec.push_back(Mystring("HEHE BOI"));

    Mystring piyush;
    piyush = mussu;
    piyush = "Piyush is GAY";
    piyush.display();

    Mystring God;
    God = -mussu;
    God.display();

    Mystring rick = mussu + " " + "AND I AM not a terrorist";
    rick.display();

    cout << (mussu == piyush) << endl;
    cout << (God == God) << endl;

    Mystring sheesh;
    cin >> sheesh;
    cout << sheesh;
}

// NO args constructor
// Mystring::Mystring():
//     str {nullptr} {
//         str = new char[1];
//         str[0] = '\0';
//     }

Mystring Mystring::operator-() const
{
    cout << "Operator- Called!" << endl;
    char buff[strlen(str) + 1];
    int i = 0;
    while (str[i])
    {
        buff[i] = tolower(str[i]);
        i++;
    }
    Mystring temp{buff};
    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs)
{
    cout << "Operator+ Called!" << endl;
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

bool Mystring::operator==(const Mystring &rhs)
{
    return (strcmp(str, rhs.str) == 0);
}

istream &operator>>(istream &input, Mystring &rhs)
{
    cout << "Value Inputted" << endl;
    char buff[1000];
    input >> buff;
    strcpy(rhs.str, buff);
    return input;
}

ostream &operator<<(ostream &output, const Mystring &rhs)
{
    cout << "Value outputted!" << endl;
    output << rhs.str << " " << strlen(rhs.str) << endl;
    return output;
}