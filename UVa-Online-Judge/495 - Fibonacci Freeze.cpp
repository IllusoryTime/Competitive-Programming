//Source Code Written: 5/22/15

#include <bits/stdc++.h>
using namespace std;

char* str_sum(char array1[], char array2[]);

int main() {
    char array[5000+2][1092] = { "0", "1" };
    char* c;
    for(int i = 2; i <= 5000; i++) {
        c = str_sum(array[i-1], array[i-2]);
        strcpy(array[i], c);
    }
    int n;
    while(scanf("%d", &n)==1) {
        printf("The Fibonacci number for %d is %s\n", n, array[n]);
    }
    return 0;
}

char* str_sum(char array1[], char array2[]) {
    static char str[1092];
    int len1 = strlen(array1), len2 = strlen(array2);
    int d = len1 - len2, x = 0, n;
    for(int i = len2 - 1; i >= 0; i--) {
        n = array1[i + d] - '0' + array2[i] - '0' + x;
        if(n >= 10) x  = 1;
        else x = 0;
        str[i + d] = (n % 10) + '0';
    }
    if(d) {
        str[d - 1] = array1[0] + x;
        str[len2 + d] = '\0';
    } else if(x) {
        for(int i = len1; i > 0; i--) str[i] = str[i - 1];
        str[0] = '1';
        str[len1 + 1] = '\0';
    }
    return str;
}
