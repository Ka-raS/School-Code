#include <iostream>
using namespace std;

bool isPangram(string S, int K) {
    int len = S.length();
    if (len < 26)
        return false;
        
    int i;
    int letters = 0;
    int count[28] = {0};
    
    for (i = 0; i < len; i++)
        if (S[i] >= 'a')
            count[ S[i] - 97 ] = 1;
            
    for (i = 0; i < 27; i++)
        letters += count[i];
            
    if (letters + K >= 26)
        return true;
    return false;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    int K;
    int T;
    cin >> T;
    
    while (T--) {
        cin >> S;
        cin >> K;
        
        cout << isPangram(S, K) << endl;
    }
    return 0;
}