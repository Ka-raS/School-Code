#include<iostream>
#include<cmath>
using namespace std;

long long gcd(long long a, long long b) {   //  ước chung lớn nhất
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(int a, long long b) { //  bội chung nhỏ nhất
    return a / gcd(a, b) * b;
}

long long tenPow(int n) {   //  10 mũ n
    if (n == 0)
        return 1;
    return 10 * tenPow(n - 1);
}

long long int result(int X, int Y, int Z, int N) {
    long long multiple = lcm(X, lcm(Y, Z));         //  bội chung nhỏ nhất của X, Y, Z
    int multipleDigits = ceil(log10(multiple));     //  số chữ số của multiple
    
    if (multipleDigits > N)
        return -1;

    long long min = tenPow(N - 1);
    long long remainder = min % multiple;           

    if (remainder == 0)     //  nếu biểu diễn được min = k x multiple , k số nguyên
        return min;

    return min + multiple - remainder;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int X, Y, Z, N;
        cin >> X >> Y >> Z >> N;

        cout << result(X, Y, Z, N) << endl;
    }
    
    return 0;
}