//Source Code Written: 9/7/15
//Using Binary Indexed Tree

#include <bits/stdc++.h>
using namespace std;

int a[100000 + 9], tree[100000 + 9];
void update(int idx, int v, int n) {
    while(idx <= n) {
        tree[idx] += v;
        idx += idx & (-idx);
    }
}

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        memset(tree, 0, sizeof(tree));
        printf("Case %d:\n", ++tc);
        int n, q;
        scanf("%d %d", &n, &q);        
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            update(i, a[i], n);
        }
        while(q--) {
            int o, i, j, v;
            scanf("%d", &o);
            if(o == 1) {
                scanf("%d", &i);
                printf("%d\n", a[i+1]);
                update(i+1, -a[i+1], n);
                a[i+1] = 0;
            } else if(o == 2) {
                scanf("%d %d", &i, &v);       
                a[i+1] += v;
                update(i+1, v, n);
            } else if(o == 3) {
                scanf("%d %d", &i, &j);                
                printf("%d\n", query(j+1) - query(i));
            }
        }
    }
    return 0;
}
