#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    char c;

    while (T--)
    {
        cin >> c;

        if (c <= 'Z')
        {
            c = tolower(c);
            cout << c << endl;
        }
        else
        {
            c = toupper(c);
            cout << c << endl;
        }
    }

    return 0;
}