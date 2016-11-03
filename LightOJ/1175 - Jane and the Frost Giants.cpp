//Source Code Written: 3/24/16

#include <bits/stdc++.h>
using namespace std;
#define pii pair < int, int >
#define N 210
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int n, m, a[N*N][4], cnt;
char mat[N][N];
#define check(x, y) (x >=0 && x < n && y >= 0 && y < m)
int bfs(int p, int q) {
    int v1[N][N], v2[N][N], d1[N][N], d2[N][N];
    queue < pii > q1;
    queue < pii > q2;
    memset(v1, 0, sizeof v1);
    memset(v2, 0, sizeof v2);
    memset(d1, 0, sizeof d1);
    memset(d2, 0, sizeof d2);
    q1.push(pii(p, q));
    v1[p][q] = 1;
    d1[p][q] = 0;
    for(int i=0; i<cnt; i++) {
        q2.push(pii(a[i][1], a[i][2]));
        v2[a[i][1]][a[i][2]] = 1;
        d2[a[i][1]][a[i][2]] = 0;
    }
    while(!q2.empty()) {
        pii t2 = q2.front();
        q2.pop();
        for(int i=0; i<4; i++) {
            int tx = t2.first + dx[i];
            int ty = t2.second + dy[i];
            if(check(tx, ty)) {
                if(v2[tx][ty] == 1) continue;
                if(mat[tx][ty] == '#' || mat[tx][ty] == 'F') continue;
                d2[tx][ty] = d2[t2.first][t2.second] + 1;
                q2.push(pii(tx, ty));
                v2[tx][ty] = 1;
            }
        }
    }
    while(!q1.empty()) {
        pii t1 = q1.front();
        q1.pop();
        for(int i=0; i<4; i++) {
            int tx = t1.first + dx[i];
            int ty = t1.second + dy[i];
            if(check(tx, ty)) {
                if(v1[tx][ty] == 1) continue;
                if(mat[tx][ty] == '#' || mat[tx][ty] == 'F') continue;
                v1[tx][ty] = 1;
                d1[tx][ty] = d1[t1.first][t1.second] + 1;
                if(d1[tx][ty] < d2[tx][ty] || !d2[tx][ty]) q1.push(pii(tx, ty));

            } else {
                return d1[t1.first][t1.second];
            }
        }
    }
    return -1;
}
int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int p, q;
        cnt = 0;
        memset(a, 0, sizeof a);
        scanf("%d %d\n", &n, &m);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%c", &mat[i][j]);
                if(mat[i][j] == 'J') p = i, q = j;
                if(mat[i][j] == 'F') a[cnt][1] = i, a[cnt++][2] = j;
            }
            getchar();
        }
        int ans = bfs(p, q);
        printf("Case %d: ", ++tc);
        if(ans == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans + 1);
    }
    return 0;
}
