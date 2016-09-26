//Problem Solved: 2/23/15
//Last Edit: 9/27/16

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    long long int a, b, s, sum;
    scanf("%I64d %I64d %I64d", &a, &b, &s);
    sum = abs(a) + abs(b);
    if(sum == s) printf("Yes\n");
    else if(sum < s) {
        if(sum%2 == 0 && s%2 == 0) printf("Yes\n");
        else if(sum%2 == 1 && s%2 == 1) printf("Yes\n");
        else printf("No\n");
    } else printf("No\n");
    return 0;
}
