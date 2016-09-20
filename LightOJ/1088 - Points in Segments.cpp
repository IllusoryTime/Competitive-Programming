//Source Code Written: 6/12/15

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int n, q, x, y, a[100000+7];
        printf("Case %d:\n", ++tc);
        scanf("%d %d", &n, &q);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(int i=0; i<q; i++) {
            scanf("%d %d", &x, &y);
            int st = lower_bound(a, a+n, x) - a;
            int ed = upper_bound(a, a+n, y) - a;
            printf("%d\n", ed-st);
        }
    }
    return 0;
}
