//Source Code Written: 2/6/16

#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> PII;
const int INF = 2000000000;

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int N, M, MAX;
        scanf("%d%d", &N, &M);
        MAX =  N + 10;
        vector < vector <PII> > edges(MAX);
        for(int i=0; i<M; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            edges[u].push_back(make_pair(w, v));
            edges[v].push_back(make_pair(w, u));
        }
        int s = 0, t = N - 1;
        priority_queue< PII, vector <PII>, greater <PII> > Q;
        vector <int> d(MAX, INF), path(MAX, -1);
        Q.push (make_pair (0, s));
        d[s] = 0;
        while(!Q.empty()) {
            PII top = Q.top();
            int u = top.second;
            if(u == t) break;
            Q.pop();
            for(vector <PII>::iterator it = edges[u].begin(); it != edges[u].end(); it++) {
                int v = it->second, w = it->first;
                if(d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    path[v] = u;
                    Q.push(make_pair(d[v], v));
                }
            }
        }
        printf("Case %d: ", ++tc);
        if(d[t] != INF) printf("%d\n", d[t]);
        else printf("Impossible\n");
    }
    return 0;
}
