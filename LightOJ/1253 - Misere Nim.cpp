//Source Code Written: 1/4/16

#include <bits/stdc++.h>
using namespace std;
int main() {
    ///freopen("in.txt", "r", stdin);
    int t, tc = 0;
    scanf("%d", &t);
    while(t--) {
        int k;
        scanf("%d", &k);
        int xorsum = 0, cnt = 0, carry;
        for(int i=0; i<k; i++) {
            scanf("%d", &carry);
            if(carry == 1) cnt++;
            xorsum ^= carry;
        }
        if(cnt == k && k%2 == 1) printf("Case %d: Bob\n", ++tc);
        else if(cnt == k && k%2 == 0) printf("Case %d: Alice\n", ++tc);
        else if(xorsum == 0) printf("Case %d: Bob\n", ++tc);
        else printf("Case %d: Alice\n", ++tc);
    }
    return 0;
}
