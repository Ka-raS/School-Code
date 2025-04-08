#include <iostream>
using namespace std;

bool canArrange(string S) {
    double len = S.length();
    if (len == 1)
        return true;
        
    int letters[28] = {0};
    int i;
    
    for (i = 0; i < len; i++)
        letters[ S[i] - 97 ]++;
    
    int avr = (int)(len / 2 + 0.5);
    for (i = 0; i < 28; i++)
        if (letters[i] > avr)
            return false;
    return true;        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S;
    
    int T;
    cin >> T;
    
    while (T--) {
        cin >> S;
        cout << canArrange(S) << endl;
    }
    return 0;
}