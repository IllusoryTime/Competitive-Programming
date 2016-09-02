//Source Code Written: 3/28/16

#include <bits/stdc++.h>
using namespace std;

const int N = 21;
typedef pair < int, int > pii;
int d[N][N], v[N][N], cell[N][N], x, y, sx, sy;
#define check(tx, ty) (tx >= 0 && tx < x && ty >= 0 && ty < y && v[tx][ty] == 0 && cell[tx][ty] != '#')

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int bfs() {
    memset(v, 0, sizeof(v));
    int cnt = 0;
    v[sx][sy] = 1;
    queue < pii > q;
    q.push(pii(sx, sy));
    d[sx][sy] = 0;
    while(!q.empty()) {
        pii t = q.front();
        q.pop();
        for(int k=0; k<4; k++) {
            int tx = t.first + fx[k];
            int ty = t.second + fy[k];
            if(check(tx, ty)) {
                v[tx][ty] = 1;
                d[tx][ty] = d[t.first][t.second] + 1;
                q.push(pii(tx, ty));
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ///freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d\n", &x, &y);
        for(int i=0; i<y; i++) {
            for(int j=0; j<x; j++) {
                scanf("%c", &cell[j][i]);
                if(cell[j][i] == '@') {
                    sx = j;
                    sy = i;
                }
            }
            getchar();
        }
        printf("Case %d: %d\n", ++tc, bfs() + 1);
    }
    return 0;
}
