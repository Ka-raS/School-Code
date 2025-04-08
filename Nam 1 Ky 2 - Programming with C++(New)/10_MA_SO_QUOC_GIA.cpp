#include <iostream>
#include <string>
using namespace std;

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
        
        code = S.find("084");
        S.erase(code, 3);
        
        cout << S << endl;
    }
    
    return 0;           
}
    