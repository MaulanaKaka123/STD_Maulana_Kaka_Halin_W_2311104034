#include <iostream>
using namespace std;

const int maksimalQueue = 5;    // Maksimal Antrian
int front = 0;                  // Penanda Antrian
int back = 0;                   // Penanda
string queueTeller[5];          // Fungsi Pengecekan

bool isFull(){ // Antrian penuh atau tidak
    if (back == maksimalQueue){
        return true; // = 1
    } else {
        return false;
    }
}

bool isEmpty(){ // Antrian kosong atau tidak
    if (back == 0){
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data){ // Menambah antrian
    if (isFull()){
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()){ // Jika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian(){
    if (isEmpty()){
        cout << "Antrian kosong" << endl; // Pindah elemen ke depan
    } else {
        for (int i = 0; i < back - 1; i++){
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = ""; // Kosongkan elemen terakhir
        back--;;
    }
}

int countQueue(){ // Menghitung banyak antrian
    return back;
}

void clearQueue(){ // Menghapus semua antrian
    if (isEmpty()){
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++){
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue(){
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++){
        if (queueTeller[i] != ""){
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main(){
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    cout << "===========================" << endl;
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    cout << "===========================" << endl;
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    cout << "===========================" << endl;
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    cout << "===========================" << endl;
    return 0;
}