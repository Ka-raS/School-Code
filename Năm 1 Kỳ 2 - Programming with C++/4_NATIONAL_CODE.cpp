#include<iostream>
#include<string.h>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        char code[18];
        cin >> code;

        int length = strlen(code), i;
        for (i = 0; i < length - 3; i++)
            if (code[i] == '0' && code[i + 1] == '8' && code[i + 2] == '4')
                break;

        while (code[i + 3] != '\0') {
            code[i] = code[i + 3];
            i++;
        }
        code[i] = '\0';
        cout << code << endl;
    }
    
    return 0;
}