
#include <iostream>
using namespace std;

// Definisi Node
struct Node {
    int data;
    Node* next;
};

// Menambahkan elemen ke dalam linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Menukar nilai dua node
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Melakukan Bubble Sort pada linked list
void bubbleSortList(Node* head) {
    if (head == nullptr) {
        return; // Jika list kosong, tidak perlu sorting
    }

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    // Perulangan hingga tidak ada pertukaran
    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next); // Tukar data jika urutannya salah
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Elemen terakhir sudah berada pada posisi yang benar
    } while (swapped);
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

int main() {
    Node* head = nullptr;

    // Memasukkan 5 elemen ke dalam list
    insert(head, 3);
    insert(head, 1);
    insert(head, 4);
    insert(head, 2);
    insert(head, 5);

    cout << "List sebelum sorting: ";
    displayList(head);

    // Mengurutkan list menggunakan Bubble Sort
    bubbleSortList(head);

    cout << "List setelah sorting: ";
    displayList(head);

    return 0;
}