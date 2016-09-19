//Source Code Written: 3/28/16

#include <bits/stdc++.h>
using namespace std;

#define MAX 109
vector < int > edges[MAX];
map< pair < int, int > , int > mp;
typedef long long int LL;
int n;
int mx = 0;
int d1[MAX], d2[MAX];

void bfs_1(int st, int flag) {
    int vis[MAX], first = 1, last;
    memset(vis, 0, sizeof(vis));
    vis[st] = 1;
    queue <int> q;
    q.push(st);
    d1[st] = 0;
    while(!q.empty()) {
        int top = q.front(), len = edges[top].size();
        q.pop();
        for(int k=0; k<len; k++) {
            if(first && flag == k) {
                first = 0;
                continue;
            }
            int tmp = edges[top][k];
            if(!vis[tmp]) {
                last = tmp;
                d1[tmp] = d1[top] + mp[make_pair(top, tmp)];
                q.push(tmp);
                vis[tmp] = 1;
            }
        }
    }
    d1[st] = d1[last] + mp[make_pair(last, st)];
}

void bfs_2(int st, int flag) {
    int vis[MAX], first = 1, last;
    memset(vis, 0, sizeof(vis));
    vis[st] = 1;
    queue <int> q;
    q.push(st);
    d2[st] = 0;
    while(!q.empty()) {
        int top = q.front(), len = edges[top].size();
        q.pop();
        for(int k=0; k<len; k++) {
            if(first && flag == k) {
                first = 0;
                continue;
            }
            int tmp = edges[top][k];
            if(!vis[tmp]) {
                last = tmp;
                d2[tmp] = d2[top] + mp[make_pair(top, tmp)];
                q.push(tmp);
                vis[tmp] = 1;
            }
        }
    }
    d2[st] = d2[last] + mp[make_pair(last, st)];
}

int main() {
    ///freopen("in.txt", "r", stdin);
    int T, tc = 0;
    scanf("%d", &T);
    while(T--) {
        mp.clear();
        for(int i=0; i<105; i++) edges[i].clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            int x, y, c;
            scanf("%d %d %d", &x, &y, &c);
            mp[make_pair(x, y)] = 0;
            mp[make_pair(y, x)] = c;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        int cost = 0;
        for(int j=1; j<=n; j++) {
            bfs_1(j, 0);
            bfs_2(j, 1);
            for(int i=1; i<=n; i++) d1[i] = min(d1[i], d2[i]);
            for(int i=1; i<=n; i++) cost = max(cost, d1[i]);
        }
        printf("Case %d: %d\n", ++tc, cost);
    }
    return 0;
}
