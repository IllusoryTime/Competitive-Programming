//Source Code Written: 6/18/13

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>

#define MAX1 1000+3
#define MAX2 100+3
#define MAX3 30+3

int dp[MAX1][MAX3];
int cost[MAX1], weight[MAX1], n, g, gw[MAX2];

int call(int i, int w, int j) {
    if(i == n+1) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    int profit1 = 0, profit2 = 0;

    if(w+weight[i] <= gw[j]) profit1 = cost[i] + call(i+1, w+weight[i], j);
    else profit1 = 0;

    profit2 = call(i+1, w, j);

    dp[i][w] = std::max(profit1, profit2);
    return dp[i][w];
}

int main() {
//    freopen("in", "r", stdin);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int profit = 0;
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d %d", &cost[i], &weight[i]);
        }
        scanf("%d", &g);
        for(int j=1; j<=g; j++) {
            memset(dp, -1, sizeof(dp));
            scanf("%d", &gw[j]);
            profit += call(1, 0, j);
        }
        printf("%d\n", profit);
        profit = 0;
    }
    return 0;
}
