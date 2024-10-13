

#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float UTS;
    float UAS;
    float Tugas;
    float NilaiAkhir;
};

// Menghitung nilai akhir
float HitungNilaiAkhir(float UTS, float UAS, float Tugas) {
    return (0.3 * UTS) + (0.4 * UAS) + (0.3 * Tugas);
}

int main() {
    const int JumlahMahasiswa = 10;  // Maks 10 mahasiswa
    Mahasiswa Mahasiswa[JumlahMahasiswa];
    int n;

    cout << "Masukkan jumlah Mahasiswa (max 10): ";
    cin >> n;

    if(n > JumlahMahasiswa) {
        cout << "Jumlah Mahasiswa tidak boleh lebih dari 10!" << endl;
        return 1;
    }

    // Input data mahasiswa
    for(int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i+1 << endl;
        cout << "Nama Mahasiswa: ";
        cin >> ws;  // membersihkan newline dari input sebelumnya
        getline(cin, Mahasiswa[i].Nama);
        cout << "NIM: ";
        cin >> Mahasiswa[i].NIM;
        cout << "Nilai UTS: ";
        cin >> Mahasiswa[i].UTS;
        cout << "Nilai UAS: ";
        cin >> Mahasiswa[i].UAS;
        cout << "Nilai Tugas: ";
        cin >> Mahasiswa[i].Tugas;

        // Hitung nilai akhir
        Mahasiswa[i].NilaiAkhir = HitungNilaiAkhir(Mahasiswa[i].UTS, Mahasiswa[i].UAS, Mahasiswa[i].Tugas);
    }

    // Output data mahasiswa
    cout << "\n\nData Mahasiswa dan Nilai Akhir:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama Mahasiswa: " << Mahasiswa[i].Nama << endl;
        cout << "NIM: " << Mahasiswa[i].NIM << endl;
        cout << "Nilai UTS: " << Mahasiswa[i].UTS << endl;
        cout << "Nilai UAS: " << Mahasiswa[i].UAS << endl;
        cout << "Nilai Tugas: " << Mahasiswa[i].Tugas << endl;
        cout << "Nilai Akhir: " << Mahasiswa[i].NilaiAkhir << endl;
    }

    return 0;
}