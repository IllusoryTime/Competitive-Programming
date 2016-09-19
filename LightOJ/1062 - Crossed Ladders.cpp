//Source Code Written: 6/12/15

#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
#define eps 1e-9
double x, y, c;

bool ok(double k) {
    double cc = acos(k/y);
    double bb = acos(k/x);
    double aa = (PI-cc-bb);
    double y = sin(bb)*k/sin(aa);
    double h = sin(cc)*y;
    return h <= c + eps;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc=0;
    cin >> t;
    while(t--) {
        cin >> x >> y >> c;
        if(x >= y) swap(x, y);
        double hi, lo, mid;
        lo = 0, hi = x;
        int co = 100;
        while(co--) {
            mid = (lo+hi)/2.0;
            if(ok(mid)) hi = mid;
            else lo = mid;
            mid = (lo+hi)/2.0;
        }
        printf("Case %d: %.8lf\n", ++tc, mid);
    }
    return 0;
}
