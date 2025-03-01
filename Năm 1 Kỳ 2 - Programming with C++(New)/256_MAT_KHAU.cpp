#include <iostream>
#include <vector>
#include <algorithm>

void input(std::vector<std::string>&);
int possibleBypasses(std::vector<std::string> str) {
    auto lengthDescend = [](const std::string& A, const std::string& B) -> bool {
        return A.length() > B.length();
    };
    std::sort(str.begin(), str.end(), lengthDescend);

    int count = 0;
    const size_t n = str.size();
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if (str[i].find(str[j]) != std::string::npos)
            {
                ++count;
                if (str[i].length() == str[j].length()) // str[i] == str[j]
                    ++count;
            }
    return count;
}

int main() {
    size_t length;
    std::vector<std::string> str;
    input(str);
    std::cout << possibleBypasses(str);
}

void input(std::vector<std::string>& str) {
    size_t size;
    std::cin >> size;
    str.resize(size);
    for (std::string& password : str)
        std::getline(std::cin >> std::ws, password);
}