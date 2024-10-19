

#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List L;
    createList(L);
    infotype data;

    cout << "Masukkan Nomor Nim ke 1: ";
    cin >> data;
    insertFirst(L, allocate(data));
    cout << "List setelah data ke 1 dimasukkan: ";
    printInfo(L);

    cout << "Masukkan nomor Nim ke 2: ";
    cin >> data;
    insertFirst(L, allocate(data));

    cout << "List setelah data ke 2 dimasukkan: ";
    printInfo(L);

    cout << "Masukkan nomor Nim ke 3: ";
    cin >> data;
    insertFirst(L, allocate(data));

    cout << "List setelah data terakhir dimasukkan: ";
    printInfo(L);

    return 0;
}