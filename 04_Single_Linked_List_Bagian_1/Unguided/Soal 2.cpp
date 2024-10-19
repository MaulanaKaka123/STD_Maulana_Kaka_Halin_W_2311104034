

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertDepan(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

void insertBelakang(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void hapusNode(Node*& head, int nilai) {
    Node* temp = head;
    Node* prev = nullptr;
    
    if (temp != nullptr && temp->data == nilai) {
        head = temp->next;
        delete temp;
        return;
    }
    
    while (temp != nullptr && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan dalam linked list." << endl;
        return;
    }
    
    prev->next = temp->next;
    delete temp;
}

void cetakLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    
    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);
    
    cout << "Linked list sebelum penghapusan:" << endl;
    cetakLinkedList(head);
    
    hapusNode(head, 10);
    
    cout << "Linked list setelah penghapusan:" << endl;
    cetakLinkedList(head);
    
    return 0;
}