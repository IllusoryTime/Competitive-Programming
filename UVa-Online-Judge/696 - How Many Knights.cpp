//Source Code Written: 5/24/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    int m, n;
    while(scanf("%d %d", &m, &n) == 2) {
        int ans = 0;
        if(m == 0 && n == 0) break;
        if(m == 1 || n == 1) {
            if(m == 1) ans = n;
            else ans = m;
        } else if(n == 2) {
            ans = (m / 4) * 4;
            if(m % 4 == 1)
                ans += 2;
            else if(m % 4 > 1)
                ans += 4;
        } else if(m == 2) {
            ans = (n / 4) * 4;
            if(n % 4 == 1)
                ans += 2;
            else if(n % 4 > 1)
                ans += 4;
        } else {
            ans = ((m*n)+1)/2;
        }
        printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
    }
    return 0;
}
