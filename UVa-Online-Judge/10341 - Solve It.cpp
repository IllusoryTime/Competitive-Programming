//Source Code Written: 6/19/15

#include<bits/stdc++.h>
using namespace std;
double eps = 1e-9;
int main() {
    //freopen("in.txt", "r", stdin);
    double p, q, r, s, t , u;
    while(cin >> p >> q >> r >> s >> t >> u) {
        double low = 0, high = 1, x, ans;
        int cnt = 130;
        while(cnt--) {
            x = (low + high)/2.0;
            ans = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
            if(ans < 0) high = x;
            else low = x;
        }
        if(ans < eps && ans > -eps) printf("%.4lf\n", x);
        else printf("No solution\n");
    }
    return 0;
}
