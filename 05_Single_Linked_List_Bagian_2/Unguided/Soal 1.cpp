#include <iostream>
#include <string>

using namespace std;

// Node structure for Single Linked List
struct Node {
    int NIM;
    string nama;
    Node* next;
};

// Function to create a new node
Node* createNode(int nim, string nama) {
    Node* newNode = new Node();
    newNode->NIM = nim;
    newNode->nama = nama;
    newNode->next = nullptr;
    return newNode;
}

// Function to add a student to the list
void tambahMahasiswa(Node*& head, int nim, string nama) {
    Node* newNode = createNode(nim, nama);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Mahasiswa dengan NIM " << nim << " telah ditambahkan." << endl;
}

// Function to search for a student by NIM
Node* cariMahasiswa(Node* head, int nim) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->NIM == nim) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Function to display a student based on search result
void tampilkanMahasiswa(Node* head, int nim) {
    Node* hasil = cariMahasiswa(head, nim);
    if (hasil != nullptr) {
        cout << "Mahasiswa ditemukan:" << endl;
        cout << "NIM: " << hasil->NIM << endl;
        cout << "Nama: " << hasil->nama << endl;
    } else {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }
}

int main() {
    Node* head = nullptr;
    int pilihan, nim;
    string nama;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Cari Mahasiswa Berdasarkan NIM\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cin.ignore();  // to ignore newline character after integer input
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                tambahMahasiswa(head, nim, nama);
                break;
            case 2:
                cout << "Masukkan NIM yang ingin dicari: ";
                cin >> nim;
                tampilkanMahasiswa(head, nim);
                break;
            case 3:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);

    return 0;
}