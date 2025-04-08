#include <iostream>
#include <vector>

int waysToInterpret(const std::string &code)
{
    // std::string code contains digit
    // '1' = A, '2' = B,..., "26" = Z
    // '0' is invalid, "27", "28"... is invalid

    // optimization
    // an empty code or a code starts with '0' cannot be interpreted
    if (code.empty() || code[0] == '0')
        return 0;
    // 1 way to interpret a single digit code
    if (code.size() == 1)
        return 1;

    const size_t n = code.size();

    // dynamic programming
    // ways[right] = ways to interpret code[0, right]
    int ways[n] = {0};

    // code[0] != '0' interpret as a single digit
    ++ways[0];

    // check if code[0, 1] can be interpret as 2 single digits
    // condition: code[0] != '0' && code[1] != '0'
    if (code[1] != '0')
        ++ways[1];

    // check if code[0, 1] can be interpret as 2 single digits
    // condition: "10" <= code[0, 1] <= "26"
    std::string combine = code.substr(0, 2);
    if ("10" <= combine && combine <= "26")
        ++ways[1];

    for (size_t i = 2; i < n; ++i)
    {
        // check if code[i] != '0' can be interpreted as 1 single digit
        if (code[i] != '0')
        {
            // string = code[0, i - 1] + code[i]
            // pick up the trail of code[0, i - 1]
            ways[i] += ways[i - 1];
        }

        // combine = code[i - 1, i]
        combine = code.substr(i - 1, 2);

        // check if combine can be interpreted as 1 double digit
        if ("10" <= combine && combine <= "26")
        {
            // string = code[0, i - 2] + combine
            // pick up the trail of code[0, i - 2]
            ways[i] += ways[i - 2];
        }
    }

    // ways to interpret sub string [0, n - 1]
    return ways[n - 1];
}

void runProgram()
{
    std::string code;
    std::cin >> code;
    std::cout << waysToInterpret(code) << '\n';
}

int main()
{
    int tests;
    std::cin >> tests;
    for (int test = 0; test < tests; ++test)
        runProgram();
}