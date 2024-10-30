
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

    // Menambahkan elemen di awal list
    void insertFirst(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        
        head = newNode;
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

    // Menampilkan elemen dari depan ke belakang
    void display() {
        Node* temp = head;
        cout << "DAFTAR ANGGOTA LIST: ";
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
    
    // Input elemen pertama di awal
    cout << "Input: Masukkan elemen pertama = ";
    cin >> value;
    dll.insertFirst(value);
    
    // Input elemen kedua di awal
    cout << "Input: Masukkan elemen kedua di awal = ";
    cin >> value;
    dll.insertFirst(value);
    
    // Input elemen ketiga di akhir
    cout << "Input: Masukkan elemen ketiga di akhir = ";
    cin >> value;
    dll.insertLast(value);

    // Tampilan seluruh elemen
    dll.display();

    return 0;
}