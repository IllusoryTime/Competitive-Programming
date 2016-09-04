//Source Code Written: 3/22/16

#include <bits/stdc++.h>
using namespace std;

int n, dp[(1<<15)+2], w[20];
char save[20][20];

bool check(int N, int pos) {
    return (bool) (N & (1<<pos));
}
int Set(int N, int pos) {
    return N |= (1<<pos);
}

int call(int mask) {
    if(mask == (1 << n)-1) return 0;
    if(dp[mask] != -1) return dp[mask];
    int mn = 1<<28;
    for(int i=0; i<n; i++) {
        if(check(mask, i) == 0) {
            int mx = 1;
            for(int j=0; j<n; j++) {
                if(i != j && check(mask, j) != 0) {
                    mx = max(mx, save[j][i]-'0');
                }
            }
            int ret = w[i]/mx;
            if(w[i] % mx) ret += 1;
            mn = min(mn, ret+call(Set(mask, i)));
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
        for(int i=0; i<n; i++) scanf("%d", &w[i]);
        getchar();
        for(int i=0; i<n; i++) scanf("%s", save[i]);
        printf("Case %d: %d\n", ++tc, call(0));
    }
    return 0;
}
