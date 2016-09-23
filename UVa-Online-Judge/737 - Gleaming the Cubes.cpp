//Source Code Written: 5/24/15

#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);
    int n, R, X, Y, Z, X1, Y1, Z1, X2, Y2, Z2;
    while(scanf("%d", &n) == 1) {
        if(n == 0) break;
        else {
            cin >> X1 >> Y1 >> Z1 >> R;
            X2 = X1 + R;
            Y2 = Y1 + R;
            Z2 = Z1 + R;
            n--;
            while(n--) {
                cin >> X >> Y >> Z >> R;
                if((X >= X2 || Y >= Y2 || Z >= Z2) || ((X + R) < X1 || (Y + R) < Y1 || (Z + R) < Z1)) {
                    X2  = -1000000, Y2 = -1000000, Z2 = -1000000;
                }
                if(X > X1) X1 = X;
                if(Y > Y1) Y1 = Y;
                if(Z > Z1) Z1 = Z;
                if((X + R) < X2) X2 = X + R;
                if((Y + R) < Y2) Y2 = Y + R;
                if((Z + R) < Z2) Z2 = Z + R;
            }
            int ans = (X2-X1) * (Y2-Y1) * (Z2-Z1);
            if(X2 == -1000000 && Y2 == -1000000 && Z2 == -1000000) printf("0\n");
            else printf("%d\n", ans);
        }
    }
    return 0;
}
