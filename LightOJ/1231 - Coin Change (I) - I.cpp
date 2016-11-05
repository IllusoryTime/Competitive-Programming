//Source Code Written: 11/30/14

#include <stdio.h>
#include <string.h>

int mod = 100000007;

int dp[51][1001];
int make;
int indx[51];
int n;
int coin[51];

int call(int i, int amount) {
    if(i == n) {
        if(amount == make) return 1;
        else return 0;
    }
    if (dp[i][amount] != -1) return dp[i][amount];

    int ret = 0;
    for(int k=0; k<=indx[i]; k++) {
        if(amount+coin[i]*k <= make) {
            ret += call(i+1, amount+coin[i]*k)%mod;
        } else break;
    }
    return dp[i][amount] = (ret%mod);
}

int main() {
    int testcases;
    scanf("%d", &testcases);
    for(int i=1; i<=testcases; i++) {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &n, &make);
        for(int j=0; j<n; j++) scanf("%d", &coin[j]);
        for(int k=0; k<n; k++) scanf("%d", &indx[k]);
        printf("Case %d: %d\n", i, call(0, 0));
    }
    return 0;
}
