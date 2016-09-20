//Source Code Written: 9/20/16

#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 26;
int X[] = {1, 1, 0, -1, -1, -1, 0, 1};
int Y[] = {0, 1, 1, 1, 0, -1, -1, -1};
int r, c, matrix[8], dp[8][(1<<8)+7][(1<<8)+7];
char ch;

int call(int now, int prev, int curr) {
    if(now == r) {
        if(prev == ((1 << c) - 1)) return 0;
        else return INF;
    }
    if(dp[now][prev][curr] != -1) return dp[now][prev][curr];
    int ret = INF;
    for(int mask=0; mask<(1<<c); mask++) {
        int next = matrix[now+1], newprev = prev, newcurr = curr;
        for(int i=0; i<c; i++) {
            if((mask & (1 << i)) != 0) {
                newcurr ^= (1 << i);
                for(int j=0; j<8; j++) {
                    int x = now + X[j];
                    int y = i + Y[j];
                    if(x >= 0 && x < r && y >= 0 && y < c) {
                        if(X[j] == -1) newprev ^= (1 << y);
                        if(X[j] == 0) newcurr ^= (1 << y);
                        if(X[j] == 1) next ^= (1 << y);
                    }
                }
            }
        }
        if((newprev == ((1 << c) - 1)) || now == 0)
            ret = min(ret, call(now + 1, newcurr, next) + __builtin_popcount(mask));
    }
    return dp[now][prev][curr] = ret;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d: ", ++tc);
        memset(matrix, 0, sizeof matrix);
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &r, &c);
        for(int i=0; i<r; i++) {
            int mask = 0;
            for(int j=0; j<c; j++) {
                scanf(" %c", &ch);
                if(ch == '*') mask |= (1 << j);
            }
            matrix[i] = mask;
        }
        int ans = call(0, 0, matrix[0]);
        if(ans >= INF) printf("impossible\n");
        else printf("%d\n", ans);
    }
    return 0;
}
