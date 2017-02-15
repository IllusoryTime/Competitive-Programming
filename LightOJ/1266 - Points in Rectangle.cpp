//Source Code Written: 9/8/15

#include <bits/stdc++.h>
using namespace std;
#define maxX 1005
#define maxY 1005
int tree[maxX][maxY], flag[maxX][maxY];

void update(int x, int y) {
    for(int i=x; i<=1001; i+=i&-i)
        for(int j=y; j<=1001; j+=j&-j)
            tree[i][j]++;
}

int read(int x, int y) {
    int sum = 0;
    for(int i=x; i>0; i-=i&-i)
        for(int j=y; j>0; j-=j&-j)
            sum += tree[i][j];
    return sum;
}

int query(int x1, int y1, int x2, int y2) {
    return read(x2, y2) - read(x2, y1-1) - read(x1-1, y2) + read(x1-1, y1-1);
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0, q;
    scanf("%d", &t);
    while(t--) {
        memset(tree, 0, sizeof(tree));
        memset(flag, 0, sizeof(flag));
        printf("Case %d:\n", ++tc);
        scanf("%d", &q);
        while(q--) {
            int x, x1, y1, x2, y2;
            scanf("%d", &x);
            if(x == 0) {
                scanf("%d %d", &x1, &y1);
                x1++; y1++;
                if(!flag[x1][y1]) {
                    flag[x1][y1] = 1;
                    update(x1, y1);
                }
            } else if(x == 1) {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++; y1++; x2++; y2++;
                printf("%d\n", query(x1, y1, x2, y2));
            }
        }
    }
    return 0;
}
