//Source Code Written: 5/23/15

#include <bits/stdc++.h>
using namespace std;

char* str_sum(char array1[], char array2[]);

int main() {
    //freopen("in.txt", "r", stdin);
    char array1[10000], array2[10000];
    char * c;
    strcpy(array2, "0");
    while(scanf("%s", array1) == 1) {
        if(strcmp(array1, "0") == 0) {
            cout << array2 << endl;
            break;
        } else {
            if(strlen(array1) >= strlen(array2)) c = str_sum(array1, array2);
            else if(strlen(array1) < strlen(array2)) c = str_sum(array2, array1);
            strcpy(array2, c);
        }
    }
    return 0;
}

char* str_sum(char array1[], char array2[]) {
    static char str[100000];
    int len1 = strlen(array1), len2 = strlen(array2);
    int d = len1 - len2, x = 0, n;
    for(int i = len2 - 1; i >= 0; i--) {
        n = array1[i + d] - '0' + array2[i] - '0' + x;
        if(n >= 10) x  = 1;
        else x = 0;
        str[i + d] = (n % 10) + '0';
    }
    if(d) {
        for(int i = d; i > 0; i--) {
            n = array1[i - 1] + x - '0';
            if(n >= 10) x = 1;
            else x = 0;
            str[i - 1] =  (n % 10) + '0';
        }
        str[len1] = '\0';
    }
    if(x) {
        for(int i = len1; i > 0; i--) str[i] = str[i - 1];
        str[0] = '1';
        str[len1 + 1] = '\0';
    }
    return str;
}
