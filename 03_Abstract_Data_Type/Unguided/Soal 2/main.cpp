#include "pelajaran.h"
using namespace std;

int main() {
    // Objek pelajaran
    string NamaPel = "Struktur Data";
    string KodePel = "STD";

    // Menampilkan data pelajaran
    pelajaran pel = create_pelajaran(NamaPel, KodePel);
    tampil_pelajaran(pel);

    return 0;
}