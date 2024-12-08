#include <iostream>
#include <string>
using namespace std;

struct ProyekNode {
    string namaProyek;
    int durasi;
    ProyekNode* next;

    ProyekNode(string nama, int dur) : namaProyek(nama), durasi(dur), next(nullptr) {}
};

struct PegawaiNode {
    string namaPegawai;
    string idPegawai;
    ProyekNode* proyekHead;
    PegawaiNode* next;

    PegawaiNode(string nama, string id) : namaPegawai(nama), idPegawai(id), proyekHead(nullptr), next(nullptr) {}
};

class MultiLinkedList {
private:
    PegawaiNode* head;

public:
    MultiLinkedList() : head(nullptr) {}

    void tambahPegawai(string nama, string id) {
        PegawaiNode* newPegawai = new PegawaiNode(nama, id);
        newPegawai->next = head;
        head = newPegawai;
    }

    void tambahProyek(string idPegawai, string namaProyek, int durasi) {
        PegawaiNode* curr = head;
        while (curr != nullptr) {
            if (curr->idPegawai == idPegawai) {
                ProyekNode* newProyek = new ProyekNode(namaProyek, durasi);
                newProyek->next = curr->proyekHead;
                curr->proyekHead = newProyek;
                return;
            }
            curr = curr->next;
        }
        cout << "Pegawai dengan ID " << idPegawai << " tidak ditemukan.\n";
    }

    void hapusProyek(string idPegawai, string namaProyek) {
        PegawaiNode* curr = head;
        while (curr != nullptr) {
            if (curr->idPegawai == idPegawai) {
                ProyekNode* prev = nullptr;
                ProyekNode* proyek = curr->proyekHead;
                while (proyek != nullptr) {
                    if (proyek->namaProyek == namaProyek) {
                        if (prev == nullptr) {
                            curr->proyekHead = proyek->next;
                        } else {
                            prev->next = proyek->next;
                        }
                        delete proyek;
                        cout << "Proyek " << namaProyek << " berhasil dihapus dari pegawai " << curr->namaPegawai << ".\n";
                        return;
                    }
                    prev = proyek;
                    proyek = proyek->next;
                }
                cout << "Proyek " << namaProyek << " tidak ditemukan pada pegawai " << curr->namaPegawai << ".\n";
                return;
            }
            curr = curr->next;
        }
        cout << "Pegawai dengan ID " << idPegawai << " tidak ditemukan.\n";
    }

    void tampilkanData() {
        PegawaiNode* curr = head;
        while (curr != nullptr) {
            cout << "Pegawai: " << curr->namaPegawai << " (ID: " << curr->idPegawai << ")\n";
            ProyekNode* proyek = curr->proyekHead;
            if (proyek == nullptr) {
                cout << "  Tidak ada proyek.\n";
            } else {
                while (proyek != nullptr) {
                    cout << "  Proyek: " << proyek->namaProyek << ", Durasi: " << proyek->durasi << " bulan\n";
                    proyek = proyek->next;
                }
            }
            curr = curr->next;
            cout << endl;
        }
    }
};

int main() {
    cout << "========================" << endl;
    MultiLinkedList mll;

    mll.tambahPegawai("Andi", "P001");
    mll.tambahPegawai("Budi", "P002");
    mll.tambahPegawai("Citra", "P003");

    mll.tambahProyek("P001", "Aplikasi Mobile", 12);
    mll.tambahProyek("P002", "Sistem Akuntansi", 8);
    mll.tambahProyek("P003", "E-commerce", 10);

    mll.tambahProyek("P001", "Analisis Data", 6);

    mll.hapusProyek("P001", "Aplikasi Mobile");

    mll.tampilkanData();
    cout << "========================" << endl;
    return 0;
}