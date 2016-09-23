//Source Code Written: 5/23/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    long long int a, b, z, q;
    while(scanf("%lld %lld", &a, &b) == 2) {
        int r, x = 0, ans = 0;
        if(a == 0 && b == 0) break;
        z = max(a, b);
        q = min(a, b);
        while(z) {
            r = z%10 + q%10 + x;
            z /= 10;
            q /= 10;
            if(r>=10) {
                ans++;
                x = 1;
            } else x = 0;
        }
        if(ans == 0) printf("No carry operation.\n");
        else if(ans == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n", ans);
    }
    return 0;
}
