//Source Code Written: 6/14/15

#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
double x_1, y_1, z_1, x_2, y_2, z_2, x, y, z;

double dist(double t) {
    double dx, dy, dz;
    dx = x_1 + t*(x_2-x_1);
    dy = y_1 + t*(y_2-y_1);
    dz = z_1 + t*(z_2-z_1);
    return sqrt(sq(x - dx) + sq(y - dy) + sq(z - dz));
}

int main() {
    //freopen("in.txt", "r", stdin);
    int t, tc = 0;
    cin >> t;
    while(t--) {
        int cnt = 90;
        cin >> x_1 >> y_1 >> z_1 >> x_2 >> y_2 >> z_2 >> x >> y >> z;
        double left = 0, right = 1, left_3, right_3;
        while(cnt--) {
            left_3 = (2.0*left + right)/3.0;
            right_3 = (left + 2.0*right)/3.0;
            if(dist(left_3) < dist(right_3)) right = right_3;
            else left = left_3;
        }
        printf("Case %d: %.8lf\n", ++tc, dist((left + right)/2.0));
    }
    return 0;
}
