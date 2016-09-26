//Source Code Written: 6/1/15

#include <bits/stdc++.h>
using namespace std;

bool check(double x, double y, int a) {
    if(x*x + y*y > a*a) return 0;
    else if(x*x + (y-a)*(y-a) > a*a) return 0;
    else if((x-a)*(x-a) + y*y > a*a) return 0;
    else if((x-a)*(x-a) + (y-a)*(y-a) > a*a) return 0;
    return 1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    while(1) {
        int n, a, m = 0, t;
        scanf("%d %d", &n, &a);
        t = n;
        if(n == 0 && a == 0) break;
        while(n--) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            if(check(x, y, a)) m++;
        }
        printf("%.5lf\n", (double)m*(a*a)/t);
    }
    return 0;
}
