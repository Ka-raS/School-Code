#include <stdio.h>
#include <string.h>

#define max 1001

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapStr(char a[], char b[]) { 
    char temp[max];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
} 

int compare(char a[], char b[], int len) {
    for (int i = 0; i < len; i++)
        if(a[i] < b[i])
            return 1;
    return 0;
}

void removeZeros(char a[]) {
    int len = strlen(a), flag = -1;
    for (int i = 0; i < len; i++)
        if(a[i] != '0') {
            flag = i;
            break;
        }
    if(flag == -1) {
        strcpy(a, "0");
        return;
    }
    for (int i = 0; i < len - flag; i++)
        a[i] = a[i + flag];
    a[len - flag] = '\0';
}

int main(int argc, char* argv[]) {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        char num1[max], num2[max];
        scanf("%s%s", num1, num2);

        int len1 = strlen(num1), len2 = strlen(num2);

        if (len1 < len2 || (len1 == len2 && compare(num1, num2, len1))) {
            swapInt(&len1, &len2);
            swapStr(num1, num2);
        }

        while (len1--, len2--) {
            int value = num1[len1] - num2[len2];
            if (value < 0) {
                if (num1[len1 - 1] == '0')
                    for (int i = len1 - 1; i >= 0; i--) {
                        if (num1[i] == '0')
                            num1[i] = 57;
                        else {
                            num1[i]--;
                            break;
                        }
                }
                value += 10;
            }
            num1[len1] = value + 48;
        }
        if(num1[0] == '0')
            removeZeros(num1);
        printf("%s\n", num1);
    }
    return 0;
}