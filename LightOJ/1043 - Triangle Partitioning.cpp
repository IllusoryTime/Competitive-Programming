//Source Code Written: 3/23/15

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, tc = 0;
    cin >> t;
    while(t--) {
        double a, b, c, r;
        cin >> a >> b >> c >> r;
        r = (1/r) + 1;
        r = sqrt(r);
        r = a/r;
        printf("Case %d: %.8lf\n", ++tc, r);
    }
    return 0;
}
