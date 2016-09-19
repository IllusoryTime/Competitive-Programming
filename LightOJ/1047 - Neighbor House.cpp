//Source Code Written: 12/2/14

#include <iostream>
#include <cstring>
#include <algorithm>

#define inf 1<<18

using namespace std;

int n, mat[22][5], dp[22][5];

int call(int i, int j) {
    if(i == n) return mat[i][j];
    if(dp[i][j] != -1) return dp[i][j];

    int ret, ret1, ret2, ret3;
    ret1 = ret2 = ret3 = inf;
    if(j != 1) ret1 = call(i+1, 1) + mat[i][j];
    if(j != 2) ret2 = call(i+1, 2) + mat[i][j];
    if(j != 3) ret3 = call(i+1, 3) + mat[i][j];

    ret = min(min(ret1, ret2), ret3);
    return dp[i][j] = ret;
}

int main() {
    int t, tc = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> mat[i][1] >> mat[i][2] >> mat[i][3];
        }
        mat[0][0] = 0;
        cout << "Case " << ++tc << ": " << call(0, 0) << endl;
    }
    return 0;
}
