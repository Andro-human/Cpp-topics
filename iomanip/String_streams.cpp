#include <iostream>
#include <sstream>
using namespace std;
int main() {
    int num;
    double total;
    string name;
    string info {"Moe 100 1234.5"};

    istringstream iss{info};
    iss >> name >> num >> total; 
    cout << name << " || " << num << " || " << total << endl;

    ostringstream oss{};
    oss << name << num << total;
    cout << oss.str();

    //discards the input buffer
    // std :: cin.ignore ( std :: numeric_limits < std :: streamsize > :: max ( ) , ' \ n ' ) ;

}