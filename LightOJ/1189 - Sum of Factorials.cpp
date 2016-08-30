//Source Code Written: 8/30/16

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    ll a[20], w[20];
    a[0] = 1;
    for(ll i=1; i<=19; i++) a[i] = a[i-1] * i;
    scanf("%d", &t);
    while(t--) {
        ll n, k = 19, flag = 0;
        printf("Case %d: ", ++tc);
        scanf("%lld", &n);
        while(k >= 0) {
            if(n >= a[k])
                n -= a[k], w[flag++] = k;
            k--;
        }
        if(n == 0) {
            for(int i=flag-1; i>=0; i--)
                if(i==flag-1) printf("%d!", w[i]);
                else printf("+%d!", w[i]);
            printf("\n");
        } else printf("impossible\n");
    }
    return 0;
}
