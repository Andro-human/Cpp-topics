#include <iostream>
using namespace std;

int *create_arr(size_t size, int init_val) {
    
    int *ptr = new int[size];

    for (int i=0; i<size; i++) {
        ptr[i] = init_val;
    }
    return ptr;
}

void print(int *arr_ptr, size_t size) {

    for (int i=0; i<size; i++) {
        cout << arr_ptr[i] << " ";
    }
    cout << endl;
}

int main() {
    
    size_t size;
    cin >> size;

    int init_val;
    cin >> init_val;

    int *arr_ptr = create_arr(size, init_val);
    print(arr_ptr, size);

    delete[] arr_ptr;

   
}
