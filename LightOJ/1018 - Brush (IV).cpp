//Source Code Written: 9/3/16

#include <bits/stdc++.h>
using namespace std;

int n, dp[(1<<16)+9], C[17][2];

struct st {
    int x, y;
};

int cross(int x1, int y1, int x2, int y2) {
    return ((x1*y2) - (x2*y1));
}

st V(int x1, int y1, int x2, int y2) {
    st temp;
    temp.x = x2-x1, temp.y = y2-y1;
    return temp;
}

int call(int mask) {
    int pc = __builtin_popcount(mask);
    if(pc == n) return 0;
    if(n - pc <= 2) return 1;
    if(dp[mask] != -1) return dp[mask];
    int ret = 1<<26, k;
    for(k=0; k<n; k++) {
        if((mask & (1 << k)) == 0)
            break;
    }
    st slope_1, slope_2;
    int tmp_mask = mask | (1 << k), curr_mask;
    for(int i=k+1; i<n; i++) {
        if((tmp_mask & (1 << i)) == 0) {
            curr_mask = tmp_mask | (1 << i);
            slope_1 = V(C[k][0], C[k][1], C[i][0], C[i][1]);
            for(int j=0; j<n; j++) {
                slope_2 = V(C[i][0], C[i][1], C[j][0], C[j][1]);
                if(cross(slope_1.x, slope_1.y, slope_2.x, slope_2.y) == 0)
                    curr_mask |= (1 << j);
            }
            ret = min(ret, call(curr_mask) + 1);
        }
    }
    return dp[mask] = ret;
}
int main() {
//    freopen("in.txt","r",stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d%d", &C[i][0], &C[i][1]);
        }
        printf("Case %d: %d\n", ++tc, call(0));
    }
    return 0;
}
