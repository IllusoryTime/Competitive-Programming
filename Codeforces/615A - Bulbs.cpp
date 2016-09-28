//Problem Solved: 1/8/15
//Last Edit: 9/29/16

#include <bits/stdc++.h>
using namespace std;
int main() {
    ///freopen("in.txt", "r", stdin);
    int n, m, flag[109], x, y;
    memset(flag, 0, sizeof flag);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> x;
        for(int j=0; j<x; j++) {
            cin >> y;
            flag[y]++;
        }
    }
    for(int i=1; i<=m; i++) if(!flag[i]) {
            puts("NO");
            return 0;
        }
    puts("YES");
    return 0;
}
