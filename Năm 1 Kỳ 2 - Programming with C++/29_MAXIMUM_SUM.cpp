#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int lenA, lenB;
        cin >> lenA >> lenB;

        int A[lenA], B[lenB];

        for (int i = 0; i < lenA; i++)
            cin >> A[i];
        for (int i = 0; i < lenB; i++)
            cin >> B[i];

        int idA = 0, idB = 0;
        int sumA = 0, sumB = 0, sumMax = 0;

        while (idA < lenA && idB < lenB) {
            if (A[idA] < B[idB])
                sumA += A[idA++];
            else if (A[idA] > B[idB])
                sumB += B[idB++];
            else {
                sumMax += max(sumA, sumB) + A[idA];
                sumA = 0;
                sumB = 0;
                idA++;
                idB++;
                break;
            }
        }

        while (idA < lenA)
            sumA += A[idA++];
            
        while (idB < lenB)
            sumB += B[idB++];
            
        sumMax += max(sumA, sumB);

        cout << sumMax << endl;
    }

    return 0;
}