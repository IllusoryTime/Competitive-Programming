//Source Code Written: 3/5/15

#include <stdio.h>
#include <math.h>

int main() {
//    freopen("in.txt", "r", stdin);
    double sum = 0, ara[1000005], ans;
    int n, b, test, tc = 0;
    for(int i=1; i<=1000001; i++) {
        sum += log10(i);
        ara[i] = sum;
    }
    scanf("%d", &test);
    while(test--) {
        scanf("%d %d", &n, &b);
        if(n == 0) {
            printf("Case %d: 1\n", ++tc);
        } else {
            ans = int(ara[n]/log10(b)) + 1;
            printf("Case %d: %.0lf\n", ++tc, ans);
        }
    }
    return 0;
}
