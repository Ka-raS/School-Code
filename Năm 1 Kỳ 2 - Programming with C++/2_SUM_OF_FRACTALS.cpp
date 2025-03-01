#include<iostream>
using namespace std;

long long factorial (int i) {
    if (i == 1)
        return 1;
    return i * factorial(i - 1);
}

int main() {
    int N;
    cin >> N;

    long long S = 0;
    for (int i = 1; i <= N; i++)
        S += factorial(i);

    cout << S;

    return 0;
}