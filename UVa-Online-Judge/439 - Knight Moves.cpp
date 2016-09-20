//Source Code Written: 7/2/15

#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define check(tx, ty) (tx >= 1 && tx <= 8 && ty>= 1 && ty <= 8 && vis[tx][ty] == 0)

int d[11][11], vis[11][11], row, col;
int fx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int fy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs(int sx, int sy, int x, int y) {
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    queue <pii> q;
    q.push(pii(sx, sy));
    d[sx][sy] = 0;
    while(!q.empty()) {
        pii top = q.front();
        q.pop();
        for(int k=0; k<8; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];
            if(check(tx, ty)) {
                vis[tx][ty] = 1;
                d[tx][ty] = d[top.first][top.second] + 1;
                q.push(pii(tx, ty));
                if(tx == x && ty == y) return d[tx][ty];
            }
        }
    }
}

int main() {
    ///freopen("in.txt", "r", stdin);
    string str;
    while(getline(cin, str)) {
        int ans = bfs(str[0]-'a'+1, str[1]-'1'+1, str[3]-'a'+1, str[4]-'1'+1);
        printf("To get from %c%c to %c%c takes %d knight moves.\n", str[0], str[1], str[3], str[4], ans);
    }
    return 0;
}
