#include <iostream>

size_t find(const int *const array, const size_t count, const int target)
{
    for (size_t i = 0; i < count; i++)
        if (array[i] == target)
            return i;
    return count;
}

void outputBinaryTree(const int *const inorder, const int *const preorder, const size_t count)
{
    const size_t pos = find(inorder, count, preorder[0]);
    if (pos > 0)
        outputBinaryTree(inorder, preorder + 1, pos);
    if (pos < count - 1)
        outputBinaryTree(inorder + pos + 1, preorder + pos + 1, count - pos - 1);
    std::cout << preorder[0] << ' ';
}

void runProgram()
{
    size_t count;
    std::cin >> count;
    int inorder[count], preorder[count];
    for (int &node : inorder)
        std::cin >> node;
    for (int &node : preorder)
        std::cin >> node;
    outputBinaryTree(inorder, preorder, count);
    std::cout << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    while (tests--)
        runProgram();
}