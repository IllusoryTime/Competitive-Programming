//Source Code Written: 3/27/16

#include <bits/stdc++.h>
using namespace std;
const int N = 9;
bool p[14];
short v[N][N][N][N][N][N][N], d[N][N][N][N][N][N][N];
struct node {
    int v[N][2];
} A;
node f(node w, int x, int y, int i) {
    int c;
    if(i == 1) {
        for(int i=y; i>x; i--) {
            c = w.v[i][0];
            w.v[i][0] = w.v[i-1][0];
            w.v[i-1][0] = c;
            c = w.v[i][1];
            w.v[i][1] = w.v[i-1][1];
            w.v[i-1][1] = c;
        }
    } else if(i == 2) {
        for(int i=x; i<y; i++) {
            c = w.v[i][0];
            w.v[i][0] = w.v[i+1][0];
            w.v[i+1][0] = c;
            c = w.v[i][1];
            w.v[i][1] = w.v[i+1][1];
            w.v[i+1][1] = c;
        }
    }
    return w;
}
int bfs() {
    queue < node > q;
    memset(v, 0, sizeof v);
    q.push(A);
    v[A.v[1][0]][A.v[2][0]][A.v[3][0]][A.v[4][0]][A.v[5][0]][A.v[6][0]][A.v[7][0]] = 1;
    d[A.v[1][0]][A.v[2][0]][A.v[3][0]][A.v[4][0]][A.v[5][0]][A.v[6][0]][A.v[7][0]] = 0;
    while(!q.empty()) {
        node t = q.front(), k;
        q.pop();
        int w = d[t.v[1][0]][t.v[2][0]][t.v[3][0]][t.v[4][0]][t.v[5][0]][t.v[6][0]][t.v[7][0]];
        if(t.v[1][0] == 1 && t.v[2][0] == 2 && t.v[3][0] == 3 && t.v[4][0] == 4 && t.v[5][0] == 5 && t.v[6][0] == 6 && t.v[7][0] == 7) return w;
        for(int i=1; i<=8; i++) {
            for(int j=i+1; j<=8; j++) {
                if(t.v[i][1] != t.v[j][1] && p[t.v[i][0] + t.v[j][0]]) {
                    if(t.v[i][1] == i && t.v[j][0] == j) continue;
                    k = f(t, i, j, 1);
                    if(!v[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]]) {
                        q.push(k);
                        v[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]] = 1;
                        d[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]] = w + 1;
                    }
                    k = f(t, i+1, j, 1);
                    if(!v[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]]) {
                        q.push(k);
                        v[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]] = 1;
                        d[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]] = w + 1;
                    }
                    k = f(t, i, j, 2);
                    if(!v[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]]) {
                        q.push(k);
                        v[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]] = 1;
                        d[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]] = w + 1;
                    }
                    k = f(t, i, j-1, 2);
                    if(!v[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]]) {
                        q.push(k);
                        v[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]] = 1;
                        d[k.v[1][0]][k.v[2][0]][k.v[3][0]][k.v[4][0]][k.v[5][0]][k.v[6][0]][k.v[7][0]] = w + 1;
                    }
                }
            }
        }
    }
    return -1;
}
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    memset(p, false, sizeof p);
    p[2] = true;
    p[3] = true;
    p[5] = true;
    p[7] = true;
    p[11] = true;
    p[13] = true;
    int t, tc = 0, x;
    scanf("%d", &t);
    while(t--) {
        for(int i=1; i<=8; i++) {
            scanf("%d", &x);
            if(x < 0) A.v[i][1] = 1, x *= -1;
            else A.v[i][1] = 0;
            A.v[i][0] = x;
        }
        printf("Case %d: %d\n", ++tc, bfs());
    }
    return 0;
}
