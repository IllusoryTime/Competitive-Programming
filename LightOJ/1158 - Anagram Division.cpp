//Source Code Written: 9/22/16

#include <bits/stdc++.h>
using namespace std;

int dp[(1<<10)+9][1001], len, divisor;
string str;

int call(int mask, int reminder) {
    if(mask == (1 << len) - 1) {
        if(reminder == 0) return 1;
        else return 0;
    }
    if(dp[mask][reminder] != -1) {
        return dp[mask][reminder];
    }
    int ans = 0;
    for(int i=0; i<len; i++) {
        if((mask & (1 << i)) == 0) {
            ans += call((mask | (1 << i)), (reminder*10+(str[i]-'0')) % divisor);
        }
    }
    return dp[mask][reminder] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> str >> divisor;
        len = str.size();
        int ans = call(0, 0);
        for(int i=0; i<=9; i++){
            int cnt = 0, factorial = 1;
            for(int j=0; j<len; j++){
                if(str[j]-'0' == i){
                    cnt++;
                }
            }
            for(int k=1; k<=cnt; k++) factorial *= k;
            ans /= factorial;
        }
        printf("Case %d: %d\n", ++tc, ans);
    }
    return 0;
}
