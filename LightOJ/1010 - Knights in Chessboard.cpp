//Source Code Written: 5/24/15

#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d: ", ++tc);
        int m, n, ans = 0;
        scanf("%d %d", &m, &n);
        if(m == 1 || n == 1) {
            if(m == 1) printf("%d\n", n);
            else printf("%d\n", m);
        } else if(n == 2) {
            ans = (m / 4) * 4;
            if(m % 4 == 1)
                ans += 2;
            else if(m % 4 > 1)
                ans += 4;
            printf("%d\n", ans);
        } else if(m == 2) {
            ans = (n / 4) * 4;
            if(n % 4 == 1)
                ans += 2;
            else if(n % 4 > 1)
                ans += 4;
            printf("%d\n", ans);
        } else {
            printf("%d\n", ((m*n)+1)/2);
        }
    }
    return 0;
}
