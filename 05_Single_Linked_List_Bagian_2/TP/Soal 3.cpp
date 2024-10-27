
#include <iostream>
using namespace std;

// Definisi Node
struct Node {
    int data;
    Node* next;
};

// Membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Menampilkan elemen-elemen dalam linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Menambahkan elemen secara terurut ke dalam linked list
void insertSorted(Node*& head, int value) {
    Node* newNode = createNode(value);

    // Jika list kosong atau elemen baru lebih kecil dari elemen pertama
    if (head == nullptr || head->data >= value) {
        newNode->next = head;
        head = newNode;
    } else {
        // Mencari posisi yang tepat untuk memasukkan elemen baru
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        // Menyisipkan elemen baru di antara current dan current->next
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    // Memasukkan 4 elemen ke dalam list
    insertSorted(head, 10);
    insertSorted(head, 5);
    insertSorted(head, 20);
    insertSorted(head, 15);

    cout << "List setelah penambahan elemen secara terurut: ";
    displayList(head);

    // Meminta pengguna memasukkan elemen tambahan untuk disisipkan
    int newElement;
    cout << "Masukkan elemen baru yang ingin ditambahkan: ";
    cin >> newElement;

    // Menambahkan elemen baru ke dalam list secara terurut
    insertSorted(head, newElement);

    cout << "List setelah elemen baru ditambahkan: ";
    displayList(head);

    return 0;
}