//Source Code Written: 3/24/15

#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)

int main() {
    int t, tc = 0;
    cin >> t;
    while(t--) {
        double R, n;
        cin >> R >> n;
        R *= sin(PI/n);
        R /= (sin(PI/n) + 1);
        printf("Case %d: %.8lf\n", ++tc, R);
    }
    return 0;
}
