#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    std :: vector < int > vec { 1,2,3,1,4,6} ;
    auto loc = std :: find ( vec.begin ( ) , vec.end ( ) , 3 ) ;    //find
    if ( loc != vec.end ())
        std :: cout << * loc << endl;       
    
    for_each(vec.begin(), vec.end(), [] (int x) {cout << x*x << " ";});     //for_each
    cout << endl;

    int num = count(vec.begin(), vec.end(), 1);         //count
    cout << num << endl; 

    int num2 = count_if (vec.begin(), vec.end(), [] (int x) {   //count_if
        return x%2==0;});
    cout << num2 << endl;

    replace(vec.begin(), vec.end(), 1, 100);            //replace
    for (auto &v:vec) {
        cout << v << " ";
    }
    cout << endl;

    if (all_of(vec.begin(), vec.end(), [](int x){return x>=2;})) {  //all_of
        cout << "All the elements are greater than 2" << endl;
    } 
    else
        cout << "Not all the elements are greater than 2" << endl;

    string hii = "hello";
    transform (hii.begin(), hii.end(), hii.begin(),::toupper);     //transform
    cout << hii << endl;
}