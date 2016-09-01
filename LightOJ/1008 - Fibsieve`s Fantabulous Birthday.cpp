//Source Code Written: 12/4/14

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
typedef long long int ll;

int main() {
    int t, tc = 1;
    ll k, a, s, d;
    cin >> t;
    while(t--) {
        cin >> k;
        d = pow(k, 0.5);
        if(d*d == k && d%2 == 1) {
            printf("Case %d: 1 %lld\n", tc++, d);
        } else if(d*d == k && d%2 == 0) {
            printf("Case %d: %lld 1\n", tc++, d);
        } else {
            s = k - d * d;
            a = s - d - 1;
            if(d%2 == 1) {
                if(a > 0) printf("Case %d: %lld %lld\n", tc++, d+1, d+1-a);
                else printf("Case %d: %lld %lld\n", tc++, s, d+1);
            } else {
                if(a > 0) printf("Case %d: %lld %lld\n", tc++, d+1-a, d+1);
                else printf("Case %d: %lld %lld\n", tc++, d+1, s);
            }
        }
    }
    return 0;
}
