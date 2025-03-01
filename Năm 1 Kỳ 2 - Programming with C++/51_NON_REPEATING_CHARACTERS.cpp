#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int fre[200] = {0};

        string word;
        cin >> word;

        int i;
        int len = word.length();
        for (i = 0; i < len; i++)
            fre[ word[i] ]++;

        for (i = 0; i < len; i++)
            if (fre[ word[i] ] == 1)
                cout << word[i];
        cout << endl;
    }
    return 0;
}