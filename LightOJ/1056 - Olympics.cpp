//Source Code Written: 6/12/15

#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9

int main() {
    // freopen("in.txt", "r", stdin);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        double a, b, mid, l, w, ang, s, lo, hi, r;
        char ch;
        cin >> a >> ch >> b;
        lo = 0, hi = 400;
        int co = 100;
        while(co--) {
            mid = (lo+hi)/2.0;
            l = mid;
            w = (b/a)*l;
            r = (sqrt(l*l + w*w))/2.0;
            ang = acos(((2*r*r) - w*w)/(2*r*r));
            s = ang*r;
            if((2*s+2*l+eps) <= 400) lo = mid;
            else hi = mid;
        }
        printf("Case %d: %.8lf %.8lf\n",++tc, mid, mid*(b/a));
    }
    return 0;
}
