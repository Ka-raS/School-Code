#include <iostream>

void TowerOfHanoi(const int disks, const char beginRod = 'A', const char middleRod = 'B', const char endRod = 'C')
{
    if (disks <= 0)
        return;

    TowerOfHanoi(disks - 1, beginRod, endRod, middleRod);

    std::cout << beginRod << " -> " << endRod << std::endl;

    TowerOfHanoi(disks - 1, middleRod, beginRod, endRod);
}

int main()
{
    int disks;
    std::cin >> disks;
    TowerOfHanoi(disks);
}