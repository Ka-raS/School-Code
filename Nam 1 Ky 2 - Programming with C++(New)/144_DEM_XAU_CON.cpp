#include <bits/stdc++.h>

int find_at_most_k_chars(const std::string &s, const int &k)
{
    int count = 0;
    const std::size_t n = s.size();
    std::unordered_map<char, int> m;

    for (std::size_t i = 0, j = 0; i < n; i++)
    {
        m[s[i]]++;
        while (m.size() > k)
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                m.erase(s[j]);
            j++;
        }
        count += i - j + 1;
    }

    return count;
}

int find_exactly_k_chars(const std::string &s, const int &k)
{
    return find_at_most_k_chars(s, k) - find_at_most_k_chars(s, k - 1);
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    while (test_cases--)
    {
        int k;
        std::string s;
        std::cin >> s >> k;
        std::cout << find_exactly_k_chars(s, k) << '\n';
    }

    return 0;
}