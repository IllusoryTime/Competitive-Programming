//Source Code Written: 6/1/14
//Using Segment Tree

#include <stdio.h>
#define N 100005

int a[N], tree[N*3];

void init (int n, int b, int e, int i, int v) {
    if(b == i && e == i) {
        tree[n] = v;
        return;
    }
    int mid = (b+e)/2;
    if (i <= mid) init(2*n, b, mid, i, v);
    else init(2*n+1, mid+1, e, i, v);
    tree[n] = tree[2*n] + tree[2*n+1];
}

int quer(int idx, int st, int ed, int i, int j) {
    if(i == st && j == ed) return tree[idx];
    int mid = (st+ed)/2;
    if(j <= mid) {
        return quer(2*idx, st, mid, i, j);
    } else if(i > mid) {
        return quer(2*idx+1, mid+1, ed, i, j);
    } else return  (quer(2*idx, st, mid, i, mid) + quer(2*idx+1, mid+1, ed, mid+1, j));
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, i, j, q, n, q1, a1, a2, a3, a4, a5, num;
    scanf("%d", &t);
    for(j=1; j<=t; j++){
        printf("Case %d:\n", j);
        scanf("%d %d", &n, &q);
        for(i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            num = a[i];
            init(1, 1, n, i, num);
        }
        for(i=1; i<=q; i++) {
            scanf("%d", &q1);
            if(q1==1) {
                scanf("%d", &a1);
                printf("%d\n", a[a1+1]);
                a[a1+1] = 0;
                init(1, 1, n, a1+1, 0);
            }
            if(q1==2) {
                scanf("%d %d", &a2, &a3);
                a[a2+1] += a3;
                init(1, 1, n, a2+1, a[a2+1]);
            }
            if(q1==3) {
                scanf("%d %d", &a4, &a5);
                printf("%d\n", quer(1, 1, n, a4+1, a5+1));
            }
        }
    }
    return 0;
}
