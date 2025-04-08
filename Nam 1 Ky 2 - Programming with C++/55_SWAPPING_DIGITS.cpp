#include <iostream>
using namespace std;

bool canSwap(string &S) {
    int i, j, k;
    int max = 0;
    int idx;
    char tmp;
    int len = S.length();
    
    for (i = len - 2; i >= 0; i--) {
        for (j = i + 1; j < len; j++) {
            if (S[j] < S[i] && max < S[j]) {
                max = S[j];
                idx = j;

                if (max + 1 == S[i])
                    break;
            }
        }
        if (max) {
            tmp = S[i];
            S[i] = S[idx];
            S[idx] = tmp;
            return true;
        }
    }
    return false;    
}

void output(string S) {
    int i = 0;
    int len = S.length();
    
    while (S[i] == '0')
        i++;
        
    while (i < len)
        cout << S[i++];
    cout << endl;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> S;
        
        if (canSwap(S))
            output(S);
        else
            cout << -1 << endl;
    }
    return 0;
}