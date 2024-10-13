

#include <iostream>
using namespace std;

int main() {
    int a = 20;
    int *ptr = &a;  // Pointer menunjuk ke alamat memori variabel a
    cout << "Nilai a: " << a << endl;         // Menampilkan nilai a
    cout << "Nilai a melalui pointer: " << *ptr << endl;  // Mengakses nilai a melalui pointer
    cout << "Alamat memori pointer ptr: " << ptr << endl; // Menampilkan alamat memori yang ditunjuk oleh pointer
    return 0;
}