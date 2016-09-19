//Source Code Written: 6/3/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, tc = 0;
    cin >> t;
    while(t--) {
        printf("Case %d: ", ++tc);
        int n, d, r, ans = 0;
        cin >> n >> d;
        r = d;
        while(r! = 0) {
            if(r < n) {
                r *= 10;
                r += d;
                ans++;
            } else r %= n;
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
