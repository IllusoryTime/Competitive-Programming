//Source Code Written: 6/19/15

#include<bits/stdc++.h>
using namespace std;
int a[100000000];

int main() {
    //freopen("in.txt", "r", stdin);
    int n, q, tc = 0, x;
    while(scanf("%d %d", &n, &q) == 2) {
        if(n == 0 && q == 0) break;
        printf("CASE# %d:\n", ++tc);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        sort(a, a+n);
        while(q--) {
            scanf("%d", &x);
            int l = lower_bound(a, a+n, x) - a;
            if(a[l] == x) printf("%d found at %d\n", x , l+1);
            else printf("%d not found\n", x);
        }
    }
    return 0;
}
