#include <bits/stdc++.h>

std::set<std::string> convert_to_set(const std::string &S)
{
    std::string buf;
    std::stringstream ss(S);
    std::set<std::string> set_S;

    while (ss >> buf)
        set_S.insert(buf);
    return set_S;
}

bool not_in_set(const std::set<std::string> &set_S, const std::string &S)
{
    if (set_S.find(S) == set_S.end())
        return true;
    return false;
}

std::set<std::string> find_set_S1(const std::string &S1, const std::set<std::string> &set_S2)
{
    std::string buf;
    std::stringstream ss(S1);
    std::set<std::string> set_S1;

    while (ss >> buf)
        if (not_in_set(set_S2, buf))
            set_S1.insert(buf);
    return set_S1;
}

void output(std::set<std::string> &set_S)
{
    for (std::string word : set_S)
        std::cout << word << ' ';
    std::cout << '\n';
}

int main()
{
    int test_cases;
    std::cin >> test_cases;
    std::cin.ignore();

    while (test_cases--)
    {
        std::string S1, S2;
        std::getline(std::cin, S1);
        std::getline(std::cin, S2);

        std::set<std::string> set_S2 = convert_to_set(S2);
        std::set<std::string> set_S1 = find_set_S1(S1, set_S2);
        output(set_S1);
    }

    return 0;
}