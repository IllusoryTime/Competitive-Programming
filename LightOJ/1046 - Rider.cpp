//Source Code Written: 3/23/16

#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define MAX 11
#define check(tx, ty) (tx >= 0 && tx < n && ty >= 0 && ty < m && vis[tx][ty] == 0)

int n, m, v[MAX][MAX][3];
char mat[MAX][MAX];
int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

void bfs(int sx, int sy, int k) {
    queue < pii > q;
    int vis[MAX][MAX], d[MAX][MAX];
    memset(vis, 0, sizeof vis);
    memset(d, 0, sizeof d);
    vis[sx][sy] = 1;
    d[sx][sy] = 0;
    v[sx][sy][1]++;
    q.push(pii(sx, sy));
    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        for(int i=0; i<8; i++) {
            int tx = top.first + dx[i];
            int ty = top.second + dy[i];
            if(check(tx, ty)) {
                vis[tx][ty] = 1;
                q.push(pii(tx, ty));
                v[tx][ty][1]++;
                d[tx][ty] = d[top.first][top.second] + 1;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            v[i][j][2] += (d[i][j] / k);
            if(d[i][j]%k != 0) v[i][j][2]++;
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d\n", &n, &m);
        for(int i=0; i<n; i++) {
            scanf("%s", mat[i]);
        }
        memset(v, 0, sizeof v);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] != '.') {
                    cnt++;
                    bfs(i, j, mat[i][j] - '0');
                }
            }
        }
        int mn = 1<<28;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(v[i][j][1] == cnt) {
                    mn = min(mn, v[i][j][2]);
                }
            }
        }
        printf("Case %d: %d\n", ++tc, (mn == (1<<28)) ? -1 : mn);
    }
    return 0;
}
