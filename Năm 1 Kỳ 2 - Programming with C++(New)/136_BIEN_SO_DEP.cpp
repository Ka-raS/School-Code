#include <iostream>
using namespace std;

bool isAscending(string S)
{
    for (int i = 0; i < 4; i++)
        if (S[i] >= S[i + 1])
            return false;

    return true;
}

bool isIdentical(string S)
{
    if (S[3] != S[4])
        return false;

    for (int i = 1; i < 3; i++)
        if (S[i] != S[0])
            return false;

    return true;
}

bool is6sAnd8s(string S)
{
    for (int i = 0; i < 5; i++)
        if (S[i] != '6' && S[i] != '8')
            return false;

    return true;
}

bool isPrettyPlate(string S)
{
    if (isAscending(S))
        return true;
    if (isIdentical(S))
        return true;
    if (is6sAnd8s(S))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int len;
    string S;
    string A(5, ' ');

    int T;
    cin >> T;

    while (T--)
    {
        cin >> S;

        len = S.length();

        A[0] = S[len - 6];
        A[1] = S[len - 5];
        A[2] = S[len - 4];
        A[3] = S[len - 2];
        A[4] = S[len - 1];

        if (isPrettyPlate(A))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}