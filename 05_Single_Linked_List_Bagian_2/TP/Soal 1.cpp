
#include <iostream>
using namespace std;

// Mendefinisikan Node
struct Node {
    int data;
    Node* next;
};

// Fungsi menambahkan elemen ke dalam linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Fungsi mencari elemen dalam linked list
void searchElement(Node* head, int target) {
    Node* current = head;
    int position = 1; // Posisi dimulai dari 1
    bool found = false;

    // Linear search dalam linked list
    while (current != nullptr) {
        if (current->data == target) {
            cout << "Elemen ditemukan pada posisi: " << position << endl;
            cout << "Alamat elemen: " << current << endl;
            found = true;
            break;
        }
        current = current->next;
        position++;
    }

    // Jika elemen tidak ditemukan
    if (!found) {
        cout << "Elemen tidak ditemukan." << endl;
    }
}

int main() {
    Node* head = nullptr;

    // Memasukkan 6 elemen ke dalam list
    insert(head, 5);
    insert(head, 10);
    insert(head, 15);
    insert(head, 20);
    insert(head, 25);
    insert(head, 30);

    // Meminta input dari pengguna
    int target;
    cout << "Masukkan elemen yang ingin dicari: ";
    cin >> target;

    // Mencari elemen dalam list
    searchElement(head, target);

    return 0;
}