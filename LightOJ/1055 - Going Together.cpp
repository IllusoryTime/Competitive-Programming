//Source Code Written: 3/26/16

#include <bits/stdc++.h>
using namespace std;

#define N 10
struct node {
    int x1, x2, x3, y1, y2, y3, z1, z2, z3;
} T;
int n, S[4][3];
char s[N][N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

node order(node w, int i) {
    int o1, o2, o3;
    if(i == 0) {
        if(w.x1 >= w.x2 && w.x1 >= w.x3) o1 = 1;
        else if(w.x2 >= w.x1 && w.x2 >= w.x3) o1 = 2;
        else if(w.x3 >= w.x1 && w.x3 >= w.x2) o1 = 3;
        if(o1 == 1) {
            if(w.x2 >= w.x3) o2 = 2, o3 = 3;
            else o2 = 3, o3 = 2;
        } else if(o1 == 2) {
            if(w.x1 >= w.x3) o2 = 1, o3 = 3;
            else o2 = 3, o3 = 1;
        } else if(o1 == 3) {
            if(w.x1 >= w.x2) o2 = 1, o3 = 2;
            else o2 = 2, o3 = 1;
        }
    } else if(i == 1) {
        if(w.x1 <= w.x2 && w.x1 <= w.x3) o1 = 1;
        else if(w.x2 <= w.x1 && w.x2 <= w.x3) o1 = 2;
        else if(w.x3 <= w.x1 && w.x3 <= w.x2) o1 = 3;
        if(o1 == 1) {
            if(w.x2 <= w.x3) o2 = 2, o3 = 3;
            else o2 = 3, o3 = 2;
        } else if(o1 == 2) {
            if(w.x1 <= w.x3) o2 = 1, o3 = 3;
            else o2 = 3, o3 = 1;
        } else if(o1 == 3) {
            if(w.x1 <= w.x2) o2 = 1, o3 = 2;
            else o2 = 2, o3 = 1;
        }
    } else if(i == 2) {
        if(w.y1 >= w.y2 && w.y1 >= w.y3) o1 = 1;
        else if(w.y2 >= w.y1 && w.y2 >= w.y3) o1 = 2;
        else if(w.y3 >= w.y1 && w.y3 >= w.y2) o1 = 3;
        if(o1 == 1) {
            if(w.y2 >= w.y3) o2 = 2, o3 = 3;
            else o2 = 3, o3 = 2;
        } else if(o1 == 2) {
            if(w.y1 >= w.y3) o2 = 1, o3 = 3;
            else o2 = 3, o3 = 1;
        } else if(o1 == 3) {
            if(w.y1 >= w.y2) o2 = 1, o3 = 2;
            else o2 = 2, o3 = 1;
        }
    } else if(i == 3) {
        if(w.y1 <= w.y2 && w.y1 <= w.y3) o1 = 1;
        else if(w.y2 <= w.y1 && w.y2 <= w.y3) o1 = 2;
        else if(w.y3 <= w.y1 && w.y3 <= w.y2) o1 = 3;
        if(o1 == 1) {
            if(w.y2 <= w.y3) o2 = 2, o3 = 3;
            else o2 = 3, o3 = 2;
        } else if(o1 == 2) {
            if(w.y1 <= w.y3) o2 = 1, o3 = 3;
            else o2 = 3, o3 = 1;
        } else if(o1 == 3) {
            if(w.y1 <= w.y2) o2 = 1, o3 = 2;
            else o2 = 2, o3 = 1;
        }
    }
    node k;
    if(o1 == 1) {
        k.x1 = w.x1;
        k.y1 = w.y1;
        k.z1 = w.z1;
    } else if(o1 == 2) {
        k.x1 = w.x2;
        k.y1 = w.y2;
        k.z1 = w.z2;
    } else if(o1 == 3) {
        k.x1 = w.x3;
        k.y1 = w.y3;
        k.z1 = w.z3;
    }
    if(o2 == 1) {
        k.x2 = w.x1;
        k.y2 = w.y1;
        k.z2 = w.z1;
    } else if(o2 == 2) {
        k.x2 = w.x2;
        k.y2 = w.y2;
        k.z2 = w.z2;
    } else if(o2 == 3) {
        k.x2 = w.x3;
        k.y2 = w.y3;
        k.z2 = w.z3;
    }
    if(o3 == 1) {
        k.x3 = w.x1;
        k.y3 = w.y1;
        k.z3 = w.z1;
    } else if(o3 == 2) {
        k.x3 = w.x2;
        k.y3 = w.y2;
        k.z3 = w.z2;
    } else if(o3 == 3) {
        k.x3 = w.x3;
        k.y3 = w.y3;
        k.z3 = w.z3;
    }
    return k;
}

node sort_it(node w) {
    int o1, o2, o3;
    if(w.z1 == 1) o1 = 1;
    if(w.z2 == 1) o1 = 2;
    if(w.z3 == 1) o1 = 3;
    if(w.z1 == 2) o2 = 1;
    if(w.z2 == 2) o2 = 2;
    if(w.z3 == 2) o2 = 3;
    if(w.z1 == 3) o3 = 1;
    if(w.z2 == 3) o3 = 2;
    if(w.z3 == 3) o3 = 3;
    node k;
    if(o1 == 1) {
        k.x1 = w.x1;
        k.y1 = w.y1;
        k.z1 = w.z1;
    } else if(o1 == 2) {
        k.x1 = w.x2;
        k.y1 = w.y2;
        k.z1 = w.z2;
    } else if(o1 == 3) {
        k.x1 = w.x3;
        k.y1 = w.y3;
        k.z1 = w.z3;
    }
    if(o2 == 1) {
        k.x2 = w.x1;
        k.y2 = w.y1;
        k.z2 = w.z1;
    } else if(o2 == 2) {
        k.x2 = w.x2;
        k.y2 = w.y2;
        k.z2 = w.z2;
    } else if(o2 == 3) {
        k.x2 = w.x3;
        k.y2 = w.y3;
        k.z2 = w.z3;
    }
    if(o3 == 1) {
        k.x3 = w.x1;
        k.y3 = w.y1;
        k.z3 = w.z1;
    } else if(o3 == 2) {
        k.x3 = w.x2;
        k.y3 = w.y2;
        k.z3 = w.z2;
    } else if(o3 == 3) {
        k.x3 = w.x3;
        k.y3 = w.y3;
        k.z3 = w.z3;
    }
    return k;
}

int v[N][N][N][N][N][N], d[N][N][N][N][N][N];

int bfs() {
    queue < node > q;
    T = sort_it(T);
    q.push(T);
    memset(v, 0, sizeof v);
    v[T.x1][T.y1][T.x2][T.y2][T.x3][T.y3] = 1;
    d[T.x1][T.y1][T.x2][T.y2][T.x3][T.y3] = 0;
    while(!q.empty()) {
        node t = q.front(), b;
        q.pop();
        int cost = d[t.x1][t.y1][t.x2][t.y2][t.x3][t.y3];
        if((t.x1 == S[0][0] && t.y1 == S[0][1]) || (t.x1 == S[1][0] && t.y1 == S[1][1]) || (t.x1 == S[2][0] && t.y1 == S[2][1])) {
            if((t.x2 == S[0][0] && t.y2 == S[0][1]) || (t.x2 == S[1][0] && t.y2 == S[1][1]) || (t.x2 == S[2][0] && t.y2 == S[2][1])) {
                if((t.x3 == S[0][0] && t.y3 == S[0][1]) || (t.x3 == S[1][0] && t.y3 == S[1][1]) || (t.x3 == S[2][0] && t.y3 == S[2][1])) {
                    return d[t.x1][t.y1][t.x2][t.y2][t.x3][t.y3];
                }
            }
        }
        for(int i=0; i<4; i++) {
            node r = order(t, i);
            b.x1 = r.x1 + dx[i];
            b.y1 = r.y1 + dy[i];
            b.x2 = r.x2 + dx[i];
            b.y2 = r.y2 + dy[i];
            b.x3 = r.x3 + dx[i];
            b.y3 = r.y3 + dy[i];
            b.z1 = r.z1;
            b.z2 = r.z2;
            b.z3 = r.z3;

            if(!(b.x1 >= 0 && b.x1 < n && b.y1 >= 0 && b.y1 < n && s[b.x1][b.y1] != '#') ) {
                b.x1 = r.x1;
                b.y1 = r.y1;
            }
            if(!(b.x2 >= 0 && b.x2 < n && b.y2 >= 0 && b.y2 < n && s[b.x2][b.y2] != '#') || (b.x2 == b.x1 && b.y2 == b.y1)) {
                b.x2 = r.x2;
                b.y2 = r.y2;
            }
            if(!(b.x3 >= 0 && b.x3 < n && b.y3 >= 0 && b.y3 < n && s[b.x3][b.y3] != '#') || ((b.x3 == b.x2 && b.y3 == b.y2) || (b.x3 == b.x1 && b.y3 == b.y1))) {
                b.x3 = r.x3;
                b.y3 = r.y3;
            }
            b = sort_it(b);
            if(v[b.x1][b.y1][b.x2][b.y2][b.x3][b.y3] != 1) {
                q.push(b);
                v[b.x1][b.y1][b.x2][b.y2][b.x3][b.y3] = 1;
                d[b.x1][b.y1][b.x2][b.y2][b.x3][b.y3] = cost + 1;
            }
        }
    }
    return -1;
}

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int cnt = 0;
        scanf("%d\n", &n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%c", &s[i][j]);
                if(s[i][j] == 'A') T.x1 = i, T.y1 = j, T.z1 = 1;
                if(s[i][j] == 'B') T.x2 = i, T.y2 = j, T.z2 = 2;
                if(s[i][j] == 'C') T.x3 = i, T.y3 = j, T.z3 = 3;
                if(s[i][j] == 'X') S[cnt][0] = i, S[cnt++][1] = j;
            }
            getchar();
        }
        int ans = bfs();
        if(ans == -1) printf("Case %d: trapped\n", ++tc);
        else printf("Case %d: %d\n", ++tc, ans);
    }
    return 0;
}
