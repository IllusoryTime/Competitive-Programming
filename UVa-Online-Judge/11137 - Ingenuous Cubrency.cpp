//Source Code Written: 12/1/14

#include <stdio.h>
#include <string.h>

typedef long long int LL;
LL dp[22][10000+1], make;
int coin[] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};

LL call(int i, int p) {
    if(i >= 21) {
        if(p==0) return 1;
        else return 0;
    }
    if(dp[i][p] != -1) return dp[i][p];
    LL ret1 = 0, ret2 = 0;
    if(p-coin[i] >= 0) ret1 = call(i, p-coin[i]);
    ret2 = call(i+1, p);
    return dp[i][p] = ret1 + ret2;
}

int main() {
    memset(dp, -1, sizeof(dp));
    call(0, 10000);
    while(scanf("%lld",&make) == 1) {
        printf("%lld\n", dp[0][make]);
    }
    return 0;
}
