#include <iostream>
#include <string>
using namespace std;

bool isLucky(string S) {
    int n = S.size();
    
    while (n--)
        if (S.at(n) != '0' && S.at(n) != '6' && S.at(n) != '8')
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
        
        if (isLucky(S))
            cout << "YES" << endl;
        else
            cout << "NO" << endl; 
    }
    
    return 0;           
}
    