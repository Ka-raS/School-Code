#include<iostream>
#include<cmath>
using namespace std;

bool isPerfectSquare(int n) {
    int root = sqrt(n);
    if (root * root == n)
        return true;
    return false;
}

int main() {
    int a, b;
    cin >> a >> b;

    long long sum = 0;

    while (a != b) {
        if (isPerfectSquare(a))
            sum += a;
        a++;
    }
    
    cout << sum;

    return 0;
}