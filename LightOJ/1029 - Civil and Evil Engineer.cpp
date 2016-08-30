//Source Code Written: 2/13/16

#include <bits/stdc++.h>
using namespace std;

#define edge pair <int, pair<int, int> >
#define MAX 109

vector < edge > graph;
int parent[MAX], N;

int find_parent(int x, int *parent) {
    if(x != parent[x])
        parent[x] = find_parent(parent[x], parent);
    return parent[x];
}

int kruskal() {
    for(int i=0; i<=N; i++) parent[i] = i;
    sort(graph.begin(), graph.end());
    int M = graph.end() - graph.begin(), cost = 0;
    for(int i=0; i<M; i++) {
        int w = graph[i].first;
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        int pu = find_parent(u, parent);
        int pv = find_parent(v, parent);
        if(pu != pv) {
            cost += w;
            parent[pu] = parent[pv];
        }
    }
    for(int i=0; i<=N; i++) parent[i] = i;
    for(int i=M-1; i>=0; i--) {
        int w = graph[i].first;
        int u = graph[i].second.first;
        int v = graph[i].second.second;
        int pu = find_parent(u, parent);
        int pv = find_parent(v, parent);
        if(pu != pv) {
            cost += w;
            parent[pu] = parent[pv];
        }
    }
    return cost;
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &N);
        int u, v, w;
        graph.clear();
        while(scanf("%d%d%d", &u, &v, &w) == 3) {
            if(u == 0 && v == 0 && w == 0) break;
            graph.push_back(edge(w, make_pair(u, v)));
        }
        int avg = kruskal();
        if(avg&1) printf("Case %d: %d/2\n", ++tc, avg);
        else printf("Case %d: %d\n", ++tc, avg/2);
    }
    return 0;
}
