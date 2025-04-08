#include <iostream>
#include <vector>
#include <algorithm>

struct Job
{
    long long id;
    long long deadline;
    long long profit;
};

void input(std::vector<Job> &jobList)
{
    long long count;
    std::cin >> count;
    jobList.resize(count);
    for (Job &job : jobList)
        std::cin >> job.id >> job.deadline >> job.profit;
}

bool profitDescending(const Job &A, const Job &B)
{
    return A.profit > B.profit;
}

std::pair<long long, long long> findBestProfit(const std::vector<Job> &jobList)
{
    long long jobDone = 0;
    long long totalProfit = 0;

    for (const Job &job : jobList)
        if (job.deadline > jobDone)
        {
            totalProfit += job.profit;
            ++jobDone;
        }

    return {jobDone, totalProfit};
}

void runProgram()
{
    std::vector<Job> jobList;
    input(jobList);
    std::sort(jobList.begin(), jobList.end(), profitDescending);
    const auto [jobDone, totalProfit] = findBestProfit(jobList);
    std::cout << jobDone << ' ' << totalProfit << '\n';
}

int main()
{
    long long tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}