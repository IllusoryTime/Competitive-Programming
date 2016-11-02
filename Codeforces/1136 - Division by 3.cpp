//Source Code Written: 2/23/16

#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);
    int t, tc = 0, a, b;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> a >> b;
        x = b/3;
        x *= 2;
        if(b%3) x += ((b%3) - 1);
        y = (a-1)/3;
        y *= 2;
        if((a-1)%3) y += (((a-1)%3) - 1);
        printf("Case %d: %d\n", ++tc, x - y);
    }
    return 0;
}
