#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef struct Coordinate {
    double x;
    double y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(4) << fixed;

    int T;
    cin >> T;
    
    double distance;
    Coordinate A, B, C;
    
    while (T--) {
        cin >> A.x >> A.y;
        cin >> B.x >> B.y;
        
        C.x = pow(A.x - B.x, 2);
        C.y = pow(A.y - B.y, 2);
        
        distance = sqrt(C.x + C.y);
        cout << distance << endl;
        
    }
    
    return 0;           
}