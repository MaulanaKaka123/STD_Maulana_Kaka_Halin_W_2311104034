
#include <iostream>
#include <string>
using namespace std;

// Menyimpan informasi buku
struct Node {
    int idBuku;
    string judulBuku;
    string penulisBuku;
    Node* prev;
    Node* next;

    Node(int id, string judul, string penulis) : idBuku(id), judulBuku(judul), penulisBuku(penulis), prev(nullptr), next(nullptr) {}
};

// Mengelola daftar buku
class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    // Menambahkan buku di akhir list
    void tambahBuku(int id, string judul, string penulis) {
        Node* newNode = new Node(id, judul, penulis);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Buku dengan ID " << id << " berhasil ditambahkan.\n";
    }

    // Menampilkan daftar buku dari awal ke akhir
    void tampilkanDariAwal() {
        if (head == nullptr) {
            cout << "Daftar buku kosong.\n";
            return;
        }

        Node* current = head;
        cout << "Daftar Buku dari Awal ke Akhir:\n";
        while (current != nullptr) {
            cout << "ID Buku: " << current->idBuku << ", Judul Buku: " << current->judulBuku
                 << ", Penulis Buku: " << current->penulisBuku << "\n";
            current = current->next;
        }
    }

    // Menampilkan daftar buku dari akhir ke awal
    void tampilkanDariAkhir() {
        if (tail == nullptr) {
            cout << "Daftar buku kosong.\n";
            return;
        }

        Node* current = tail;
        cout << "Daftar Buku dari Akhir ke Awal:\n";
        while (current != nullptr) {
            cout << "ID Buku: " << current->idBuku << ", Judul Buku: " << current->judulBuku
                 << ", Penulis Buku: " << current->penulisBuku << "\n";
            current = current->prev;
        }
    }

    ~DoubleLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

// Fungsi utama
int main() {
    DoubleLinkedList daftarBuku;
    int pilihan, id;
    string judul, penulis;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Buku dari Awal ke Akhir\n";
        cout << "3. Tampilkan Buku dari Akhir ke Awal\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID Buku: ";
                cin >> id;
                cin.ignore(); // Mengabaikan newline
                cout << "Masukkan Judul Buku: ";
                getline(cin, judul);
                cout << "Masukkan Penulis Buku: ";
                getline(cin, penulis);
                daftarBuku.tambahBuku(id, judul, penulis);
                break;
            case 2:
                daftarBuku.tampilkanDariAwal();
                break;
            case 3:
                daftarBuku.tampilkanDariAkhir();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}