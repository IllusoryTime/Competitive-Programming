//Source Code Written: 3/21/15

#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main() {
    int test, caseno = 0;
    double PI = 2*acos(0.0);
    cin >> test;
    while(test--) {
        double r1, r2, h, p;
        double r, ans;
        cin >> r1 >> r2 >> h >> p;
        r = r2 + ((r1-r2)*p)/h*1.0;
        ans = 1/3.0 * PI * p *( r*r + r*r2*1.0 + r2*r2 );
        printf("Case %d: %.9lf\n", ++caseno, ans);
    }
    return 0;
}
