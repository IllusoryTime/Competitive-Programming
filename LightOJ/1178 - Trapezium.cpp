//Source Code Written: 3/20/15

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {
    int test, caseno = 0;
    cin >> test;
    while(test--) {
        double a, b, c, d, ans, df, ang, h;
        cin >> a >> b >> c >> d;
        df = a-c;
        if(df < 0) df *= -1;
        ang = acos(((d*d)+(df*df)-(b*b))/(2*d*df));
        h = d*sin(ang);
        ans = .5*h*(a+c);
        printf("Case %d: %lf\n", ++caseno, ans);
    }
    return 0;
}


