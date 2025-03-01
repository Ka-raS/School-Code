#include <iostream>
#include <cstdlib>
using namespace std;

int descending(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int testCases;
    cin >> testCases;
    
    int length;
    
    while (testCases--) {
        cin >> length;
        
        int array[length];
        
        for (int i = 0; i < length; i++)
            cin >> array[i];
            
        qsort(array, length, sizeof(int), descending);
            
        long long diff = array[0] - array[1];
        
        for (int i = 1; i < length - 1; i++) {
            int diffTemp = array[i] - array[i + 1];
            if (diff > diffTemp) {
                diff = diffTemp;
                if (diff == 0)
                    break;
            }
        }    
        cout << diff << endl;    
    }
            
    return 0;
}