#include <bits/stdc++.h>

/*
long long pow10(int n) {
    long long product = 1;

    for (int i = 0; i < n; i++)
        product *= 10;

    return product;
}

bool isAscend(long long n) {
    int digit;
    int digitPrevious = n % 10;
    n /= 10;

    while (n) {
        digit = n % 10;

        if (digitPrevious <= digit)
            return false;

        digitPrevious = digit;
        n /= 10;
    }

    return true;
}

bool isDescend(long long n) {
    int digit;
    int digitPrevious = n % 10;
    n /= 10;

    while (n) {
        digit = n % 10;

        if (digitPrevious >= digit)
            return false;

        digitPrevious = digit;
        n /= 10;
    }

    return true;
}

bool isPrime (long long n) {
    if (!(n & 1) || !(n % 3))
        return false;
    
    for (long long i = 5; i * i <= n; i += 6)
        if (!(n % i) || !(n % (i + 2)))
            return false;

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    int n;
    int count = 0;
    long long i;
    long long start, end;

    while (t--) {
        std::cin >> n;

        count = 0;

        if (n != 9) {
            start = pow10(n - 1);
            end = start * 10;

            start += 5 - (start % 6);

            for (i = start; i < end; i += 6) {
                if ((isAscend(i) || isDescend(i)) && isPrime(i))
                    count++;
                if ((isAscend(i + 2) || isDescend(i + 2)) && isPrime(i + 2))
                    count++;
            }
        }
        
        std::cout << count << '\n';
    }

    return 0;
}
*/

int count(const int n) {
    switch (n) {
    case 2:
        return 20;
    case 3:
        return 38;
    case 4:
        return 50;
    case 5:
        return 38;
    case 6:
        return 20;
    case 7:
        return 8;
    case 8:
        return 5;
    default:
        return 0;
    }
}

int main() {
    int t, n;
    std::cin >> t;

    while (t--) {
        std::cin >> n;
        std::cout << count(n) << '\n';
    }

    return 0;
}