#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;
    
    cin >> a >> op >> b;
    
    switch (op) {
        case '+': 
            printf("%.2f", a + b);
            break;
        case '-':
            printf("%.2f", a - b);
            break;        
        case '*':
            printf("%.2f", a * b);
            break;        
        case '/':
            printf("%.2f", a / b);
            break;
        default:
            break;
    }
            
    return 0;
}