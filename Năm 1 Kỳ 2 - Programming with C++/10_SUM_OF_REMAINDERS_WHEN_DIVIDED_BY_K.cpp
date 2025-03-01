#include<iostream>
using namespace std;

bool answer(int N, long long K) {
    int sum = 0;

    while (N) {
        sum += N % K;
        N--;
    }
    
    if (sum == K)
        return true;
    return false;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int N;
        long long K;
        cin >> N >> K;

        cout << answer(N, K) << endl;
    }

    return 0;
}