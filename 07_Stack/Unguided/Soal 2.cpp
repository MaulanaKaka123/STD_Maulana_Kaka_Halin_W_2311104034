#include <iostream>
#include <stack>
#include <string>
using namespace std;

string balikKalimat(string kalimat) {
    stack<char> stackChar;
    string hasil = "";

    for (char c : kalimat) {
        stackChar.push(c);
    }

    while (!stackChar.empty()) {
        hasil += stackChar.top();
        stackChar.pop();
    }

    return hasil;
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    string hasil = balikKalimat(kalimat);

    cout << "Kalimat asli: " << kalimat << endl;
    cout << "Hasil pembalikan: " << hasil << endl;

    return 0;
}