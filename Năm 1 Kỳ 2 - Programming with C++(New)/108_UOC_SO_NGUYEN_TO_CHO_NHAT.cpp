#include <bits/stdc++.h>

bool isPrime (int n) {
    for (int i = 5; i * i <= n; i += 6)
        if (!(n % i) || !(n % (i + 2)))
            return false;

    return true;
}

int minDivisor(int n) {
    if (!(n & 1))
        return 2;
    
    if (!(n % 3))
        return 3;

    if (isPrime(n))
        return n;

    for (int i = 5; i * i <= n; i += 6) {
        if(!(n % i) && isPrime(i))
            return i;
        if(!(n % (i + 2)) && isPrime(i + 2))
            return i + 2;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;

    int n, i;

    while (t--) {
        std::cin >> n;
        std::cout << "1 ";

        for (int i = 2; i <= n; i++)
            std::cout << minDivisor(i) << ' ';

        std::cout << '\n';
    }

    return 0;
}