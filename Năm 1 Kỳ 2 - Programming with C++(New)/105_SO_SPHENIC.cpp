#include<iostream>
using namespace std;

int isSphenic(int N) {
    int distinctInt = 1;

    if (N % 4 == 0 || N < 30)
        return 0;
    if (N % 2 == 0) {
        N /= 2;
        distinctInt++;
    }

    for (int i = 3; i * i <= N; i += 2)
        if (N % i == 0) {
            if (N % (i * i) == 0)
                return 0;
            N /= i;
            distinctInt++;
            if (distinctInt == 4)
                return 0;
        }
    if (distinctInt == 3)
        return 1;
    return 0;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int N;
        cin >> N;
        cout << isSphenic(N) << endl;
    }

    return 0;
}