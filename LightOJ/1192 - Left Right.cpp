//Source Code Written: 1/4/16

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int k;
        scanf("%d", &k);
        int l, r, xorsum = 0;
        while(k--) {
            scanf("%d %d", &l, &r);
            xorsum ^= (r - l - 1);
        }
        if(xorsum == 0) printf("Case %d: Bob\n", ++tc);
        else printf("Case %d: Alice\n", ++tc);
    }
    return 0;
}
