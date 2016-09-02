//Source Code Written: 3/11/15

#include <stdio.h>
#include <string.h>

int main() {
    int test, sum = 0, x, n;
    scanf("%d", &test);
    for(int i=1; i<=test; i++) {
        getchar();
        scanf("%d", &n);
        for(int j=1; j<=n; j++) {
            scanf("%d", &x);
            if(x > 0) sum += x;
        }
        printf("Case %d: %d\n",i, sum);
        sum = 0;
    }
    return 0;
}
