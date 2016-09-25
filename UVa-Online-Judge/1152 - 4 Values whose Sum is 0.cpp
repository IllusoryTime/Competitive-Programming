//Source Code Written: 7/4/15

#include <bits/stdc++.h>
using namespace std;
long long int a[4000 + 7][4], sum[8000000 + 7], ans;

int main() {
//    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int tc=0; tc<t; tc++) {
        int n, cnt = 0, idx = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%lld %lld %lld %lld", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                sum[idx] = a[i][0] + a[j][1];
                idx++;
            }
        }
        sort(sum, sum + idx);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans = a[i][2] + a[j][3];
                cnt += upper_bound(sum, sum + n*n, -1*ans) - lower_bound(sum, sum + n*n, -1*ans);
            }
        }
        if(tc != 0) printf("\n");
        printf("%d\n", cnt);
    }
    return 0;
}

