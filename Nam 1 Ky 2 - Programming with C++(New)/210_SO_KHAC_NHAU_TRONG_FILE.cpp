#include <iostream>
#include <fstream>
#include <map>

int main()
{
    int num;
    std::map<int, int> map_num;
    std::ifstream infile("DATA.in");
    while (infile >> num)
        map_num[num]++;
    infile.close();
    for (const std::pair<const int, int> &num : map_num)
        std::cout << num.first << ' ' << num.second << std::endl;
    return 0;
}