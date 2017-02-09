//Source Code Written: 1/18/17

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, tc = 0;
    scanf("%d", &t);
    for(int h=0; h<t; h++) {
        int r, c, rowsum = 0, carry, xorsum = 0;
        scanf("%d %d", &r, &c);
        for(int i=0; i<r; i++) {
            rowsum = 0;
            for(int j=0; j<c; j++) {
                scanf("%d", &carry);
                rowsum += carry;
            }
            xorsum ^= rowsum;
        }
        if(xorsum == 0) printf("Case %d: Bob\n", ++tc);
        else printf("Case %d: Alice\n", ++tc);
    }
    return 0;
}
