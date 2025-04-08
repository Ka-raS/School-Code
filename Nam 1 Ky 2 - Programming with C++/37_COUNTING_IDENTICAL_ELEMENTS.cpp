#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int fre[100001] = {0};
        int i = 1;
        int j = 0;
        int x;
        int max = 0;
        
        while (j < N) {
            cin >> x;
            if (max < x)
                max = x;
                
            fre[x] = i;
            j++;
        }
        
        for (i = 1; i < N; i++)
            for (j = 0; j < N; j++) {
                cin >> x;
                
                if(fre[x] == i)
                    fre[x] = i + 1;
            }
            
        int count = 0;
        for (i = 0; i <= max; i++)
            if(fre[i] == N)
                count++;
                
        cout << count << endl;            
    }

    return 0;
}