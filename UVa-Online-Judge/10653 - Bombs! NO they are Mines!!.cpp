//Source Code Written: 7/2/15

#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int mat[N][10001], level[N][N], visited[N][N];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int r, c;
queue< pair<int, int> >q;

int bfs(int s1, int e1, int s2, int e2) {
    while(!q.empty()) q.pop();
    memset(visited, 0, sizeof(visited));
    visited[s1][e1] = 1;
    level[s1][e1] = 0;
    q.push(make_pair(s1, e1));
    while(!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        for(int i=0; i<4; i++) {
            int x = u + dx[i];
            int y = v + dy[i];
            if(x >= 0 && x < r && y >= 0 && y < c && !visited[x][y] && !mat[x][y]) {
                level[x][y] = level[u][v] + 1;
                visited[x][y] = 1;
                q.push(make_pair(x, y));
            }
            if(x == s2 && y == e2) return level[x][y];
        }
        q.pop();
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    while(cin >> r >> c) {
        if(r == 0 && c == 0) break;
        memset(mat, 0, sizeof(mat));
        int n, x, y, m;
        cin >> n;
        while(n--) {
            cin >> x >> m;
            while(m--) {
                cin >> y;
                mat[x][y] = 1;
            }
        }
        int s1, e1, s2, e2;
        cin >> s1 >> e1 >> s2 >> e2;
        cout << bfs(s1, e1, s2, e2) << endl;
    }
    return 0;
}
