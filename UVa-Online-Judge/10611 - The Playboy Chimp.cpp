//Source Code Written: 6/19/15

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    int n, q, f[50000], m[25000];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &f[i]);
    scanf("%d", &q);
    while(q--) {
        int x, l, i, u;
        scanf("%d", &x);
        l = lower_bound(f, f+n, x) - f;
        for(i=l-1; i>=0; l--) {
            if(f[i] < x) printf("%d ", f[i]);
            break;
        }
        if(i == -1) printf("X ");
        u = upper_bound(f, f+n, x) - f;
        if(u == n) printf("X\n");
        else printf("%d\n", f[u]);
    }
    return 0;
}

