#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    fstream in_file ("sample.txt");
    fstream out_file ("copy-sample.txt", ios::app);
    string line;
    int num;
    double total;
    // in_file.open("sample.txt");
    if (!in_file) {
        cerr << "Unable to access the in file";
        return 1;
    }
    if (!out_file) {
        cerr << "Unable to acces the out file";
    }
    // cout << "File read successful";
    // // getline(in_file, line);
    while (!in_file.eof()) {
        in_file >> line >> num >> total;
        out_file << setw(10) << left << line
             << setw(10) << num
             << setw(10) << total << endl;
    }
    in_file.close();
    out_file.close();
}