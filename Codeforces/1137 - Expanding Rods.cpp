//Source Code Written: 6/13/15

#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
int main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        double l, n, c;
        cin >> l >> n >> c;
        double s = (1+(n*c))*l;
        double hi = PI, lo = 0, mid;
        for(int i=0; i<=100; i++) {
            mid = (lo+hi)/2.0;
            double r = l/(sin(mid)*2);
            if(r*mid*2 > s) hi = mid;
            else lo=mid;
        }
        double r = l/(sin(mid)*2);
        double h = r*sin((PI/2)-mid);
        printf("Case %d: %.8lf\n", ++tc, r - h);
    }
    return 0;
}
