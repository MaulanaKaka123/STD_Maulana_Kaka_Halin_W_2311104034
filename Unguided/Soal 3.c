#include <iostream>
using namespace std;

int main() {
    int Angka;
    cout << "Input: ";
    cin >> Angka;

    // Bagian atas
    for (int a = Angka; a > 0; a--) {
        for (int b = a; b > 0; b--) {
            cout << b << " ";
        }
        cout << "* ";
        for (int b = 1; b <= a; b++) {
            cout << b << " ";
        }
        cout << endl;
    }

    // Bagian bawah
    cout << "*" << endl;

    return 0;
}
