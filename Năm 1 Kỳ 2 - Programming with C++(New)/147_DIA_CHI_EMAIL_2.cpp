#include <bits/stdc++.h>

std::string convert(const std::string &s)
{
    std::string word, letters;
    std::stringstream ss(s);

    while (ss >> word)
        letters.push_back(std::tolower(word[0]));
    letters.erase(letters.end() - 1);

    for (char &c : word)
        c = std::tolower(c);

    return word + letters;
}

int main()
{
    int t;
    std::cin >> t;
    std::cin.ignore();

    std::vector<std::string> v;
    std::unordered_map<std::string, int> m;

    while (t--)
    {
        std::string s;
        std::getline(std::cin, s);
        s = convert(s);

        m[s]++;
        if (m[s] > 1)
            s += std::to_string(m[s]);
        v.push_back(s);
    }
    m.clear();

    for (const std::string &s : v)
        std::cout << s << "@ptit.edu.vn" << '\n';
    v.clear();

    return 0;
}