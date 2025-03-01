#include <iostream>
#include <vector>
#include <algorithm>

struct Work
{
    int begin;
    int end;
};

void input(std::vector<Work> &works)
{
    size_t size;
    std::cin >> size;
    works.resize(size);
    for (Work &work : works)
        std::cin >> work.begin >> work.end;
}

bool compare(const Work &work1, const Work &work2)
{
    if (work1.end != work2.end)
        return work1.end < work2.end;
    return work1.begin < work2.begin;
}

int maxWorksDone(std::vector<Work> works)
{
    std::sort(works.begin(), works.end(), compare);

    int worksCount = 0;
    int previousEnd = 0;

    for (const Work &work : works)
        if (work.begin >= previousEnd)
        {
            ++worksCount;
            previousEnd = work.end;
        }

    return worksCount;
}

void runProgram()
{
    std::vector<Work> works;
    input(works);
    std::cout << maxWorksDone(works) << std::endl;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}