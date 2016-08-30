//Source Code Written: 3/25/16

#include <bits/stdc++.h>
using namespace std;

#define N 101
#define OO (3.1415926535897923846/4)
#define LL (4.0-(2*OO))
#define check(x, y) (x >= 0 && x < r && y >= 0 && y < c)

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int r, c;
char s[N][N];
struct node {
    int u, v, w;
};

int f(int w) {
    if(w == 0) return 0;
    else if(w % 2 == 0) return ((w/2) - 1);
    else return (int)w/2;
}

int validity(node t, int p, int q, int d) {
    if(s[t.u][t.v] == '0' && (s[p][q] == '0' || s[p][q] == '1')) {
        if(t.w == 2 && (d == 1 || d == 2)) return 0;
        else if(t.w == 3 && (d == 0 || d == 3)) return 0;
    }
    if(s[t.u][t.v] == '1' && (s[p][q] == '0' || s[p][q] == '1')) {
        if(t.w == 2 && (d == 2 || d == 3)) return 0;
        else if(t.w == 3 && (d == 0 || d == 1)) return 0;
    }
    if(s[t.u][t.v] == '0' && s[p][q] == '0') {
        if(t.w == 1) {
            if(d == 0 || d == 3) return 3;
            else if(d == 1 || d == 2) return 2;
        } else return 1;
    } else if(s[t.u][t.v] == '0' && s[p][q] == '1') {
        if(t.w == 1) return 1;
        else if(t.w == 2) {
            if(d == 0) return 3;
            else if(d == 3) return 2;
        } else if(t.w == 3) {
            if(d == 1) return 3;
            else if(d == 2) return 2;
        }
    } else if(s[t.u][t.v] == '1' && s[p][q] == '0') {
        if(t.w == 1) return 1;
        else if(t.w == 2) {
            if(d == 0) return 3;
            else if(d == 1) return 2;
        } else if(t.w == 3) {
            if(d == 2) return 2;
            else if(d == 3) return 3;
        }
    } else if(s[t.u][t.v] == '1' && s[p][q] == '1') {
        if(t.w == 1) {
            if(d == 0 || d == 1) return 3;
            else if(d == 2 || d == 3) return 2;
        } else return 1;
    }
    return 0;
}

void bfs(int x, int y, int z) {
    node s;
    s.u = x;
    s.v = y;
    s.w = z;
    queue < node > q;
    q.push(s);
    int v[N][N][4], cnt1 = 0, cnt2 = 0;
    memset(v, 0, sizeof v);
    v[s.u][s.v][z] = 1;
    if(z == 1) cnt1++;
    else cnt2 ++;
    while(!q.empty()) {
        node t = q.front(), e;
        q.pop();
        for(int i=0; i<4; i++) {
            e.u = t.u + dx[i];
            e.v = t.v + dy[i];
            if(check(e.u, e.v)) {
                e.w = validity(t, e.u, e.v, i);
                if(e.w != 0) {
                    if(v[e.u][e.v][e.w]) continue;
                    q.push(e);
                    v[e.u][e.v][e.w] = 1;
                    if(e.w == 1) cnt1++;
                    else cnt2++;
                }
            }
        }
    }
    printf("%.10lf\n", cnt1 * LL + cnt2 * OO);
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0, q;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &r, &c);
        for(int i=0; i<r; i++) {
            scanf("%s", s[i]);
        }
        printf("Case %d:\n", ++tc);
        scanf("%d", &q);
        while(q--) {
            int x, y;
            scanf("%d %d", &x, &y);
            if((x + y) % 2 == 1) printf("0\n");
            else {
                if(x == 0 && y == 0) {
                    if(s[0][0] == '0') bfs(0, 0, 3);
                    else bfs(0, 0, 1);
                } else if(x == 0) {
                    if(s[0][f(y)] == '0') bfs(0, f(y), 1);
                    else bfs(0, f(y), 2);
                } else if(y == 0) {
                    if(s[f(x)][0] == '0') bfs(f(x), 0, 1);
                    else bfs(f(x), 0, 3);
                } else {
                    if(x % 2 == 1 && y % 2 == 1) bfs(f(x), f(y), 1);
                    else if(s[f(x)][f(y)] == '0') bfs(f(x), f(y), 2);
                    else if(s[f(x)][f(y)] == '1') bfs(f(x), f(y), 1);
                }
            }
        }
    }
    return 0;
}
