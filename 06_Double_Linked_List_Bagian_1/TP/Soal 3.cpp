
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

    // Menampilkan elemen dari depan ke belakang
    void displayForward() {
        Node* temp = head;
        cout << "Daftar elemen dari depan ke belakang: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // Menampilkan elemen dari belakang ke depan
    void displayBackward() {
        Node* temp = tail;
        cout << "Daftar elemen dari belakang ke depan: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->prev != nullptr) {
                cout << " <-> ";
            }
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int value;

    // Memasukkan 4 elemen ke dalam list
    cout << "Input: Masukkan 4 elemen secara berurutan:\n";
    for (int i = 0; i < 4; ++i) {
        cout << "Elemen ke-" << i+1 << " = ";
        cin >> value;
        dll.insertLast(value);
    }

    // Menampilkan elemen dari depan ke belakang
    dll.displayForward();

    // Menampilkan elemen dari belakang ke depan
    dll.displayBackward();

    return 0;
}