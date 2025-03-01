#include <bits/stdc++.h>

int main() {
    std::string S;
    std::ifstream in("PTIT.in");
    std::ofstream out("PTIT.out");
    
    while (std::getline(in, S))
        out << S << '\n';
    
    return 0;
}