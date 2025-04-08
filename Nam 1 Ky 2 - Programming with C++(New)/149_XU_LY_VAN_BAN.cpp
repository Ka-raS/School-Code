#include <bits/stdc++.h>

std::string convert(const std::string &str)
{
    bool end_line = true;
    std::string ans, buf;
    std::stringstream ss(str);
    const std::unordered_set<char> end_symbols = {'.', '?', '!'};

    while (ss >> buf)
    {
        for (char &c : buf)
            c = std::tolower(c);
        if (end_line)
        {
            buf.front() = std::toupper(buf.front());
            end_line = false;
        }
        bool has_end_line_symbol = end_symbols.find(buf.back()) != end_symbols.end();
        if (has_end_line_symbol)
        {
            end_line = true;
            buf.erase(buf.end() - 1);
        }
        ans += buf + ' ';
        if (end_line)
            ans.push_back('\n');
    }
    return ans;
}

int main()
{
    bool end_line = true;
    std::string str;
    std::getline(std::cin, str, '\0');
    std::cout << convert(str);

    return 0;
}