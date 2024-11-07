#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    Mahasiswa* next;
};

class PriorityQueue {
private:
    Mahasiswa* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string nama, int nim) {
        Mahasiswa* newNode = new Mahasiswa{nama, nim, nullptr};
        if (isEmpty() || nim < front->nim) {
            newNode->next = front;
            front = newNode;
        } else {
            Mahasiswa* temp = front;
            while (temp->next != nullptr && temp->next->nim <= nim) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong. Tidak ada yang dapat dihapus." << endl;
            return;
        }
        Mahasiswa* temp = front;
        front = front->next;
        cout << "Dihapus: " << temp->nama << " (NIM: " << temp->nim << ")" << endl;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong." << endl;
            return;
        }
        Mahasiswa* temp = front;
        cout << "Isi Queue:" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
            temp = temp->next;
        }
    }

    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    PriorityQueue queue;
    int choice;
    string nama;
    int nim;

    do {
        cout << "\n1. Tambah Mahasiswa\n2. Hapus Mahasiswa\n3. Tampilkan Queue\n4. Selesai\n";
        cout << "Masukkan Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan NIM Mahasiswa: ";
                cin >> nim;
                queue.enqueue(nama, nim);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Program Selesai." << endl;
                break;
            default:
                cout << "Tidak valid. Coba lagi" << endl;
        }
    } while (choice != 4);

    return 0;
}