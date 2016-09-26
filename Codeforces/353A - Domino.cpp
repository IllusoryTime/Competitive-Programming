//Problem Solved: 10/11/13
//Last Edit: 9/27/16

#include <stdio.h>

int main() {
    int n, x, y, sum1 = 0, sum2 = 0, k = 0, a, s;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &x, &y);
        if((!(x%2) && (y%2)) || ((x%2) && !(y%2))) k++;
        sum1 +=x;
        sum2 +=y;
    }
    a = sum1%2;
    s = sum2%2;
    if(!a && !s) printf("0\n");
    else if(a && s && k) printf("1\n");
    else printf("-1\n");
    return 0;
}
