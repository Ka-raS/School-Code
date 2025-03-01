#include <iostream>
#include <string>
using namespace std;

bool isLucky(string S) {
    int end = S.size() - 2;
    
    if (end < 0)
        return false;
        
    if (S.at(end) != '8' || S.at(end + 1) != '6')
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
        
        cout << isLucky(S) << endl;
    }
    
    return 0;           
}