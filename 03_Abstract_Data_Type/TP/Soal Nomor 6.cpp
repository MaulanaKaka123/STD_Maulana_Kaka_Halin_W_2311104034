

#include <iostream>
#include <cmath>  // Fungsi matematika

using namespace std;

class Kerucut {
private:
    double JariJari;
    double Tinggi;

public:
    // Konstruktor
    Kerucut(double r, double t) : JariJari(r), Tinggi(t) {}

    // Menghitung volume kerucut
    double hitungVolume() {
        return (1.0/3.0) * M_PI * JariJari * JariJari * Tinggi;
    }

    // Menghitung luas permukaan kerucut
    double hitungLuasPermukaan() {
        double s = sqrt((JariJari * JariJari) + (Tinggi * Tinggi)); // s = sisi miring
        return M_PI * JariJari * (JariJari + s);
    }
};

int main() {
    // Membuat objek kerucut dengan jari-jari 7 dan tinggi 12
    Kerucut kerucut(7.0, 12.0);

    // Menunjukan volume dan luas permukaan kerucut
    cout << "Volume Kerucut: " << kerucut.hitungVolume() << endl;
    cout << "Luas Permukaan Kerucut: " << kerucut.hitungLuasPermukaan() << endl;

    return 0;
}