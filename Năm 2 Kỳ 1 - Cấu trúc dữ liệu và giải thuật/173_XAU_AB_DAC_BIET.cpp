#include <iostream>
#include <vector>

bool isValid(const std::string &str, const int Alength) {
    bool found = false;
    int Acount = 0;

    for (const char c : str) {
        if (c == 'A') {
            ++Acount;
            if (Acount < Alength) {
                continue;
            }

            if (found) {
                return false;
            }
            found = true;
        } else {
            Acount = 0;
        }
    }

    return found;
}

void backTracking(std::vector<std::string> &list, std::string &str, const int length, const int Alength) {
    if (str.length() == length) {
        if (isValid(str, Alength)) {
            list.emplace_back(str);
        }
        return;
    }

    for (char c = 'A'; c <= 'B'; ++c) {
        str.push_back(c);
        backTracking(list, str, length, Alength);
        str.pop_back();
    }
}

std::vector<std::string> findABStrs(const int length, const int Alength) {
    std::vector<std::string> list;
    list.reserve(1 << (length - Alength));
    std::string str;
    backTracking(list, str, length, Alength);
    list.shrink_to_fit();
    return list;
}

void runProgram() {
    int length, Alength;
    std::cin >> length >> Alength;
    std::vector<std::string> list = findABStrs(length, Alength);
    std::cout << list.size() << '\n';
    for (const std::string &str : list) {
        std::cout << str << '\n';
    }
}

int main() {
    runProgram();
}