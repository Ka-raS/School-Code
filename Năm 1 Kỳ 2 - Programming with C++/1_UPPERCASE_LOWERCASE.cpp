#include<iostream>
#include<cctype>
using namespace std;

int main() {
    char letter;
    int testCases;
    cin >> testCases;

    while (testCases--) {
        cin >> letter;

        if (isupper(letter)) {
            letter = tolower(letter);
            cout << letter << endl;
        }
        else if (islower(letter)) {
            letter = toupper(letter);
            cout << letter << endl;
        }
    }

    return 0;
}
