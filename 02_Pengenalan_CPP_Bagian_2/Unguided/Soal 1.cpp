// Unguided 1

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Masukkan banyak elemen: ";
    cin >> n;

    vector<int> arr(n), genap, ganjil;

    // Input array
    cout << "Masukkan bilangan untuk array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
            genap.push_back(arr[i]);
        else
            ganjil.push_back(arr[i]);
    }

    //Data Array
    cout << "Data Array : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Nomor Genap
    cout << "Nomor Genap : ";
    for (int i = 0; i < genap.size(); i++) {
        cout << genap[i];
        if (i != genap.size() - 1)
            cout << ", ";
    }
    cout << endl;

    //Nomor Ganjil
    cout << "Nomor Ganjil : ";
    for (int i = 0; i < ganjil.size(); i++) {
        cout << ganjil[i];
        if (i != ganjil.size() - 1)
            cout << ", ";
    }
    cout << endl;
    return 0;
}