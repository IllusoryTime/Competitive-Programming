//Source Code Written: 3/29/16

#include <bits/stdc++.h>
using namespace std;
const int N = 30010;
int mx, node;
struct INFO {
    int first, second;
    INFO (int X, int Y) {
        first = X;
        second = Y;
    }
};
vector < INFO > edges[N];

vector < int > bfs(int s) {
    vector < int > d(N, 0);
    int v[N];
    memset(v, 0, sizeof v);
    queue < int > q;
    v[s] = 1;
    d[s] = 0;
    mx = 0;
    q.push(s);
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
                if(mx < d[u]) {
                    mx = d[u];
                    node = u;
                }
            }
        }
    }
    return d;
}
int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0, n, u, v, w;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d:\n", ++tc);
        for(int i=0; i<N; i++) edges[i].clear();
        scanf("%d", &n);
        for(int i=0; i<n-1; i++) {
            scanf("%d %d %d", &u, &v, &w);
            edges[u].push_back(INFO(v, w));
            edges[v].push_back(INFO(u, w));
        }
        vector < int > k1 = bfs(0);
        vector < int > k2 = bfs(node);
        vector < int > k3 = bfs(node);
        for(int i=0; i<n; i++)
            printf("%d\n", max(k2[i], k3[i]));
    }
    return 0;
}
