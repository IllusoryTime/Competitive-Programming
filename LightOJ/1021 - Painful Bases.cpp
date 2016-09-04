//Source Code Written: 9/4/16

#include <bits/stdc++.h>
using namespace std;

long long s, base, divisor, dp[(1<<16) + 7][20];
string str;

long long call(long long mask, int mod) {
    if(((1 << s) - 1) == mask) {
        if(mod == 0) return 1;
        else return 0;
    } 
    else if(dp[mask][mod] != -1) return dp[mask][mod];
    
    long long ans = 0, current;
    for(int i=0; i<s; i++) {
        if((mask & (1 << i)) == 0) {
            if(str[i] >= '0' && str[i] <= '9')
                current = str[i] - '0';
            else current = str[i] - 'A' + 10;
            ans += call((mask | (1 << i)), (mod*base+current) % divisor);
        }
    }
    return dp[mask][mod] = ans;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> base >> divisor;
        cin >> str;
        s = str.size();
        printf("Case %d: %lld\n", ++tc, call(0, 0));
    }
    return 0;
}
