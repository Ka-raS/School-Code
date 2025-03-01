#include <iostream>
#include <string>

using namespace std;

int decode(char s) {
    if (('a' <= s && s <= 'c') || ('A' <= s && s <= 'C'))
        return 2;
        
    if (('d' <= s && s <= 'f') || ('D' <= s && s <= 'F'))    
        return 3;
        
    if (('g' <= s && s <= 'i') || ('G' <= s && s <= 'I'))    
        return 4;
        
    if (('j' <= s && s <= 'l') || ('J' <= s && s <= 'L'))    
        return 5;
        
    if (('m' <= s && s <= 'o') || ('M' <= s && s <= 'O'))    
        return 6;
        
    if (('p' <= s && s <= 's') || ('P' <= s && s <= 'S'))    
        return 7;
        
    if (('t' <= s && s <= 'v') || ('T' <= s && s <= 'V'))
        return 8;   
        
    return 9;
}

bool isPalindromic(string S) {
    int first, last;
    int n = S.size();
    int j = n - 1;
    n /= 2;
    
    
    for (int i = 0; i < n; i++) {
        first = decode(S.at(i));
        last  = decode(S.at(j - i));
        
        if (first != last)
            return false;
    }
    
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
        
        if (isPalindromic(S))
            cout << "YES";
        else
            cout << "NO";
            
        cout << endl;
    }

    return 0;
}