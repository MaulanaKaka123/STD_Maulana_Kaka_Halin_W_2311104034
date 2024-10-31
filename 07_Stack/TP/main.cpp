
#include <iostream>
#include "stack.h"
using namespace std;

void testStack(int nim_mod) {
    stack S;
    createStack(S);

    if (nim_mod == 0) {
        const char *data = "IFLABJAYA";
        for (int i = 0; data[i] != '\0'; i++) {
            push(S, data[i]);
        }
    } else if (nim_mod == 1) {
        const char *data = "HALOBANDUNG";
        for (int i = 0; data[i] != '\0'; i++) {
            push(S, data[i]);
        }
    } else if (nim_mod == 2) {
        const char *data = "PERCAYADIRI";
        for (int i = 0; data[i] != '\0'; i++) {
            push(S, data[i]);
        }
    } else if (nim_mod == 3) {
        const char *data = "STRUKTURDATA";
        for (int i = 0; data[i] != '\0'; i++) {
            push(S, data[i]);
        }
    }

    cout << "Isi stack awal: ";
    printInfo(S);

    cout << "Isi stack sesudah pop: ";
    for (int i = 0; i < 4; i++) {
        pop(S);
    }
    printInfo(S);
}

int main() {
    int nim_mod;
    cout << "Masukkan digit terakhir NIM MOD 4: ";
    cin >> nim_mod;
    testStack(nim_mod);
    return 0;
}