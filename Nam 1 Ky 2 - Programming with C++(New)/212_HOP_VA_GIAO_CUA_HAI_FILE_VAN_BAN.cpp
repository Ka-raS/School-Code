#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

std::set<std::string> inputFromFile(const std::string fileName)
{
    std::set<std::string> Set;

    std::string buf;
    std::ifstream infile(fileName);
    while (infile >> buf)
    {
        for (char &c : buf)
            c = std::tolower(c);
        Set.insert(buf);
    }

    return Set;
}

std::set<std::string> findIntersection(const std::set<std::string> &A, const std::set<std::string> &B)
{
    std::set<std::string> Answer;

    for (const std::string &word : B)
        if (A.count(word))
            Answer.insert(word);

    return Answer;
}

std::set<std::string> findUnion(const std::set<std::string> &A, const std::set<std::string> &B)
{
    std::set<std::string> Answer;

    for (const std::string &word : A)
        Answer.insert(word);
    for (const std::string &word : B)
        Answer.insert(word);

    return Answer;
}

void output(const std::set<std::string> &A)
{
    for (const std::string &word : A)
        std::cout << word << ' ';
    std::cout << '\n';
}

int main()
{
    std::set<std::string> A = inputFromFile("DATA1.in"),
                          B = inputFromFile("DATA2.in");

    std::set<std::string> Uni = findUnion(A, B),
                          Inter = findIntersection(A, B);
    output(Uni);
    output(Inter);

    return 0;
}