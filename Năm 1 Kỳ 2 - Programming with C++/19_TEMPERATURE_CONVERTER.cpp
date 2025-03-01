#include <iostream>
using namespace std;

int main() {
    double C;
    cin >> C;

    double F = (C / 5 * 9) + 32;
    printf("%.2f", F);
    
    return 0;
}