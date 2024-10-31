#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isPalindrome(string sentence) {

    sentence.erase(remove(sentence.begin(), sentence.end(), ' '), sentence.end());
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    stack<char> charStack;

    for (char c : sentence) {
        charStack.push(c);
    }

    string reversedSentence = "";
    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }

    return sentence == reversedSentence;
}

int main() {
    string sentence;

    cout << "Kalimat: ";
    getline(cin, sentence);

    if (isPalindrome(sentence)) {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    } else {
        cout << "Kalimat tersebut bukanlah palindrom" << endl;
    }

    return 0;
}