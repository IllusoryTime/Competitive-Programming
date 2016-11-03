//Source Code Written: 2/6/16

#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
const int INF = 1000000000;
int N, M, MAX, s, t;
vector <int> Dijkstra(vector < vector<PII> > edges, int s) {
    priority_queue <PII, vector<PII>, greater<PII> > Q;
    vector <int> d(MAX, INF);
    Q.push (make_pair (0, s));
    d[s] = 0;
    while(!Q.empty()) {
        PII top = Q.top();
        int u = top.second;
        Q.pop();
        for(vector<PII>::iterator it = edges[u].begin(); it != edges[u].end(); it++) {
            int v = it->second, w = it->first;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                Q.push(make_pair(d[v], v));
            }
        }
    }
    return d;
}
int main() {
    ///freopen("in.txt", "r", stdin);
    int T, tc = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        MAX =  N + 10;
        vector<vector<PII> > edges(MAX);
        for(int i=0; i<M; i++) {
            int u, v, w = 1;
            scanf("%d%d", &u, &v);
            edges[u].push_back(make_pair(w, v));
            edges[v].push_back(make_pair(w, u));
        }
        scanf("%d%d", &s, &t);
        vector <int> yoo = Dijkstra(edges, s);
        vector <int> bro = Dijkstra(edges, t);
        int mx = 0;
        for(int i=0; i<N; i++) mx = max(mx, yoo[i] + bro[i]);
        printf("Case %d: %d\n", ++tc, mx);
    }
    return 0;
}
