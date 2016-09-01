//Source Code Written: 3/22/16

#include <bits/stdc++.h>
using namespace std;

int n, w[17][17], dp[18][(1<<16)+9];

int Set(int N, int pos){
    return N |= (1<<pos);
}

bool check(int N, int pos){
    return (bool)(N & (1<<pos));
}

int call(int idx, int mask)
{
    if(idx == n)return 0;
    if(dp[idx][mask] != -1) return dp[idx][mask];
    int mx = 0;
    for(int i=0; i<n; i++){
        if(check(mask, i) == 0){
            mx = max(mx, w[idx][i] + call(idx + 1, Set(mask, i)));
        }
    }
    return dp[idx][mask] = mx;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof dp);//Source Code Written: 3/22/16

#include <bits/stdc++.h>
using namespace std;

int n, w[17][17], dp[18][(1<<16)+9];

int Set(int N, int pos) {
    return N |= (1<<pos);
}

bool check(int N, int pos) {
    return (bool)(N & (1<<pos));
}

int call(int idx, int mask) {
    if(idx == n)return 0;
    if(dp[idx][mask] != -1) return dp[idx][mask];
    int mx = 0;
    for(int i=0; i<n; i++) {
        if(check(mask, i) == 0) {
            mx = max(mx, w[idx][i] + call(idx + 1, Set(mask, i)));
        }
    }
    return dp[idx][mask] = mx;
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
        printf("Case %d: %d\n", ++tc, call(0, 0));
    }
    return 0;
}

        scanf("%d", &n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &w[i][j]);
        printf("Case %d: %d\n", ++tc, call(0, 0));
    }
    return 0;
}
