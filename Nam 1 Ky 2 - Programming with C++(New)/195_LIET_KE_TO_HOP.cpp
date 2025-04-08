#include <iostream>
#include <vector>

std::vector<int> find_A(int K)
{
    std::vector<int> A(K);
    while (K--)
        A[K] = K + 1;
    return A;
}

void output(const std::vector<int> &A)
{
    for (const int &x : A)
        std::cout << x;
    std::cout << ' ';
}

void transform(std::vector<int> &A, const int &N, const int &K)
{
    int i = K - 1;
    while (A[i] == A[i - 1] + 1 && i > 0)
        i--;

    A[i - 1]++;
    while (i < K)
    {
        A[i] = A[i - 1] + 1;
        i++;
    }
}

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int N, K;
        std::cin >> N >> K;
        std::vector<int> A = find_A(K);

        while (A.front() < N - K + 1)
        {
            output(A);
            if (A.back() < N)
                A.back()++;
            else // == N
                transform(A, N, K);
        }
        output(A);
        std::cout << '\n';
    }

    return 0;
}