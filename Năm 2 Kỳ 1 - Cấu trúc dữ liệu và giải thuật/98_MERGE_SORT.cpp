#include <iostream>
#include <vector>

void input(std::vector<int> &array)
{
    size_t size;
    std::cin >> size;
    array.resize(size);
    for (int &num : array)
        std::cin >> num;
}

void output(const std::vector<int> &array)
{
    for (const int num : array)
        std::cout << num << ' ';
    std::cout << '\n';
}

void merge(std::vector<int> &array, const size_t begin, const size_t middle, const size_t end)
{
    const std::vector<int> left(array.begin() + begin, array.begin() + middle);
    const std::vector<int> right(array.begin() + middle, array.begin() + end);

    size_t i = 0;
    size_t j = 0;
    size_t k = begin;
    const size_t sizeLeft = left.size();
    const size_t sizeRight = right.size();

    while (i < sizeLeft && j < sizeRight)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            ++i;
        }
        else
        {
            array[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < sizeLeft)
    {
        array[k] = left[i];
        ++i;
        ++k;
    }

    while (j < sizeRight)
    {
        array[k] = right[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int> &array)
{
    const size_t sizeArray = array.size();

    for (size_t sizeSubArray = 1; sizeSubArray < sizeArray; sizeSubArray *= 2)
    {
        for (size_t begin = 0; begin < sizeArray - 1; begin += sizeSubArray * 2)
        {
            const size_t middle = std::min(begin + sizeSubArray, sizeArray);
            const size_t end = std::min(begin + sizeSubArray * 2, sizeArray);

            merge(array, begin, middle, end);
        }
    }
}

// recursion
// void mergeSort(std::vector<int> &array, const size_t begin, const size_t end)
// {
//     // if sub array size = 1
//     if (begin + 1 >= end)
//         return;

//     const size_t middle = (begin + end) / 2;
//     mergeSort(array, begin, middle);
//     mergeSort(array, middle, end);
//     merge(array, begin, middle, end);
// }

void runProgram()
{
    std::vector<int> array;
    input(array);
    mergeSort(array);
    output(array);
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}