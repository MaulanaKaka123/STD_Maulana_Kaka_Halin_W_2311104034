#include <iostream>
#include <string>

using namespace std;

// Ubah Angka
string ubahAngka(int Huruf) {
    string Satuan[] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh"};

    string Belasan[] = {"Sebelas", "Dua belas", "Tiga belas", "Empat belas", "Lima belas", "Enam belas", "Tujuh belas",
                       "Delapan belas", "Sembilan belas"};

    string Puluh[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh",
                        "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

// Deteksi angka
    if (Huruf == 0)
        return "Nol";
    else if (Huruf <= 10)
        return Satuan[Huruf];
    else if (Huruf <= 19)
        return Belasan[Huruf - 11];
    else if (Huruf < 100)
        return Puluh[Huruf / 10] + (Huruf % 10 != 0 ? " " + Satuan[Huruf % 10] : "");
    else if (Huruf == 100)
        return "Seratus";

    return "";
}

int main() {
    int angka;

// Input dari user
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

// Memvalidasi
    if (angka < 0 || angka > 100) {
        cout << "Angka di luar batas (0-100)." << endl;
    } else {

// Hasil
        cout << angka << " = " << ubahAngka(angka) << endl;
    }

    return 0;
}
