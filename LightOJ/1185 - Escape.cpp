//Source Code Written: 3/27/16

#include <bits/stdc++.h>
using namespace std;
const int N = 110;
vector < int > graph[N];
struct node {
    int v, s;
};
int bfs() {
    queue < node > q;
    node A;
    A.v = 1;
    A.s = 1;
    q.push(A);
    int v[N][2], cnt = 0;
    memset(v, 0, sizeof v);
    while(!q.empty()) {
        node t = q.front(), k;
        q.pop();
        for(int i=0; i<graph[t.v].size(); i++) {
            k.v = graph[t.v][i];
            k.s = 1 - t.s;
            if(v[k.v][k.s] != 1) {
                v[k.v][k.s] = 1;
                if(k.s) cnt++;
                q.push(k);
            }
        }
    }
    return cnt;
}
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int n, m, u, v, flag = 0;
        for(int i=0; i<N; i++) graph[i].clear();
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; i++) {

            scanf("%d %d", &u, &v);
            if(u == 1 || v == 1) flag = 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(flag) printf("Case %d: %d\n", ++tc, bfs());
        else printf("Case %d: 0\n", ++tc);
    }
    return 0;
}
