#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    // Variabel Float
    float ang1,ang2;

    // Meminta Input
    cout << "Masukkan angka pertama: ";
    cin >>ang1;
    cout << "Masukan angka kedua: ";
    cin >> ang2;

    // Hasil perhitungan
    cout << "Hasil dari penjumlahan: " << ang1 + ang2 << endl;
    cout << "Hasil dari pengurangan: " << ang1 - ang2 << endl;
    cout << "Hasil dari perkalian: " << ang1 * ang2 << endl;

    // Mengecek angka
    if (ang1 or ang2 != 0){
        cout << "Hasil dari pembagian: " << ang1 / ang2 << endl;
    } else
        cout << "Pembagian tidak valid: " << endl;
    return 0;
}
