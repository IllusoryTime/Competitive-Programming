//Source Code Written: 3/22/16

#include <bits/stdc++.h>
using namespace std;
int n, w[20][20], dp[(1<<15)+2];

int Set(int N, int pos) {
    return N |= (1<<pos);
}
bool check(int N, int pos) {
    return (bool)(N & (1<<pos));
}

int call(int mask) {
    if(mask == (1<<n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];
    int mn = 1<<28;
    for(int i=0; i<n; i++) {
        if(check(mask, i) == 0) {
            int price = w[i][i];
            for(int j=0; j<n; j++) {
                if(i != j and check(mask, j) != 0) {
                    price += w[i][j];
                }
            }
            int ret = price + call(Set(mask, i));
            mn = min(mn, ret);
        }
    }
    return dp[mask] = mn;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &w[i][j]);
        printf("Case %d: %d\n", ++tc, call(0));
    }
    return 0;
}
