//Source Code Written: 12/3/14

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long int ll;
const int N = 202;

int n, r, c, t;
ll dp[N][N], mat[N][N];

ll call(int i, int j) {

    if(i > n) c = 2*n - i;
    else c = i;
    if(i >= 1 && i <= r && j >= 1 && j <= c) {
        ll ret, ret1 = 0, ret2 = 0, ret3 = 0;
        if(dp[i][j] != -1) return dp[i][j];
        ret1 = call(i+1, j) + mat[i][j];
        if(i < n) ret2 = call(i+1, j+1) + mat[i][j];
        if(i >= n) ret3 = call(i+1, j-1) + mat[i][j];
        ret = max(max(ret1, ret2), ret3);
        return dp[i][j] = ret;
    } else return 0;
}

int main() {
    cin >> t;
    for(int i=1; i<=t; i++) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        r = 2*n - 1;
        for(int j=1; j<=2*n-1; j++) {
            if(j <= n) {
                for(int k=1; k<=j; k++) cin >> mat[j][k];
            } else {
                for(int k=1; k<=2*n-j; k++) cin >> mat[j][k];
            }
        }
        printf("Case %d: %lld\n", i, call(1, 1));
    }
    return 0;
}
