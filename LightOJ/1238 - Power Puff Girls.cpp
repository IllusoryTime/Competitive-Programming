//Source Code Written: 3/28/16

#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define MAXX 22
#define MAXY 22
int d[MAXX][MAXY], vis[MAXX][MAXY], vis_again[MAXX][MAXY], cell[MAXX][MAXY], x, y, row, col;
#define check(tx, ty) (tx >= 0 && tx < x && ty >= 0 && ty < y && vis[tx][ty] == 0 && cell[tx][ty] != '#' && cell[tx][ty] != 'm')
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int bfs(int sx, int sy) {
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    queue <pii> q;
    q.push(pii(sx, sy));
    d[sx][sy] = 0;
    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        for(int k=0; k<4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];
            if(check(tx, ty)) {
                vis[tx][ty] = 1;
                d[tx][ty] = d[top.first][top.second] + 1;
                q.push(pii(tx, ty));
                if(cell[tx][ty] == 'h') return d[tx][ty];
            }
        }
    }
}

int main() {
    ///freopen("in.txt", "r", stdin);
    int n, sx1, sy1, sx2, sy2, sx3, sy3, tc = 0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &x, &y);
        getchar();
        for(int i=0; i<x; i++) {
            for(int j=0; j<y; j++) {
                scanf("%c", &cell[i][j]);
                if(cell[i][j] == 'a') {
                    sx1 = i;
                    sy1 = j;
                }
                if(cell[i][j] == 'b') {
                    sx2 = i;
                    sy2 = j;
                }
                if(cell[i][j] == 'c') {
                    sx3 = i;
                    sy3 = j;
                }
            }
            getchar();
        }
        int time = 0;
        time = max(time, bfs(sx1, sy1));
        time = max(time, bfs(sx2, sy2));
        time = max(time, bfs(sx3, sy3));
        printf("Case %d: %d\n", ++tc, time);
    }
    return 0;
}
