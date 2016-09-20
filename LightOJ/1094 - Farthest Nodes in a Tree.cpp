//Source Code Written: 3/28/16

#include <bits/stdc++.h>
using namespace std;

const int N = 30010;
int mx;
vector < pair < int, int > > edges[N];

int bfs(int s) {
    int v[N], d[N], node;
    mx = 0;
    queue < int > q;
    memset(v, 0, sizeof(v));
    v[s] = 1;
    q.push(s);
    d[s] = 0;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(int i=0; i<edges[t].size(); i++) {
            int u = edges[t][i].first;
            int w = edges[t][i].second;
            if(!v[u]) {
                q.push(u);
                v[u] = 1;
                d[u] = d[t] + w;
                if(mx < d[u]){
                    mx = d[u];
                    node  = u;
                }
            }
        }
    }
    return node;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0, n, u, v, w;
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<N; i++) edges[i].clear();
        scanf("%d", &n);
        for(int i=0; i<n-1; i++) {
            scanf("%d %d %d", &u, &v, &w);
            edges[u].push_back(make_pair(v, w));
            edges[v].push_back(make_pair(u, w));
        }
        bfs(bfs(0));
        printf("Case %d: %d\n", ++tc, mx);
    }
    return 0;
}
