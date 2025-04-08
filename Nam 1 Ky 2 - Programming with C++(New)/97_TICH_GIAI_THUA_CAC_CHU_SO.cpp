#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::string a;
        std::cin >> n >> a;

        int n2 = 0, n3 = 0, n5 = 0, n7 = 0;

        for (char digit : a)
            switch (digit) {
            case '2':
                n2++;
                break;
            case '3':
                n3++;
                break;
            case '4':
                n2 += 2;
                n3++;
                break;
            case '5':
                n5++;
                break;
            case '6':
                n3++;
                n5++;
                break;
            case '7':
                n7++;
                break;
            case '8':
                n2 += 3;
                n7++;
                break;
            case '9':
                n2++;
                n3 += 2;
                n7++;
                break;
            default:
                break;
            }
        
        for (n = 0; n < n7; n++)
            std::cout << 7;
        for (n = 0; n < n5; n++)
            std::cout << 5;
        for (n = 0; n < n3; n++)
            std::cout << 3;
        for (n = 0; n < n2; n++)
            std::cout << 2;
        std::cout << '\n';
    }

    return 0;
}