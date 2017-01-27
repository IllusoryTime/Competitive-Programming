//Source Code Written: 1/27/17

#include <bits/stdc++.h>
using namespace std;
int f(int t, int n, int c) {
    return t*c - t*t*n;
}
int main() {
//    freopen("in.txt", "r", stdin);
    int t, n, c, tc = 0, ans;
    cin >> t;
    while(t--) {
        cin >> n >> c;
        if(n == 0) ans = 0;
        else {
            ans = c/(2*n);
            if(f(ans, n, c) < f(ans+1, n, c)) ans++;
        }
        printf("Case %d: %d\n", ++tc, ans);
    }
    return 0;
}
