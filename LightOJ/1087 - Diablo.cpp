//Source Code Written: 8/17/15

#include <stdio.h>
#include <string.h>

#define MAX 131072-1
int tree[2*(MAX+1)+1], position[MAX+1];

void add(int node, int st, int ed, int pos, int id) {
    if(st == ed) {
        tree[node]++;
        position[st] = id;
        return;
    }
    int mid = ( st + ed )/2;
    if(pos <= mid) add(2*node, st, mid, pos, id);
    else add(2*node+1, mid+1, ed, pos, id);
    tree[node]++;
}

void remove_it(int node, int st, int ed, int k) {
    if(st == ed) {
        printf("%d\n", position[st]);
        tree[node]--;
        return;
    }
    int mid = (st + ed)/2;
    if(k <= tree[2*node]) remove_it(2*node, st, mid, k);
    else remove_it(2*node+1, mid+1, ed, k-tree[2*node]);
    tree[node]--;
}

void clear_it(int node, int st, int ed, int k) {
    if(st == ed) {
        tree[node]--;
        return;
    }
    int mid = (st + ed)/2;
    if(k <= tree[2*node]) clear_it(2*node, st, mid, k);
    else clear_it(2*node+1, mid+1, ed, k-tree[2*node]);
    tree[node]--;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    memset(tree, 0, sizeof(tree));
    while(t--) {
        printf("Case %d:\n", ++tc);
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) {
            int id;
            scanf("%d", &id);
            add(1, 0, MAX, i, id);
        }
        scanf("\n");
        while(q--) {
            int x;
            char ch;
            scanf("%c %d\n", &ch, &x);
            if(ch == 'a') {
                add(1, 0, MAX, n++, x);
            } else if(ch == 'c') {
                if(x > tree[1]) printf("none\n");
                else remove_it(1, 0, MAX, x);
            }
        }
        int D = tree[1];
        for(int i=1; i<=D; i++) clear_it(1, 0, MAX, 1);
    }
    return 0;
}
