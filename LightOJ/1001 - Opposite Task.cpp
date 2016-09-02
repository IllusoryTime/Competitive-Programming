//Source Code Written: 1/9/13

#include <stdio.h>

int main() {
    int t, n;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        scanf("%d", &n);
        if(n < 10)
            printf("0 %d\n", n);
        else printf("%d %d\n", n-10, 10);
    }
    return 0;
}

