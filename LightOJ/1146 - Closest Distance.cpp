//Source Code Written: 6/14/15

#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
int ax, ay, bx, by, cx, cy, dx, dy;
double dist(double t) {
    double dx1, dx2, dy1, dy2;
    dx1 = ax + t*(bx-ax);
    dy1 = ay + t*(by-ay);
    dx2 = cx + t*(dx-cx);
    dy2 = cy + t*(dy-cy);
    return sqrt(sq(dx1-dx2) + sq(dy1-dy2));
}
int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        int cnt = 90;
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
        double left = 0, right = 1, left_3, right_3;
        while(cnt--) {
            left_3 = (2.0*left + right)/3;
            right_3 = (2.0*right + left)/3;
            if(dist(left_3) < dist(right_3)) {
                right = right_3;
            } else left = left_3;
        }
        printf("Case %d: %.8lf\n", ++tc, dist((left + right)/2.0));
    }
    return 0;
}
