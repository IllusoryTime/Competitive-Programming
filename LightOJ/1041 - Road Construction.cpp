#include <bits/stdc++.h>
using namespace std;

#define MAX 100
#define edge pair < int, pair <int, int> >

vector < edge > graph;
map < string, int > mp;
int parent[MAX], N, M;

int find_parent(int x, int *parent) {
    if(x != parent[x])
        parent[x] = find_parent(parent[x], parent);
    return parent[x];
}

int kruskal() {
    int cnt = 0, cost = 0;
    for(int i=0; i<=N; i++) parent[i] = i;
    sort(graph.begin(), graph.end());
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
    for(int i=1; i<N; i++) if(parent[i] == i) cnt++;
    if(cnt >= 2) printf("Impossible\n");
    else printf("%d\n", cost);
}

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        graph.clear();
        mp.clear();
        printf("Case %d: ", ++tc);
        N = 1;
        scanf("%d", &M);
        for(int i=0; i<M; i++) {
            string str1, str2; int w;
            cin >> str1 >> str2 >> w;
            if(mp[str1] == 0) mp[str1] = N++;
            if(mp[str2] == 0) mp[str2] = N++;
            graph.push_back(edge(w, make_pair(mp[str1], mp[str2])));
        }
        kruskal();
    }
    return 0;
}
