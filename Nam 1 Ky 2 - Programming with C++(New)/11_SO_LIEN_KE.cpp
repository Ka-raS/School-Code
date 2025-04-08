#include <iostream>
#include <string>
using namespace std;

bool isSatisfied(string S) {
    int n = S.size() - 1;
    
    for (int i = 0; i < n; i++)
        if (S.at(i) != S.at(i + 1) + 1 && S.at(i) != S.at(i + 1) - 1)
            return false;
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    cin.ignore();
    
    int code;
    string S;
    
    while (T--) {
        cin >> S;
        
        if (isSatisfied(S))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;    
    }
    
    return 0;           
}