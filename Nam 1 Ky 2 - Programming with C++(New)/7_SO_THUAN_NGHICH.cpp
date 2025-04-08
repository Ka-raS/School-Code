#include <iostream>
#include <string>
using namespace std;

bool isPalindromic(string S) {
    int n = S.size();
    int j = n - 1;
    n /= 2;
    
    for (int i = 0; i < n; i++)
        if (S.at(i) != S.at(j - i))
            return false;
            
    return true;        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    cin.ignore();
    
    string S;
    
    while (T--) {
        cin >> S;
        
        if (isPalindromic(S))
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }
    
    return 0;           
}