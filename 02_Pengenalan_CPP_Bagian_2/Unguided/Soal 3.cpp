// Unguided 3

#include <iostream>
using namespace std;

void cariMaksimum(int arr[], int n) {
    int maksimum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maksimum) {
            maksimum = arr[i];
        }
    }
    cout << "Nilai maksimum: " << maksimum << endl;
}

void cariMinimum(int arr[], int n) {
    int minimum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    cout << "Nilai minimum: " << minimum << endl;
}

void cariRataRata(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    double rataRata = (double)total / n;
    cout << "Nilai rata-rata: " << rataRata << endl;
}

int main() {
    int n;

    // Input jumlah elemen array
    cout << "Masukkan banyak array: ";
    cin >> n;

    int arr[n];

    // Input elemen array
    cout << "Masukkan bilangan untuk array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pilihan;
    do {
        // Menu
        cout << "\nMenu:\n";
        cout << "1. Cari Nilai Maksimum\n";
        cout << "2. Cari Nilai Minimum\n";
        cout << "3. Cari Nilai Rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cariMaksimum(arr, n);
                break;
            case 2:
                cariMinimum(arr, n);
                break;
            case 3:
                cariRataRata(arr, n);
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                break;
        }
    } while (pilihan != 4);

    return 0;
}