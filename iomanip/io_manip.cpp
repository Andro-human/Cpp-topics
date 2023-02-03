#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a = 255;

    //show base (shows the base)  || uppercase (Makes the base uppercase) || show (shows positive sign)
    cout << showbase << uppercase << showpos;
    cout << dec << a << endl;
    cout << hex << a << endl;
    cout << oct << a << endl;

    double b = 243246.6514567;

    //setprecision (decides the number of elements to display) || fixed (makes the setprecision to decide after decimal)
    cout << setprecision(9) << showpoint << fixed;
    cout << b << endl;

    int c = 20;
    string d = "HELLO";
    cout << c << d << endl;

    string h = "hello";
    int n = 20;


    // setw(sets the width of)
    cout << setfill('*') << setw(10) << left << n;
    cout << setw(15) << h;

}
