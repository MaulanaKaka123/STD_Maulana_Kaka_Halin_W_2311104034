// Unguided 2

#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    // Input array 3 dimensi
    cout << "Masukkan ukuran untuk dimensi pertama (x): ";
    cin >> x;
    cout << "Masukkan ukuran untuk dimensi kedua (y): ";
    cin >> y;
    cout << "Masukkan ukuran untuk dimensi ketiga (z): ";
    cin >> z;

    // Deklarasi array 3 dimensi
    int arr[x][y][z];

    // Input bilangan array
    cout << "Masukkan bilangan array 3D:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "arr[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
    }

    // Isi array 3 dimensi
    cout << "\nIsi array 3 dimensi adalah:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "arr[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
            }
        }
    }

    return 0;
}