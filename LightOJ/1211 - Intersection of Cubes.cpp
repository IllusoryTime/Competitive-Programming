//Source Code Written: 3/20/15

#include <bits/stdc++.h>
using namespace std;
int main() {
//    freopen("in.txt", "r", stdin);
    int test, caseno = 0;
    cin >> test;
    while(test--) {
        int n, x1, x2, y1, y2, z1, z2, x3 = 0, y3 = 0, z3 = 0, x4 = 1002, y4 = 1002, z4 = 1002;
        cin >> n;
        while(n--) {
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            if(x1 > x3) x3 = x1;
            if(y1 > y3) y3 = y1;
            if(z1 > z3) z3 = z1;
            if(x2 < x4) x4 = x2;
            if(y2 < y4) y4 = y2;
            if(z2 < z4) z4 = z2;
        }
        if(((x4-x3) <= 0) || ((y4-y3) <= 0) || ((z4-z3) <= 0)) printf("Case %d: 0\n", ++caseno);
        else printf("Case %d: %d\n", ++caseno, ((x4-x3)*(y4-y3)*(z4-z3)));
    }
    return 0;
}
