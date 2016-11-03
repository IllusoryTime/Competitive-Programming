//Source Code Written: 3/28/16

#include <bits/stdc++.h>
using namespace std;
bool flag[1009];
int bfs(int s, int t) {
    if(s == t) return 0;
    int v[1009], d[1009];
    memset(v, 0, sizeof v);
    queue < int > q;
    q.push(s);
    v[s] = 1;
    d[s] = 0;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        if(top % 2 == 0 && top + 2 <= t && top > 2 && !v[top + 2]) {
            q.push(top + 2);
            v[top + 2] = 1;
            d[top + 2] = d[top] + 1;
            if(top + 2 == t) return d[top + 2];
        }
        for(int i=3; i<top; i+=2) {
            if(flag[i] == 1 && top % i == 0 && (top + i <= t) && !v[top + i]) {
                q.push(top + i);
                v[top + i] = 1;
                d[top + i] = d[top] + 1;
                if(top + i == t) return d[top + i];
            }
        }
    }
    return -1;
}
bool is_prime(int p) {
    int sq = sqrt(p);
    for(int i=3; i<=sq + 1; i+=2)
        if(p % i == 0)
            return 0;
    return 1;
}
int main() {
    //freopen("in.txt", "r", stdin);
    for(int i=1; i<=1000; i+=1) flag[i] = 0;
    flag[2] = 1;
    flag[3] = 1;
    for(int i=5; i<=1000; i+=2) {
        if(is_prime(i) == 1) flag[i] = 1;
    }
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int s, t;
        scanf("%d %d", &s, &t);
        printf("Case %d: %d\n", ++tc, bfs(s, t));
    }
    return 0;
}
