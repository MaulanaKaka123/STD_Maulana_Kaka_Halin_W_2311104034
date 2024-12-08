#include <iostream>
#include <string>

using namespace std;

struct BookNode {
    string title;
    string returnDate;
    BookNode* next;
};

struct MemberNode {
    string name;
    string id;
    BookNode* borrowedBooks;
    MemberNode* next;
};

void addMember(MemberNode*& head, const string& name, const string& id) {
    MemberNode* newMember = new MemberNode{name, id, nullptr, head};
    head = newMember;
}

void addBook(MemberNode* head, const string& memberId, const string& title, const string& returnDate) {
    while (head != nullptr && head->id != memberId) {
        head = head->next;
    }

    if (head != nullptr) {
        BookNode* newBook = new BookNode{title, returnDate, head->borrowedBooks};
        head->borrowedBooks = newBook;
    }
}

void deleteMember(MemberNode*& head, const string& memberId) {
    MemberNode* prev = nullptr;
    MemberNode* curr = head;

    while (curr != nullptr && curr->id != memberId) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != nullptr) {
        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }

        BookNode* book = curr->borrowedBooks;
        while (book != nullptr) {
            BookNode* temp = book;
            book = book->next;
            delete temp;
        }

        delete curr;
    }
}

void displayMembers(MemberNode* head) {
    while (head != nullptr) {
        cout << "Anggota: " << head->name << " (ID: " << head->id << ")" << endl;
        BookNode* book = head->borrowedBooks;

        if (book == nullptr) {
            cout << "  Tidak ada buku yang dipinjam." << endl;
        } else {
            cout << "  Buku yang dipinjam:" << endl;
            while (book != nullptr) {
                cout << "    - " << book->title << " (Pengembalian: " << book->returnDate << ")" << endl;
                book = book->next;
            }
        }

        head = head->next;
    }
}

int main() {
    cout << "========================" << endl;
    MemberNode* library = nullptr;

    addMember(library, "Rani", "A001");
    addMember(library, "Dito", "A002");
    addMember(library, "Vina", "A003");

    addBook(library, "A001", "Pemrograman C++", "01/12/2024");
    addBook(library, "A002", "Algoritma Pemrograman", "15/12/2024");
    addBook(library, "A001", "Struktur Data", "10/12/2024");

    deleteMember(library, "A002");

    displayMembers(library);
    cout << "========================" << endl;
    return 0;
}