//Problem Solved: 10/4/13
//Last Edit: 9/27/16

#include <stdio.h>
int main() {
    long long int n, k, five = 0, cnt = 0, f;
    scanf("%I64d", &n);
    while(n--) {
        scanf("%I64d", &k);
        if(k == 5) five++;
        else cnt++;
    }
    if(five < 9 && cnt == 0) printf("-1");
    else if(five < 9) printf("0\n");
    else if(cnt == 0) printf("-1\n");
    else {
        f = five/9;
        for(int i=1; i<=f; i++) {
            for(int d=1; d<=9; d++) {
                printf("5");
            }
        }
        for(int i=1; i<=cnt; i++) {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
