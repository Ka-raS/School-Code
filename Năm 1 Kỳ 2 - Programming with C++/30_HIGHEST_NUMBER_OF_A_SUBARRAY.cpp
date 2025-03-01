#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int len, numElms;
        cin >> len >> numElms;

        int arr[len];
    
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
            
            if (i - numElms >= -1)
                cout << *max_element(arr + i - numElms + 1, arr + i + 1) << " ";
        }

        cout << endl;
    }

    return 0;
}