//Source Code Written: 7/2/15

#include <bits/stdc++.h>
using namespace std;

vector <int> v[21];
int bfs(int st, int ed) {
    int level[21], visited[21];
    queue <int> q;
    while(!q.empty()) q.pop();
    memset(visited, 0, sizeof(visited));
    q.push(st);
    level[st] = 0;
    visited[st] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<v[x].size(); i++) {
            int y = v[x][i];
            if(!visited[y]) {
                level[y] = level[x] + 1;
                visited[y] = 1;
                q.push(y);
            }
            if(y == ed) return level[ed];
        }
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    int tc = 0, n, m, x;
    while(cin >> n) {
        for(int i=0; i<21; i++) v[i].clear();
        printf("Test Set #%d\n", ++tc);
        for(int i=1; i<=19; i++) {
            if(i != 1) cin >> n;
            for(int j=0; j<n; j++) {
                cin >> x;
                v[i].push_back(x);
                v[x].push_back(i);
            }
        }
        cin >> m;
        for(int i=0; i<m; i++) {
            int p, q;
            cin >> p >> q;
            printf("%2d to %2d: %d\n", p, q, bfs(p, q));
        }
        printf("\n");
    }
    return 0;
}
