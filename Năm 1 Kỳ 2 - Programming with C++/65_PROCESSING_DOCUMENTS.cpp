#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void lower(string S, int start, int end) {
    while (start < end) {
        tolower(S.at(start));
        start++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    getline(cin, S);

    string buf;
    vector<string> V;
    stringstream ss(S);

    while (ss >> buf)
        V.push_back(buf);

    int m;
    int i = 0;
    int n = V.size();

    while (i < n) {
        m = V[i].size();
        toupper(V[i][0]);
        lower(V.at(i), 1, m);
        cout << V.at(i) << " ";
        i++;

        while (i < n && V[i][m - 1] != '')


    }

    return 0;
}