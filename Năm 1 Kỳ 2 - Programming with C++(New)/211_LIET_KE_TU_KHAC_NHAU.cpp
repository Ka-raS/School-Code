#include <iostream>
#include <set>
#include <string>
#include <fstream>

int main()
{
    std::string buf;
    std::set<std::string> word_set;
    std::ifstream infile("VANBAN.in");
    while (infile >> buf)
    {
        for (char &c : buf)
            c = std::tolower(c);
        word_set.insert(buf);
    }
    infile.close();
    for (const std::string &word : word_set)
        std::cout << word << std::endl;
    return 0;
}