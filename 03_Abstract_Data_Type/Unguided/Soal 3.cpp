#include <iostream>
using namespace std;

// Menampilkan isi array 2D
void tampilArray(int arr[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Menukarkan isi dua array 2D pada posisi tertentu
void tukarArray(int arr1[3][3], int arr2[3][3], int i, int j) {
    if(i >= 0 && i < 3 && j >= 0 && j < 3) {
        int temp = arr1[i][j];
        arr1[i][j] = arr2[i][j];
        arr2[i][j] = temp;
    } else {
        cout << "Indeks tidak valid!" << endl;
    }
}

// Menukarkan isi dua variabel yang ditunjuk pointer
void tukarPointer(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Dua buah array 2D integer berukuran 3x3
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    // Dua buah pointer integer
    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;

    // Menampilkan isi array sebelum pertukaran
    cout << "Array 1 sebelum pertukaran:" << endl;
    tampilArray(arr1);
    
    cout << "Array 2 sebelum pertukaran:" << endl;
    tampilArray(arr2);

    // Menukarkan isi array pada posisi tertentu (misal: posisi [1][1])
    tukarArray(arr1, arr2, 1, 1);

    // Menampilkan isi array setelah pertukaran
    cout << "Array 1 setelah pertukaran:" << endl;
    tampilArray(arr1);
    
    cout << "Array 2 setelah pertukaran:" << endl;
    tampilArray(arr2);

    // Menampilkan nilai variabel sebelum pertukaran pointer
    cout << "Nilai sebelum pertukaran pointer: " << endl;
    cout << "ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << endl;

    // Menukarkan nilai variabel yang ditunjuk pointer
    tukarPointer(ptr1, ptr2);

    // Menampilkan nilai variabel setelah pertukaran pointer
    cout << "Nilai setelah pertukaran pointer: " << endl;
    cout << "ptr1: " << *ptr1 << ", ptr2: " << *ptr2 << endl;

    return 0;
}