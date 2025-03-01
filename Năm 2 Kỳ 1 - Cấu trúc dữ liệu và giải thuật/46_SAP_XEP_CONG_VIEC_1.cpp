#include <iostream>
#include <vector>
#include <algorithm>

struct Task
{
    int startTime;
    int finishTime;
};

void input(std::vector<Task> &tasks)
{
    std::size_t size;
    std::cin >> size;
    tasks.resize(size);

    for (Task &task : tasks)
        std::cin >> task.startTime;
    for (Task &task : tasks)
        std::cin >> task.finishTime;
}

int mostTasksDonePosible(std::vector<Task> tasks)
{
    auto finishTimeAscend = [](const Task &task1, const Task &task2) -> bool
    {
        if (task1.finishTime != task2.finishTime)
            return task1.finishTime < task2.finishTime;

        return task1.startTime < task2.startTime;
    };

    std::sort(tasks.begin(), tasks.end(), finishTimeAscend);

    int taskDoneCounter = 0;
    int previousFinishTime = 0;

    for (const Task &task : tasks)
        if (task.startTime >= previousFinishTime)
        {
            ++taskDoneCounter;
            previousFinishTime = task.finishTime;
        }

    return taskDoneCounter;
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
    {
        std::vector<Task> tasks;
        input(tasks);
        std::cout << mostTasksDonePosible(tasks) << std::endl;
    }
}