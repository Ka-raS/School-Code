#include <iostream>
#include <stack>

class Postfix
{
public:
    int answer() const;
    friend std::istream &operator>>(std::istream &, Postfix &);

private:
    std::string expression;
};

int main()
{
    int testCases;
    std::cin >> testCases;
    while (testCases--)
    {
        Postfix expression;
        std::cin >> expression;
        std::cout << expression.answer() << std::endl;
    }
}

int Postfix::answer() const
{
    std::stack<int> nums;

    for (const char c : expression)
    {
        if ('0' <= c && c <= '9')
            nums.push(c - '0');
        else
        {
            const int n = nums.top();
            nums.pop();

            if (c == '+')
                nums.top() += n;
            else if (c == '*')
                nums.top() *= n;
            else if (c == '/')
                nums.top() /= n;
            else
                nums.top() -= n;
        }
    }

    return nums.top();
}

std::istream &operator>>(std::istream &in, Postfix &postfix)
{
    return in >> postfix.expression;
}