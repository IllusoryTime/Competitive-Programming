//Source Code Written: 4/3/15

#include <bits/stdc++.h>
using namespace std;
#define mod 100000007

int sum(int a, int b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int t, no = 0;
    int n, k, x;
    int way[10000+5];
    scanf("%d", &t);
    while(t--) {
        memset(way, 0, sizeof(way));
        way[0] = 1;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) {
            cin >> x;
            for(int j = x; j <= k; j++) {
                if(x <= j) {
                    way[j] = sum(way[j], way[j-x]);
                }
            }
        }
        printf("Case %d: %d\n", ++no, way[k]);
    }
    return 0;
}
