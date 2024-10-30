
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Menambahkan elemen di akhir list
    void insertLast(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        
        tail = newNode;
    }

    // Menghapus elemen pertama
    void deleteFirst() {
        if (head == nullptr) {
            cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    // Menghapus elemen terakhir
    void deleteLast() {
        if (tail == nullptr) {
            cout << "List kosong, tidak ada elemen yang bisa dihapus." << endl;
            return;
        }
        
        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }

    // Menampilkan elemen dari depan ke belakang
    void display() {
        Node* temp = head;
        cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int value;

    // Input elemen pertama
    cout << "Input: Masukkan elemen pertama = ";
    cin >> value;
    dll.insertLast(value);

    // Input elemen kedua
    cout << "Input: Masukkan elemen kedua = ";
    cin >> value;
    dll.insertLast(value);

    // Input elemen ketiga
    cout << "Input: Masukkan elemen ketiga = ";
    cin >> value;
    dll.insertLast(value);

    // Hapus elemen pertama
    dll.deleteFirst();

    // Hapus elemen terakhir
    dll.deleteLast();

    // Tampilan seluruh elemen
    dll.display();

    return 0;
}