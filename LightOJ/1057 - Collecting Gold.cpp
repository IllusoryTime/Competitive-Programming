//Source Code Written: 9/6/16

#include <bits/stdc++.h>
using namespace std;

int cnt, dp[(1<<15) + 7][16];
struct st {
    int x, y;
} C[16];

int dst(int p, int q) {
    if(abs(C[p].x - C[q].x) > abs(C[p].y - C[q].y)) return abs(C[p].y - C[q].y) + (abs(C[p].x - C[q].x) - abs(C[p].y - C[q].y));
    else return abs(C[p].x - C[q].x) + (abs(C[p].y - C[q].y) - abs(C[p].x - C[q].x));
}

int call(int mask, int f) {
    if(((1 << cnt) - 1) == mask) {
        return dst(f, 15);
    }
    if(dp[mask][f] != -1) return dp[mask][f];
    int ret = 1 << 26;
    for(int i=0; i<cnt; i++) {
        if((mask & (1 << i)) == 0) {
            ret = min(ret, dst(i, f)  + call((mask | (1 << i)), i));
        }
    }
    return dp[mask][f] = ret;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0, n, m;
    char ch;
    cin >> t;
    while(t--) {
        cnt = 0;
        memset(dp, -1, sizeof dp);
        cin >> m >> n;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cin >> ch;
                if(ch == 'g') C[cnt].x = i, C[cnt++].y = j;
                if(ch == 'x') C[15].x = i, C[15].y = j;
            }
            scanf("\n");
        }
        printf("Case %d: %d\n", ++tc, call(0, 15));
    }
    return 0;
}
