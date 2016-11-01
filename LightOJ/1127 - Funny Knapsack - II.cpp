//Source Code Written: 11/2/16
//Using Subset Generator
 
#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main() {
    ///freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int n, cnt = 0;
        LL w, c[35], store1[1<<16], store2[1<<16];
        scanf("%d %lld", &n, &w);
        for(int i=0; i<n; i++) scanf("%lld", &c[i]);
        int idx1 = 0, idx2 = 0;
        for(int i=0; i<(1<<(n/2)); i++) {
            LL cost = 0;
            for(int j=0; j<(n/2); j++) {
                if(i&(1<<j)) {
                    cost += c[j];
                }
            }
            store1[idx1++] = cost;
        }
        for(int i=0; i<(1<<(n-(n/2))); i++) {
            LL cost = 0;
            for(int j=0; j<(n-(n/2)); j++) {
                if(i&(1<<j)) {
                    cost += c[(n/2) + j];
                }
            }
            store2[idx2++] = cost;
        }
        sort(store2, store2 + idx2);
        for(int i=0; i<idx1; i++) {
            int tmp = upper_bound(store2, store2 + idx2, w-store1[i]) - store2;
            cnt += tmp;
        }
        printf("Case %d: %d\n", ++tc, cnt);
    }
    return 0;
}
