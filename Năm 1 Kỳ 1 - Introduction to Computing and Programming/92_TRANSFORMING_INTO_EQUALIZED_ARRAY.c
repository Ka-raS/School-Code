#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int length, A[200], sumArray = 0;

    scanf("%d", &length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &A[i]);
        sumArray += A[i];
    }
    
    int minSteps, chosenVal, sum_OnesMinusOnes;

    for (int i = 0; i < length; i++) {
        int countSteps = 0, sum = 0;

        for (int j = 0; j < length; j++) {
            countSteps += abs(A[i] - A[j]);
            sum += A[i] - A[j];
        }
            
        if (minSteps > countSteps || i == 0) {
            minSteps = countSteps;
            sum_OnesMinusOnes = sum;
        }
    }

    chosenVal = (sumArray + sum_OnesMinusOnes) / length;

    printf("%d %d", minSteps, chosenVal);

    return 0;
}