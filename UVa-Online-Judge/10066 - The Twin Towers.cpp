//Source Code Written: 12/7/14

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 102;
int n2, n1, arr1[N], arr2[N], dp[N][N];

int call(int p, int q) {
    if(p == n1+1 || q == n2+1) return 0;
    if(dp[p][q] != -1) return dp[p][q];
    int ans = 0;
    if(arr1[p] == arr2[q]) ans = 1 + call(p+1, q+1);
    else {
        ans = max(call(p+1, q), call(p, q+1));
    }
    return dp[p][q] = ans;
}

int main() {
    int tc = 1;
    while(scanf("%d %d", &n1, &n2) == 2) {
        memset(dp, -1, sizeof(dp));
        if(n1 == 0 && n2 == 0) break;
        for(int i=1; i<=n1; i++) cin>> arr1[i];
        for(int i=1; i<=n2; i++) cin>> arr2[i];
        printf("Twin Towers #%d\n", tc++);
        printf("Number of Tiles : %d\n\n", call(1, 1));
    }
    return 0;
}
