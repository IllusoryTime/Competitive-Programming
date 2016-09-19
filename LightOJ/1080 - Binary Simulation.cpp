//Source Code Written: 6/14/13

#include <stdio.h>
#include <string.h>
using namespace std;

#define MAX 100005

int cnt, sum[MAX * 4];
int ara[MAX];
char str[MAX];


void update(int idx, int st, int ed, int i, int j) {
    if(st == i && ed == j) {
        sum[idx]++;
        return;
    }

    int l = idx << 1;
    int r = l + 1;
    int mid = (st + ed)/2;

    if(j <= mid) {
        update(l, st, mid, i, j);
    } else if(mid < i) {
        update(r, mid+1, ed, i, j);
    } else {
        update(l, st, mid, i, mid);
        update(r, mid+1, ed, mid+1, j);
    }
}

int query(int idx, int st, int ed, int pos) {
    if(st == pos && pos == ed) {
        return sum[idx];
    }

    int l = idx << 1;
    int r = l + 1;
    int mid = (st + ed)/2;

    if(pos <= mid) {
        return sum[idx] + query(l, st, mid, pos);
    } else {
        return sum[idx] + query(r, mid+1, ed, pos);
    }
}

int main() {
    int t, tc = 0;
    scanf("%d", &t);
    char cmd[3];
    int p, q;
    while(t--) {
        printf("Case %d:\n", ++tc);
        memset(sum, 0, sizeof sum);
        scanf("%s", str);
        int len = strlen(str);
        for(int i=0; i<len; i++) {
            if(str[i] == '1') {
                update(1, 1, len, i+1, i+1);
            }
        }
        int Q;
        scanf("%d", &Q);
        while(Q--) {
            scanf("%s", cmd);
            if(cmd[0] == 'I') {
                scanf("%d %d", &p, &q);
                update(1, 1, len, p, q);
            } else {
                scanf("%d", &p);
                printf("%d\n", query(1, 1, len, p) % 2);
            }
        }
    }
    return 0;
}

